#include "minilang.h"

// Libérer les tokens
void free_tokens() {
    for (int i = 0; i < token_count; i++) {
        free(tokens[i].value);
    }
    free(tokens);
    tokens = NULL;
    token_count = 0;
}

// Convertir un type en chaîne
const char *type_to_string(VarType type) {
    switch (type) {
        case VAR_INT: return "int";
        case VAR_FLOAT: return "float";
        case VAR_STRING: return "str";
        case VAR_ARRAY: return "array";
        case VAR_VOID: return "void";
        default: return "unknown";
    }
}

// Afficher une erreur
void print_error(const char *message, int line) {
    fprintf(stderr, "Erreur ligne %d: %s\n", line, message);
}
