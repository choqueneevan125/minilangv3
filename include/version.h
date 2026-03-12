#ifndef VERSION_H
#define VERSION_H

// Version de MiniLang
#define MINILANG_VERSION_MAJOR 3
#define MINILANG_VERSION_MINOR 3
#define MINILANG_VERSION_PATCH 0

#define MINILANG_VERSION "3.3.1"

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
    "  v3.3.1 - Opérateurs composés (+=, -=, *=, /=), comparaison chaînes\n" \
    "  v3.2.3 - Structure organisée (src/, include/, tests/)\n" \
    "  v3.2.2 - CORRECTIF: Concaténation complète\n" \
    "  v3.2.1 - CORRECTIF: input() fonctionnel\n" \
    "  v3.2.0 - Bool natif, break/continue\n" \
    "  v3.1.1 - CORRECTIF: Chaînes en paramètres\n" \
    "  v3.1.0 - Support void, versioning\n" \
    "  v3.0.0 - Fonctions, modulaire\n" \
    "  v2.0.0 - Structures, tableaux\n" \
    "  v1.0.0 - Version initiale"

// Prototypes
void print_version();
void print_help();

#endif // VERSION_H
