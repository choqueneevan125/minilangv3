#include "minilang.h"

// Forward declarations
void parse_statement();
void parse_block();

// ============================================================================
// UTILITAIRES POUR CHAÎNES
// ============================================================================

// Convertir une valeur en chaîne
char *value_to_string(ExprResult result) {
    static char buffer[256];
    
    switch (result.type) {
        case VAR_INT:
        case VAR_BOOL:
            snprintf(buffer, sizeof(buffer), "%d", result.value.int_val);
            return strdup(buffer);
        case VAR_FLOAT:
            snprintf(buffer, sizeof(buffer), "%g", result.value.float_val);
            return strdup(buffer);
        case VAR_STRING:
            return result.value.str_val ? strdup(result.value.str_val) : strdup("");
        default:
            return strdup("");
    }
}

// Concaténer deux chaînes
char *concat_strings(const char *s1, const char *s2) {
    if (s1 == NULL) s1 = "";
    if (s2 == NULL) s2 = "";
    
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    
    strcpy(result, s1);
    strcat(result, s2);
    
    return result;
}

// Lire une ligne depuis stdin
char *read_input() {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Supprimer le \n final
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        return strdup(buffer);
    }
    return strdup("");
}

// ============================================================================
// APPEL DE FONCTION
// ============================================================================

ExprResult call_function(const char *func_name) {
    ExprResult result;
    result.type = VAR_VOID;
    result.value.int_val = 0;
    
    Function *func = find_function(func_name);
    if (func == NULL) {
        print_error("Fonction non définie", tokens[current_token].line);
        return result;
    }
    
    current_token++; // Passer le nom de la fonction
    
    if (tokens[current_token].type != TOKEN_LPAREN) {
        print_error("'(' attendu après le nom de fonction", tokens[current_token].line);
        return result;
    }
    current_token++;
    
    // Créer un nouveau scope pour la fonction
    push_scope();
    
    // Évaluer et assigner les arguments
    Param *param = func->params;
    int arg_count = 0;
    
    while (tokens[current_token].type != TOKEN_RPAREN && param != NULL) {
        ExprResult arg_value = evaluate_logical();
        
        // Créer la variable du paramètre dans le scope de la fonction
        add_variable(param->name, param->type);
        Variable *var = find_variable(param->name);
        
        if (var != NULL) {
            if (param->type == VAR_INT) {
                var->value.int_val = (arg_value.type == VAR_FLOAT) ? 
                    (int)arg_value.value.float_val : arg_value.value.int_val;
            } else if (param->type == VAR_FLOAT) {
                var->value.float_val = (arg_value.type == VAR_INT) ? 
                    (float)arg_value.value.int_val : arg_value.value.float_val;
            } else if (param->type == VAR_STRING) {
                // CORRECTION: Copier la chaîne pour les paramètres string
                if (arg_value.type == VAR_STRING && arg_value.value.str_val != NULL) {
                    var->value.str_val = strdup(arg_value.value.str_val);
                } else {
                    var->value.str_val = NULL;
                }
            } else if (param->type == VAR_BOOL) {
                var->value.int_val = is_true(arg_value) ? 1 : 0;
            }
        }
        
        arg_count++;
        param = param->next;
        
        if (tokens[current_token].type == TOKEN_COMMA) {
            current_token++;
        }
    }
    
    if (tokens[current_token].type == TOKEN_RPAREN) {
        current_token++;
    }
    
    // Vérifier le nombre d'arguments
    if (arg_count != func->param_count) {
        print_error("Nombre d'arguments incorrect", tokens[current_token-1].line);
        pop_scope();
        return result;
    }
    
    // Sauvegarder la position actuelle
    int saved_position = current_token;
    
    // Exécuter le corps de la fonction
    current_token = func->body_start;
    return_value.has_return = false;
    
    parse_block();
    
    // Récupérer la valeur de retour
    if (return_value.has_return) {
        result = return_value.value;
        return_value.has_return = false;
    } else {
        result.type = func->return_type;
    }
    
    // Restaurer la position
    current_token = saved_position;
    
    // Nettoyer le scope
    pop_scope();
    
    return result;
}

// ============================================================================
// DÉCLARATION DE FONCTION
// ============================================================================

