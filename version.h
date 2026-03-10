#ifndef VERSION_H
#define VERSION_H

// Version de MiniLang
#define MINILANG_VERSION_MAJOR 3
#define MINILANG_VERSION_MINOR 2
#define MINILANG_VERSION_PATCH 1

#define MINILANG_VERSION "3.2.1"

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
    "  v3.2.1 - CORRECTIF: input() fonctionnel, conversion automatique\n" \
    "  v3.2.0 - Bool natif, break/continue, concaténation\n" \
    "  v3.1.1 - CORRECTIF: Gestion des chaînes en paramètres\n" \
    "  v3.1.0 - Support void, système de versioning\n" \
    "  v3.0.0 - Fonctions, architecture modulaire\n" \
    "  v2.0.0 - Structures de contrôle, tableaux\n" \
    "  v1.0.0 - Version initiale"

// Prototypes
void print_version();
void print_help();

#endif // VERSION_H
