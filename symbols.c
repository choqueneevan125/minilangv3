#include "minilang.h"

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
    Variable *current = current_scope->vars;
    while (current != NULL) {
        Variable *next = current->next;
        free(current->name);
        if (current->type == VAR_STRING && current->value.str_val != NULL) {
            free(current->value.str_val);
        }
        if (current->type == VAR_ARRAY) {
            if (current->value.array_val.elem_type == VAR_INT) {
                free(current->value.array_val.int_array);
            } else if (current->value.array_val.elem_type == VAR_FLOAT) {
                free(current->value.array_val.float_array);
            }
        }
        free(current);
        current = next;
    }
    
    VarScope *parent = current_scope->parent;
    free(current_scope);
    current_scope = parent;
}

// ============================================================================
// GESTION DES VARIABLES
// ============================================================================

Variable *find_variable(const char *name) {
    VarScope *scope = current_scope;
    while (scope != NULL) {
        Variable *current = scope->vars;
        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                return current;
            }
            current = current->next;
        }
        scope = scope->parent;
    }
    return NULL;
}

void add_variable(const char *name, VarType type) {
    if (current_scope == NULL) {
        push_scope();
    }
    
    // Chercher dans le scope actuel seulement
    Variable *current = current_scope->vars;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->type = type;
            return;
        }
        current = current->next;
    }
    
    // Créer nouvelle variable
    Variable *var = malloc(sizeof(Variable));
    var->name = strdup(name);
    var->type = type;
    var->value.int_val = 0; // Initialisation par défaut
    var->next = current_scope->vars;
    current_scope->vars = var;
}

// ============================================================================
// GESTION DES FONCTIONS
// ============================================================================

Function *find_function(const char *name) {
    Function *current = functions;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_function(Function *func) {
    func->next = functions;
    functions = func;
}

// ============================================================================
// LIBÉRATION MÉMOIRE
// ============================================================================

void free_variables() {
    while (current_scope != NULL) {
        pop_scope();
    }
}

void free_functions() {
    Function *current = functions;
    while (current != NULL) {
        Function *next = current->next;
        free(current->name);
        
        // Libérer les paramètres
        Param *param = current->params;
        while (param != NULL) {
            Param *next_param = param->next;
            free(param->name);
            free(param);
            param = next_param;
        }
        
        free(current);
        current = next;
    }
    functions = NULL;
}
