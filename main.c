#include "minilang.h"

// ============================================================================
// DÉFINITION DES VARIABLES GLOBALES
// ============================================================================

Variable *variables = NULL;
Function *functions = NULL;
Token *tokens = NULL;
int token_count = 0;
int current_token = 0;
int current_line = 1;
VarScope *current_scope = NULL;
ReturnValue return_value = {false, {VAR_VOID, {0}}};
ControlFlow control_flow = {false, false};

// ============================================================================
// FONCTION PRINCIPALE
// ============================================================================

int main(int argc, char *argv[]) {
    // Gestion des arguments
    if (argc < 2) {
        print_help();
        return 1;
    }
    
    // Option --version ou -v
    if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
        print_version();
        return 0;
    }
    
    // Option --help ou -h
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }
    
    // Ouverture du fichier source
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Erreur: impossible d'ouvrir le fichier %s\n", argv[1]);
        fprintf(stderr, "Utilisez 'minilang --help' pour plus d'informations\n");
        return 1;
    }
    
    // Lecture du contenu
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
