#include "../include/minilang.h"

// Vérifier si le résultat est vrai
bool is_true(ExprResult result) {
    if (result.type == VAR_INT || result.type == VAR_BOOL) {
        return result.value.int_val != 0;
    } else if (result.type == VAR_FLOAT) {
        return result.value.float_val != 0.0;
    }
    return false;
}

// Déclaration forward pour call_function
ExprResult call_function(const char *func_name);

// Parser un facteur (nombre, variable, appel de fonction ou expression entre parenthèses)
ExprResult parse_factor() {
    ExprResult result;
    result.type = VAR_INT;
    result.value.int_val = 0;
    
    Token token = tokens[current_token];
    
    // NOT logique
    if (token.type == TOKEN_NOT) {
        current_token++;
        ExprResult expr = parse_factor();
        result.type = VAR_INT;
        result.value.int_val = !is_true(expr);
        return result;
    }
    
    // Parenthèses
    if (token.type == TOKEN_LPAREN) {
        current_token++;
        result = evaluate_logical();
        if (tokens[current_token].type == TOKEN_RPAREN) {
            current_token++;
        }
        return result;
    }
    
    // Nombre
    if (token.type == TOKEN_NUMBER) {
        if (strchr(token.value, '.') != NULL) {
            result.type = VAR_FLOAT;
            result.value.float_val = atof(token.value);
        } else {
            result.type = VAR_INT;
            result.value.int_val = atoi(token.value);
        }
        current_token++;
        return result;
    }
    
    // CORRECTION: Chaîne littérale
    if (token.type == TOKEN_STRING) {
        result.type = VAR_STRING;
        result.value.str_val = token.value;  // Pointer directement vers le token
        current_token++;
        return result;
    }
    
    // Bool
    if (token.type == TOKEN_TRUE) {
        result.type = VAR_BOOL;
        result.value.int_val = 1;
        current_token++;
        return result;
    }
    
    if (token.type == TOKEN_FALSE) {
        result.type = VAR_BOOL;
        result.value.int_val = 0;
        current_token++;
        return result;
    }
    
    // Input - Lecture depuis stdin
    if (token.type == TOKEN_INPUT) {
        current_token++;
        
        // Vérifier (
        if (tokens[current_token].type != TOKEN_LPAREN) {
            print_error("'(' attendu après input", token.line);
            return result;
        }
        current_token++;
        
        // Prompt optionnel
        if (tokens[current_token].type == TOKEN_STRING) {
            printf("%s", tokens[current_token].value);
            fflush(stdout);
            current_token++;
        }
        
        // Vérifier )
        if (tokens[current_token].type != TOKEN_RPAREN) {
            print_error("')' attendu", token.line);
            return result;
        }
        current_token++;
        
        // Lire l'entrée
        char buffer[1024];
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }
            result.type = VAR_STRING;
            result.value.str_val = strdup(buffer);
        } else {
            result.type = VAR_STRING;
            result.value.str_val = strdup("");
        }
        
        return result;
    }
    
    // Variable ou appel de fonction
    if (token.type == TOKEN_IDENTIFIER) {
        char *name = token.value;
        current_token++;
        
        // Appel de fonction
        if (tokens[current_token].type == TOKEN_LPAREN) {
            current_token--; // Revenir pour l'appel
            return call_function(name);
        }
        
        // Variable simple ou tableau
        Variable *var = find_variable(name);
        
        if (var != NULL) {
            // Accès tableau
            if (tokens[current_token].type == TOKEN_LBRACKET) {
                current_token++;
                ExprResult index = evaluate_expression();
                if (tokens[current_token].type == TOKEN_RBRACKET) {
                    current_token++;
                }
                
                int idx = index.value.int_val;
                
                // Validation stricte des bornes
                if (var->type == VAR_ARRAY) {
                    if (idx < 0 || idx >= var->value.array_val.size) {
                        char error_msg[256];
                        snprintf(error_msg, sizeof(error_msg), 
                                "Index tableau hors limites: %d (taille: %d)", 
                                idx, var->value.array_val.size);
                        print_error(error_msg, tokens[current_token].line);
                        result.type = VAR_INT;
                        result.value.int_val = 0;
                        return result;
                    }
                    
                    result.type = var->value.array_val.elem_type;
                    if (var->value.array_val.elem_type == VAR_INT) {
                        result.value.int_val = var->value.array_val.int_array[idx];
                    } else if (var->value.array_val.elem_type == VAR_FLOAT) {
                        result.value.float_val = var->value.array_val.float_array[idx];
                    }
                }
                return result;
            }
            
            // Variable simple
            result.type = var->type;
            if (var->type == VAR_INT) {
                result.value.int_val = var->value.int_val;
            } else if (var->type == VAR_FLOAT) {
                result.value.float_val = var->value.float_val;
            } else if (var->type == VAR_STRING) {
                result.value.str_val = var->value.str_val;
            } else if (var->type == VAR_BOOL) {
                result.value.int_val = var->value.int_val;
            }
        }
        return result;
    }
    
    return result;
}

