#include "minilang.h"

// Définition des variables globales
Variable *variables = NULL;
Function *functions = NULL;
Token *tokens = NULL;
int token_count = 0;
int current_token = 0;
int current_line = 1;
VarScope *current_scope = NULL;
ReturnValue return_value = {false, {VAR_VOID, {0}}};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <fichier.ml>\n", argv[0]);
        printf("\nMiniLang v3 - Langage de programmation complet\n");
        printf("Fonctionnalités:\n");
        printf("  - Types: int, float, str, tableaux\n");
        printf("  - Opérateurs: arithmétiques, comparaison, logiques\n");
        printf("  - Structures: if/else, while, for\n");
        printf("  - Fonctions avec paramètres et retour\n");
        printf("  - Commentaires // et /* */\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Erreur: impossible d'ouvrir le fichier %s\n", argv[1]);
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *source = malloc(size + 1);
    size_t read_size = fread(source, 1, size, file);
    source[read_size] = '\0';
    fclose(file);
    
    // Exécution
    lexer(source);
    parser();
    
    // Nettoyage
    free(source);
    free_tokens();
    free_variables();
    free_functions();
    
    return 0;
}
