#ifndef VERSION_H
#define VERSION_H

// Version de MiniLang
#define MINILANG_VERSION_MAJOR 3
#define MINILANG_VERSION_MINOR 5
#define MINILANG_VERSION_PATCH 0

#define MINILANG_VERSION "3.5.0"

// Date et heure de compilation
#define MINILANG_BUILD_DATE __DATE__
#define MINILANG_BUILD_TIME __TIME__

// Fonctionnalités de cette version
#define MINILANG_FEATURES \
    "  - Types: int, float, str, bool, void, tableaux\n" \
    "  - Opérateurs: arithmétiques, comparaison, logiques\n" \
    "  - Structures: if/else, while, for, break, continue\n" \
    "  - Fonctions avec paramètres et return\n" \
    "  - Procédures void (sans retour)\n" \
    "  - Type bool natif (true/false)\n" \
    "  - Concaténation de chaînes avec +\n" \
    "  - input() pour lire l'entrée utilisateur\n" \
    "  - Scopes isolés\n" \
    "  - Commentaires // et /* */"

// Historique des versions
#define MINILANG_CHANGELOG \
    "Historique:\n" \
    "  v3.5.0 - TABLEAUX EN RETOUR: func int[] creer() {}\n" \
    "  v3.4.2 - CORRECTIFS: 3 bugs (taille tableau, 2D, += chaîne)\n" \
    "  v3.4.1 - 2 bugs critiques (type tableau, .length str[])\n" \
    "  v3.4.0 - Tableaux en paramètres, str[], .length, .substring\n" \
    "  v3.3.5 - Division/Modulo par zéro\n" \
    "  v3.3.4 - Validation stricte\n" \
    "  v3.3.3 - if/else if\n" \
    "  v3.3.2 - Concaténation\n" \
    "  v3.3.0 - Opérateurs composés\n" \
    "  v3.2.0 - Bool natif\n" \
    "  v3.0.0 - Fonctions\n" \
    "  v1.0.0 - Initial"

// Prototypes
void print_version();
void print_help();

#endif // VERSION_H
