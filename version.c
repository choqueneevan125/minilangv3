#include "minilang.h"

void print_version() {
    printf("MiniLang v%s\n", MINILANG_VERSION);
    printf("Compilé le %s à %s\n\n", MINILANG_BUILD_DATE, MINILANG_BUILD_TIME);
    printf("Langage de programmation complet avec fonctions\n\n");
    printf("Fonctionnalités:\n");
    printf(MINILANG_FEATURES);
    printf("\nAuteur: Claude\n");
    printf("Licence: MIT\n");
}

void print_help() {
    printf("MiniLang v%s - Interpréteur de langage de programmation\n\n", MINILANG_VERSION);
    
    printf("Usage:\n");
    printf("  minilang <fichier.ml>    Exécuter un programme\n");
    printf("  minilang --version       Afficher la version\n");
    printf("  minilang --help          Afficher cette aide\n");
    printf("  minilang -v              Alias pour --version\n");
    printf("  minilang -h              Alias pour --help\n\n");
    
    printf("Exemples:\n");
    printf("  minilang programme.ml\n");
    printf("  minilang test_bool.ml\n\n");
    
    printf("Fonctionnalités:\n");
    printf(MINILANG_FEATURES);
    printf("\n");
    
    printf(MINILANG_CHANGELOG);
    printf("\n");
    
    printf("Documentation: Consultez README_V3.2.0.md\n");
}