// Parser un terme (multiplication, division, modulo)
ExprResult parse_term() {
    ExprResult left = parse_factor();
    
    while (current_token < token_count) {
        Token token = tokens[current_token];
        
        if (token.type == TOKEN_MULT || token.type == TOKEN_DIV || token.type == TOKEN_MOD) {
            TokenType op = token.type;
            current_token++;
            ExprResult right = parse_factor();
            
            // Promotion de type
            if (left.type == VAR_FLOAT || right.type == VAR_FLOAT) {
                float left_val = (left.type == VAR_FLOAT) ? left.value.float_val : (float)left.value.int_val;
                float right_val = (right.type == VAR_FLOAT) ? right.value.float_val : (float)right.value.int_val;
                
                left.type = VAR_FLOAT;
                if (op == TOKEN_MULT) {
                    left.value.float_val = left_val * right_val;
                } else if (op == TOKEN_DIV) {
                    if (right_val != 0) {
                        left.value.float_val = left_val / right_val;
                    } else {
                        print_error("Division par zéro", tokens[current_token-1].line);
                    }
                }
            } else {
                if (op == TOKEN_MULT) {
                    left.value.int_val = left.value.int_val * right.value.int_val;
                } else if (op == TOKEN_DIV) {
                    if (right.value.int_val != 0) {
                        left.value.int_val = left.value.int_val / right.value.int_val;
                    } else {
                        print_error("Division par zéro", tokens[current_token-1].line);
                    }
                } else if (op == TOKEN_MOD) {
                    if (right.value.int_val != 0) {
                        left.value.int_val = left.value.int_val % right.value.int_val;
                    } else {
                        print_error("Modulo par zéro", tokens[current_token-1].line);
                    }
                }
            }
        } else {
            break;
        }
    }
    
    return left;
}

// Évaluer une expression arithmétique (addition, soustraction, concaténation)
ExprResult evaluate_expression() {
    ExprResult left = parse_term();
    
    while (current_token < token_count) {
        Token token = tokens[current_token];
        
        if (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS) {
            TokenType op = token.type;
            current_token++;
            ExprResult right = parse_term();
            
            // Concaténation de chaînes avec +
            if (op == TOKEN_PLUS && (left.type == VAR_STRING || right.type == VAR_STRING)) {
                char *left_str = value_to_string(left);
                char *right_str = value_to_string(right);
                char *result_str = concat_strings(left_str, right_str);
                
                // Libérer les chaînes temporaires
                free(left_str);
                free(right_str);
                
                left.type = VAR_STRING;
                left.value.str_val = result_str;
            }
            // Arithmétique normale
            else if (left.type == VAR_FLOAT || right.type == VAR_FLOAT) {
                float left_val = (left.type == VAR_FLOAT) ? left.value.float_val : (float)left.value.int_val;
                float right_val = (right.type == VAR_FLOAT) ? right.value.float_val : (float)right.value.int_val;
                
                left.type = VAR_FLOAT;
                if (op == TOKEN_PLUS) {
                    left.value.float_val = left_val + right_val;
                } else {
                    left.value.float_val = left_val - right_val;
                }
            } else {
                if (op == TOKEN_PLUS) {
                    left.value.int_val = left.value.int_val + right.value.int_val;
                } else {
                    left.value.int_val = left.value.int_val - right.value.int_val;
                }
            }
        } else {
            break;
        }
    }
    
    return left;
}

// Évaluer une comparaison
ExprResult evaluate_comparison() {
    ExprResult left = evaluate_expression();
    
    Token token = tokens[current_token];
    if (token.type == TOKEN_EQ || token.type == TOKEN_NEQ ||
        token.type == TOKEN_LT || token.type == TOKEN_GT ||
        token.type == TOKEN_LTE || token.type == TOKEN_GTE) {
        
        TokenType op = token.type;
        current_token++;
        ExprResult right = evaluate_expression();
        
        ExprResult result;
        result.type = VAR_INT;
        
        // Comparaison de chaînes (seulement == et !=)
        if (left.type == VAR_STRING && right.type == VAR_STRING) {
            if (op == TOKEN_EQ) {
                result.value.int_val = (strcmp(left.value.str_val, right.value.str_val) == 0);
            } else if (op == TOKEN_NEQ) {
                result.value.int_val = (strcmp(left.value.str_val, right.value.str_val) != 0);
            } else {
                print_error("Opérateur non supporté pour les chaînes", token.line);
                result.value.int_val = 0;
            }
        }
        // Comparaison numérique
        else {
            float left_val = (left.type == VAR_FLOAT) ? left.value.float_val : (float)left.value.int_val;
            float right_val = (right.type == VAR_FLOAT) ? right.value.float_val : (float)right.value.int_val;
            
            switch (op) {
                case TOKEN_EQ:  result.value.int_val = (left_val == right_val); break;
                case TOKEN_NEQ: result.value.int_val = (left_val != right_val); break;
                case TOKEN_LT:  result.value.int_val = (left_val < right_val); break;
                case TOKEN_GT:  result.value.int_val = (left_val > right_val); break;
                case TOKEN_LTE: result.value.int_val = (left_val <= right_val); break;
                case TOKEN_GTE: result.value.int_val = (left_val >= right_val); break;
                default: result.value.int_val = 0;
            }
        }
        
        return result;
    }
    
    return left;
}

// Évaluer une expression logique
ExprResult evaluate_logical() {
    ExprResult left = evaluate_comparison();
    
    while (current_token < token_count) {
        Token token = tokens[current_token];
        
        if (token.type == TOKEN_AND || token.type == TOKEN_OR) {
            TokenType op = token.type;
            current_token++;
            ExprResult right = evaluate_comparison();
            
            ExprResult result;
            result.type = VAR_INT;
            
            if (op == TOKEN_AND) {
                result.value.int_val = is_true(left) && is_true(right);
            } else { // TOKEN_OR
                result.value.int_val = is_true(left) || is_true(right);
            }
            
            left = result;
        } else {
            break;
        }
    }
    
    return left;
}