void parse_function_declaration() {
    current_token++; // Passer 'func'
    
    // Type de retour
    VarType return_type = VAR_VOID;
    if (tokens[current_token].type == TOKEN_VOID) {
        return_type = VAR_VOID;
        current_token++;
    } else if (tokens[current_token].type == TOKEN_INT) {
        return_type = VAR_INT;
        current_token++;
    } else if (tokens[current_token].type == TOKEN_FLOAT) {
        return_type = VAR_FLOAT;
        current_token++;
    } else if (tokens[current_token].type == TOKEN_STR) {
        return_type = VAR_STRING;
        current_token++;
    } else if (tokens[current_token].type == TOKEN_BOOL) {
        return_type = VAR_BOOL;
        current_token++;
    }
    
    // Nom de la fonction
    if (tokens[current_token].type != TOKEN_IDENTIFIER) {
        print_error("Nom de fonction attendu", tokens[current_token].line);
        return;
    }
    
    char *func_name = strdup(tokens[current_token].value);
    current_token++;
    
    // Créer la fonction
    Function *func = malloc(sizeof(Function));
    func->name = func_name;
    func->return_type = return_type;
    func->params = NULL;
    func->param_count = 0;
    
    // Paramètres
    if (tokens[current_token].type != TOKEN_LPAREN) {
        print_error("'(' attendu après le nom de fonction", tokens[current_token].line);
        free(func_name);
        free(func);
        return;
    }
    current_token++;
    
    Param *last_param = NULL;
    
    while (tokens[current_token].type != TOKEN_RPAREN) {
        // Type du paramètre
        VarType param_type = VAR_INT;
        if (tokens[current_token].type == TOKEN_INT) {
            param_type = VAR_INT;
        } else if (tokens[current_token].type == TOKEN_FLOAT) {
            param_type = VAR_FLOAT;
        } else if (tokens[current_token].type == TOKEN_STR) {
            param_type = VAR_STRING;
        } else if (tokens[current_token].type == TOKEN_BOOL) {
            param_type = VAR_BOOL;
        } else {
            print_error("Type de paramètre attendu", tokens[current_token].line);
            break;
        }
        current_token++;
        
        // Nom du paramètre
        if (tokens[current_token].type != TOKEN_IDENTIFIER) {
            print_error("Nom de paramètre attendu", tokens[current_token].line);
            break;
        }
        
        Param *param = malloc(sizeof(Param));
        param->name = strdup(tokens[current_token].value);
        param->type = param_type;
        param->next = NULL;
        
        if (last_param == NULL) {
            func->params = param;
        } else {
            last_param->next = param;
        }
        last_param = param;
        func->param_count++;
        
        current_token++;
        
        if (tokens[current_token].type == TOKEN_COMMA) {
            current_token++;
        }
    }
    
    if (tokens[current_token].type == TOKEN_RPAREN) {
        current_token++;
    }
    
    // Corps de la fonction
    if (tokens[current_token].type != TOKEN_LBRACE) {
        print_error("'{' attendu pour le corps de fonction", tokens[current_token].line);
        free(func_name);
        free(func);
        return;
    }
    
    func->body_start = current_token;
    
    // Sauter le corps pour l'enregistrer
    int brace_count = 1;
    current_token++;
    while (current_token < token_count && brace_count > 0) {
        if (tokens[current_token].type == TOKEN_LBRACE) brace_count++;
        if (tokens[current_token].type == TOKEN_RBRACE) brace_count--;
        current_token++;
    }
    
    func->body_end = current_token;
    
    // Ajouter la fonction
    add_function(func);
}

// ============================================================================
// PARSER DE BLOCS
// ============================================================================

void parse_block() {
    if (tokens[current_token].type == TOKEN_LBRACE) {
        current_token++;
    }
    
    push_scope();
    
    while (current_token < token_count && 
           tokens[current_token].type != TOKEN_RBRACE && 
           tokens[current_token].type != TOKEN_EOF &&
           !return_value.has_return &&
           !control_flow.break_flag &&
           !control_flow.continue_flag) {
        parse_statement();
    }
    
    pop_scope();
    
    if (tokens[current_token].type == TOKEN_RBRACE) {
        current_token++;
    }
}

