#include "../include/minilang.h"

// ============================================================================
// GESTION DES VARIABLES
// ============================================================================

void add_variable(const char *name, VarType type) {
    // Vérifier redéclaration dans le scope courant uniquement
    if (current_scope != NULL) {
        Variable *existing = current_scope->vars;
        while (existing != NULL) {
            if (strcmp(existing->name, name) == 0) {
                char error_msg[256];
                snprintf(error_msg, sizeof(error_msg), "Variable '%s' deja declaree", name);
                print_error(error_msg, 0);
                return;
            }
            existing = existing->next;
        }
    } else {
        // Vérifier dans les variables globales
        Variable *existing = variables;
        while (existing != NULL) {
            if (strcmp(existing->name, name) == 0) {
                char error_msg[256];
                snprintf(error_msg, sizeof(error_msg), "Variable '%s' deja declaree", name);
                print_error(error_msg, 0);
                return;
            }
            existing = existing->next;
        }
    }
    
    Variable *var = malloc(sizeof(Variable));
    var->name = strdup(name);
    var->type = type;
    var->value.int_val = 0;
    var->value.float_val = 0.0;
    var->value.str_val = NULL;
    
    if (current_scope != NULL) {
        var->next = current_scope->vars;
        current_scope->vars = var;
    } else {
        var->next = variables;
        variables = var;
    }
}

Variable *find_variable(const char *name) {
    // Chercher dans le scope courant
    if (current_scope != NULL) {
        VarScope *scope = current_scope;
        while (scope != NULL) {
            Variable *var = scope->vars;
            while (var != NULL) {
                if (strcmp(var->name, name) == 0) {
                    return var;
                }
                var = var->next;
            }
            scope = scope->parent;
        }
    }
    
    // Chercher dans les variables globales
    Variable *var = variables;
    while (var != NULL) {
        if (strcmp(var->name, name) == 0) {
            return var;
        }
        var = var->next;
    }
    
    return NULL;
}

void free_variables() {
    Variable *var = variables;
    while (var != NULL) {
        Variable *next = var->next;
        free(var->name);
        if (var->type == VAR_STRING && var->value.str_val != NULL) {
            free(var->value.str_val);
        }
        free(var);
        var = next;
    }
    variables = NULL;
}

// ============================================================================
// GESTION DES FONCTIONS
// ============================================================================

void add_function(Function *func) {
    func->next = functions;
    functions = func;
}

Function *find_function(const char *name) {
    Function *func = functions;
    while (func != NULL) {
        if (strcmp(func->name, name) == 0) {
            return func;
        }
        func = func->next;
    }
    return NULL;
}

void free_functions() {
    Function *func = functions;
    while (func != NULL) {
        Function *next = func->next;
        free(func->name);
        
        Param *param = func->params;
        while (param != NULL) {
            Param *next_param = param->next;
            free(param->name);
            free(param);
            param = next_param;
        }
        
        free(func);
        func = next;
    }
    functions = NULL;
}

// ============================================================================
// GESTION DES SCOPES
// ============================================================================

void push_scope() {
    VarScope *new_scope = malloc(sizeof(VarScope));
    new_scope->vars = NULL;
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void pop_scope() {
    if (current_scope == NULL) return;
    
    // Libérer les variables du scope
    Variable *var = current_scope->vars;
    while (var != NULL) {
        Variable *next = var->next;
        free(var->name);
        if (var->type == VAR_STRING && var->value.str_val != NULL) {
            free(var->value.str_val);
        }
        free(var);
        var = next;
    }
    
    VarScope *old_scope = current_scope;
    current_scope = current_scope->parent;
    free(old_scope);
}
