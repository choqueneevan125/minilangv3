#include <stdio.h>
#include "version.h"

void print_version() {
    printf("%s v%s\n", MINILANG_NAME, MINILANG_VERSION);
    printf("Compilé le %s à %s\n", MINILANG_BUILD_DATE, MINILANG_BUILD_TIME);
    printf("\n%s\n", MINILANG_DESCRIPTION);
    printf("\nFonctionnalités:\n%s", MINILANG_FEATURES);
    printf("\nAuteur: %s\n", MINILANG_AUTHOR);
    printf("Licence: %s\n", MINILANG_LICENSE);
}

void print_help() {
    printf("%s v%s - %s\n\n", MINILANG_NAME, MINILANG_VERSION, MINILANG_DESCRIPTION);
    
    printf("Usage:\n");
    printf("  minilang <fichier.ml>         Exécuter un programme\n");
    printf("  minilang --version            Afficher la version\n");
    printf("  minilang --help               Afficher cette aide\n");
    printf("  minilang -v                   Afficher la version (court)\n");
    printf("  minilang -h                   Afficher cette aide (court)\n");
    
    printf("\nExemples:\n");
    printf("  minilang hello.ml             Exécuter hello.ml\n");
    printf("  minilang test.ml              Exécuter test.ml\n");
    
    printf("\nFonctionnalités:\n%s", MINILANG_FEATURES);
    
    printf("\n%s\n", MINILANG_CHANGELOG);
    
    printf("\nDocumentation:\n");
    printf("  Voir README_V3.1.md pour la documentation complète\n");
}