// ============================================================================
// PARSER D'INSTRUCTIONS
// ============================================================================

void parse_statement() {
    Token token = tokens[current_token];
    
    // Return
    if (token.type == TOKEN_RETURN) {
        current_token++;
        
        if (tokens[current_token].type != TOKEN_SEMICOLON) {
            return_value.value = evaluate_logical();
        } else {
            return_value.value.type = VAR_VOID;
            return_value.value.value.int_val = 0;
        }
        
        return_value.has_return = true;
        
        if (tokens[current_token].type == TOKEN_SEMICOLON) {
            current_token++;
        }
        return;
    }
    
    // Break
    if (token.type == TOKEN_BREAK) {
        control_flow.break_flag = true;
        current_token++;
        if (tokens[current_token].type == TOKEN_SEMICOLON) {
            current_token++;
        }
        return;
    }
    
    // Continue
    if (token.type == TOKEN_CONTINUE) {
        control_flow.continue_flag = true;
        current_token++;
        if (tokens[current_token].type == TOKEN_SEMICOLON) {
            current_token++;
        }
        return;
    }
    
    // Déclaration de fonction
    if (token.type == TOKEN_FUNC) {
        parse_function_declaration();
        return;
    }
    
    // Déclaration de variable
    if (token.type == TOKEN_INT || token.type == TOKEN_FLOAT || token.type == TOKEN_STR || token.type == TOKEN_BOOL) {
        VarType type = (token.type == TOKEN_INT) ? VAR_INT : 
                      (token.type == TOKEN_FLOAT) ? VAR_FLOAT :
                      (token.type == TOKEN_BOOL) ? VAR_BOOL : VAR_STRING;
        current_token++;
        
        if (tokens[current_token].type != TOKEN_IDENTIFIER) {
            print_error("Nom de variable attendu", token.line);
            return;
        }
        
        char *var_name = tokens[current_token].value;
        current_token++;
        
        // Déclaration de tableau
        if (tokens[current_token].type == TOKEN_LBRACKET) {
            current_token++;
            ExprResult size = evaluate_expression();
            if (tokens[current_token].type == TOKEN_RBRACKET) {
                current_token++;
            }
            
            Variable *var = malloc(sizeof(Variable));
            var->name = strdup(var_name);
            var->type = VAR_ARRAY;
            var->value.array_val.size = size.value.int_val;
            var->value.array_val.elem_type = type;
            
            if (type == VAR_INT) {
                var->value.array_val.int_array = calloc(size.value.int_val, sizeof(int));
            } else if (type == VAR_FLOAT) {
                var->value.array_val.float_array = calloc(size.value.int_val, sizeof(float));
            }
            
            var->next = current_scope->vars;
            current_scope->vars = var;
        } else {
            add_variable(var_name, type);
            
            if (tokens[current_token].type == TOKEN_ASSIGN) {
                current_token++;
                Variable *var = find_variable(var_name);
                
                if (tokens[current_token].type == TOKEN_STRING) {
                    if (type == VAR_STRING) {
                        var->value.str_val = strdup(tokens[current_token].value);
                    }
                    current_token++;
                } else {
                    ExprResult result = evaluate_logical();
                    
                    if (type == VAR_INT) {
                        if (result.type == VAR_FLOAT) {
                            var->value.int_val = (int)result.value.float_val;
                        } else if (result.type == VAR_STRING) {
                            var->value.int_val = atoi(result.value.str_val);
                        } else {
                            var->value.int_val = result.value.int_val;
                        }
                    } else if (type == VAR_FLOAT) {
                        if (result.type == VAR_INT) {
                            var->value.float_val = (float)result.value.int_val;
                        } else if (result.type == VAR_STRING) {
                            var->value.float_val = atof(result.value.str_val);
                        } else {
                            var->value.float_val = result.value.float_val;
                        }
                    } else if (type == VAR_BOOL) {
                        if (result.type == VAR_STRING) {
                            var->value.int_val = (strcmp(result.value.str_val, "true") == 0 || 
                                                 strcmp(result.value.str_val, "1") == 0) ? 1 : 0;
                        } else {
                            var->value.int_val = is_true(result) ? 1 : 0;
                        }
                    } else if (type == VAR_STRING) {
                        if (result.type == VAR_STRING) {
                            var->value.str_val = strdup(result.value.str_val);
                        }
                    }
                }
            }
        }
        
        if (tokens[current_token].type == TOKEN_SEMICOLON) {
            current_token++;
        }
    }
    // Assignation ou appel de fonction
    else if (token.type == TOKEN_IDENTIFIER) {
        char *name = token.value;
        current_token++;
        
        // Appel de fonction (sans récupération de valeur)
        if (tokens[current_token].type == TOKEN_LPAREN) {
            current_token--;
            call_function(name);
            if (tokens[current_token].type == TOKEN_SEMICOLON) {
                current_token++;
            }
            return;
        }
        
        // Assignation tableau
        if (tokens[current_token].type == TOKEN_LBRACKET) {
            current_token++;
            ExprResult index = evaluate_expression();
            if (tokens[current_token].type == TOKEN_RBRACKET) {
                current_token++;
            }
            
            if (tokens[current_token].type == TOKEN_ASSIGN) {
                current_token++;
                ExprResult value = evaluate_logical();
                
                Variable *var = find_variable(name);
                if (var != NULL && var->type == VAR_ARRAY) {
                    int idx = index.value.int_val;
                    if (idx >= 0 && idx < var->value.array_val.size) {
                        if (var->value.array_val.elem_type == VAR_INT) {
                            var->value.array_val.int_array[idx] = value.value.int_val;
                        } else if (var->value.array_val.elem_type == VAR_FLOAT) {
                            var->value.array_val.float_array[idx] = 
                                (value.type == VAR_INT) ? (float)value.value.int_val : value.value.float_val;
                        }
                    }
                }
            }
        }
        // Assignation normale
        else if (tokens[current_token].type == TOKEN_ASSIGN) {
            current_token++;
            Variable *var = find_variable(name);
            
            if (var != NULL) {
                // Gestion de input()
                if (tokens[current_token].type == TOKEN_INPUT) {
                    current_token++;
                    
                    if (tokens[current_token].type != TOKEN_LPAREN) {
                        print_error("'(' attendu après input", token.line);
                        return;
                    }
                    current_token++;
                    
                    // Prompt optionnel
                    if (tokens[current_token].type == TOKEN_STRING) {
                        printf("%s", tokens[current_token].value);
                        fflush(stdout);
                        current_token++;
                    }
                    
                    if (tokens[current_token].type != TOKEN_RPAREN) {
                        print_error("')' attendu", token.line);
                        return;
                    }
                    current_token++;
                    
                    // Lire l'entrée
                    char *input_str = read_input();
                    
                    // Convertir selon le type
                    if (var->type == VAR_STRING) {
                        if (var->value.str_val != NULL) {
                            free(var->value.str_val);
                        }
                        var->value.str_val = input_str;
                    } else if (var->type == VAR_INT) {
                        var->value.int_val = atoi(input_str);
                        free(input_str);
                    } else if (var->type == VAR_FLOAT) {
                        var->value.float_val = atof(input_str);
                        free(input_str);
                    } else if (var->type == VAR_BOOL) {
                        var->value.int_val = (strcmp(input_str, "true") == 0 || 
                                             strcmp(input_str, "1") == 0) ? 1 : 0;
                        free(input_str);
                    }
                }
                else if (tokens[current_token].type == TOKEN_STRING) {
                    if (var->type == VAR_STRING) {
                        if (var->value.str_val != NULL) {
                            free(var->value.str_val);
                        }
                        var->value.str_val = strdup(tokens[current_token].value);
                    }
                    current_token++;
                } else {
                    ExprResult result = evaluate_logical();
                    
                    if (var->type == VAR_INT) {
                        var->value.int_val = (result.type == VAR_FLOAT) ? 
                            (int)result.value.float_val : result.value.int_val;
                    } else if (var->type == VAR_FLOAT) {
                        var->value.float_val = (result.type == VAR_INT) ? 
                            (float)result.value.int_val : result.value.float_val;
                    }
                }
            }
        }
        
        if (tokens[current_token].type == TOKEN_SEMICOLON) {
            current_token++;
        }
    }
    // Print
    else if (token.type == TOKEN_PRINT) {
        current_token++;
        
        if (tokens[current_token].type != TOKEN_LPAREN) {
            print_error("'(' attendu après print", token.line);
            return;
        }
        current_token++;
        
        if (tokens[current_token].type == TOKEN_STRING) {
            printf("%s\n", tokens[current_token].value);
            current_token++;
        } else {
            // Utiliser evaluate_logical qui gère les appels de fonction
            ExprResult result = evaluate_logical();
            
            if (result.type == VAR_INT) {
                printf("%d\n", result.value.int_val);
            } else if (result.type == VAR_FLOAT) {
                printf("%g\n", result.value.float_val);
            } else if (result.type == VAR_STRING) {
                printf("%s\n", result.value.str_val);
            } else if (result.type == VAR_BOOL) {
                printf("%s\n", result.value.int_val ? "true" : "false");
            }
        }
        
        if (tokens[current_token].type != TOKEN_RPAREN) {
            print_error("')' attendu", token.line);
            return;
        }
        current_token++;
        
        if (tokens[current_token].type == TOKEN_SEMICOLON) {
            current_token++;
        }
    }
    // If
    else if (token.type == TOKEN_IF) {
        current_token++;
        
        if (tokens[current_token].type != TOKEN_LPAREN) {
            print_error("'(' attendu après if", token.line);
            return;
        }
        current_token++;
        
        ExprResult condition = evaluate_logical();
        
        if (tokens[current_token].type != TOKEN_RPAREN) {
            print_error("')' attendu", token.line);
            return;
        }
        current_token++;
        
        int then_pos = current_token;
        
        // Sauter le bloc then
        int brace_count = 0;
        int else_pos = -1;
        int temp_token = current_token;
        
        if (tokens[temp_token].type == TOKEN_LBRACE) {
            brace_count = 1;
            temp_token++;
            while (temp_token < token_count && brace_count > 0) {
                if (tokens[temp_token].type == TOKEN_LBRACE) brace_count++;
                if (tokens[temp_token].type == TOKEN_RBRACE) brace_count--;
                temp_token++;
            }
        } else {
            while (temp_token < token_count && tokens[temp_token].type != TOKEN_SEMICOLON) {
                temp_token++;
            }
            temp_token++;
        }
        
        if (tokens[temp_token].type == TOKEN_ELSE) {
            else_pos = temp_token + 1;
        }
        
        if (is_true(condition)) {
            current_token = then_pos;
            if (tokens[current_token].type == TOKEN_LBRACE) {
                parse_block();
            } else {
                parse_statement();
            }
            
            if (else_pos != -1) {
                current_token = else_pos;
                if (tokens[current_token].type == TOKEN_LBRACE) {
                    int brace = 1;
                    current_token++;
                    while (current_token < token_count && brace > 0) {
                        if (tokens[current_token].type == TOKEN_LBRACE) brace++;
                        if (tokens[current_token].type == TOKEN_RBRACE) brace--;
                        current_token++;
                    }
                } else {
                    while (current_token < token_count && tokens[current_token].type != TOKEN_SEMICOLON) {
                        current_token++;
                    }
                    if (tokens[current_token].type == TOKEN_SEMICOLON) {
                        current_token++;
                    }
                }
            }
        } else {
            current_token = temp_token;
            
            if (else_pos != -1 && tokens[else_pos - 1].type == TOKEN_ELSE) {
                current_token = else_pos;
                if (tokens[current_token].type == TOKEN_LBRACE) {
                    parse_block();
                } else {
                    parse_statement();
                }
            }
        }
    }
    // While
    else if (token.type == TOKEN_WHILE) {
        current_token++;
        
        if (tokens[current_token].type != TOKEN_LPAREN) {
            print_error("'(' attendu après while", token.line);
            return;
        }
        current_token++;
        
        int condition_start = current_token;
        ExprResult condition = evaluate_logical();
        int condition_end = current_token;
        
        if (tokens[current_token].type != TOKEN_RPAREN) {
            print_error("')' attendu", token.line);
            return;
        }
        current_token++;
        
        int body_start = current_token;
        
        while (is_true(condition) && !return_value.has_return) {
            current_token = body_start;
            
            // Réinitialiser continue_flag
            control_flow.continue_flag = false;
            
            if (tokens[current_token].type == TOKEN_LBRACE) {
                parse_block();
            } else {
                parse_statement();
            }
            
            // Si break, sortir
            if (control_flow.break_flag) {
                control_flow.break_flag = false;
                break;
            }
            
            current_token = condition_start;
            condition = evaluate_logical();
            current_token = condition_end;
            
            if (tokens[current_token].type == TOKEN_RPAREN) {
                current_token++;
            }
        }
        
        current_token = body_start;
        if (tokens[current_token].type == TOKEN_LBRACE) {
            int brace_count = 1;
            current_token++;
            while (current_token < token_count && brace_count > 0) {
                if (tokens[current_token].type == TOKEN_LBRACE) brace_count++;
                if (tokens[current_token].type == TOKEN_RBRACE) brace_count--;
                current_token++;
            }
        } else {
            while (current_token < token_count && tokens[current_token].type != TOKEN_SEMICOLON) {
                current_token++;
            }
            if (tokens[current_token].type == TOKEN_SEMICOLON) {
                current_token++;
            }
        }
    }
    // For
    else if (token.type == TOKEN_FOR) {
        current_token++;
        
        if (tokens[current_token].type != TOKEN_LPAREN) {
            print_error("'(' attendu après for", token.line);
            return;
        }
        current_token++;
        
        push_scope();
        
        parse_statement();
        
        int condition_start = current_token;
        ExprResult condition = evaluate_logical();
        int condition_end = current_token;
        
        if (tokens[current_token].type != TOKEN_SEMICOLON) {
            print_error("';' attendu", token.line);
            pop_scope();
            return;
        }
        current_token++;
        
        int increment_start = current_token;
        
        while (current_token < token_count && tokens[current_token].type != TOKEN_RPAREN) {
            current_token++;
        }
        int increment_end = current_token;
        
        if (tokens[current_token].type != TOKEN_RPAREN) {
            print_error("')' attendu", token.line);
            pop_scope();
            return;
        }
        current_token++;
        
        int body_start = current_token;
        
        while (is_true(condition) && !return_value.has_return) {
            current_token = body_start;
            
            control_flow.continue_flag = false;
            
            if (tokens[current_token].type == TOKEN_LBRACE) {
                parse_block();
            } else {
                parse_statement();
            }
            
            if (control_flow.break_flag) {
                control_flow.break_flag = false;
                break;
            }
            
            // Exécuter l'incrément seulement si pas de continue
            if (!control_flow.continue_flag) {
                current_token = increment_start;
                while (current_token < increment_end && tokens[current_token].type != TOKEN_RPAREN) {
                    if (tokens[current_token].type == TOKEN_IDENTIFIER) {
                        parse_statement();
                        break;
                    }
                    current_token++;
                }
            } else {
                // Même avec continue, exécuter l'incrément
                current_token = increment_start;
                while (current_token < increment_end && tokens[current_token].type != TOKEN_RPAREN) {
                    if (tokens[current_token].type == TOKEN_IDENTIFIER) {
                        parse_statement();
                        break;
                    }
                    current_token++;
                }
            }
            
            current_token = condition_start;
            condition = evaluate_logical();
        }
        
        pop_scope();
        
        current_token = body_start;
        if (tokens[current_token].type == TOKEN_LBRACE) {
            int brace_count = 1;
            current_token++;
            while (current_token < token_count && brace_count > 0) {
                if (tokens[current_token].type == TOKEN_LBRACE) brace_count++;
                if (tokens[current_token].type == TOKEN_RBRACE) brace_count--;
                current_token++;
            }
        } else {
            while (current_token < token_count && tokens[current_token].type != TOKEN_SEMICOLON) {
                current_token++;
            }
            if (tokens[current_token].type == TOKEN_SEMICOLON) {
                current_token++;
            }
        }
    }
    else {
        current_token++;
    }
}

// ============================================================================
// PARSER PRINCIPAL
// ============================================================================

void parser() {
    push_scope();
    
    while (current_token < token_count && tokens[current_token].type != TOKEN_EOF) {
        parse_statement();
    }
    
    pop_scope();
}
