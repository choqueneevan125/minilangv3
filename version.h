#ifndef VERSION_H
#define VERSION_H

// Version de MiniLang
#define MINILANG_VERSION_MAJOR 3
#define MINILANG_VERSION_MINOR 1
#define MINILANG_VERSION_PATCH 1

#define MINILANG_VERSION "3.1.1"
#define MINILANG_BUILD_DATE __DATE__
#define MINILANG_BUILD_TIME __TIME__

// Informations sur le projet
#define MINILANG_NAME "MiniLang"
#define MINILANG_DESCRIPTION "Langage de programmation complet avec fonctions"
#define MINILANG_AUTHOR "Claude"
#define MINILANG_LICENSE "MIT"

// Fonctionnalités de cette version
#define MINILANG_FEATURES \
    "  - Types: int, float, str, void, tableaux\n" \
    "  - Opérateurs: arithmétiques, comparaison, logiques\n" \
    "  - Structures: if/else, while, for\n" \
    "  - Fonctions avec paramètres et return\n" \
    "  - Procédures void (sans retour)\n" \
    "  - Scopes isolés\n" \
    "  - Commentaires // et /* */"

// Historique des versions
#define MINILANG_CHANGELOG \
    "Historique:\n" \
    "  v3.1.1 - CORRECTIF: Gestion des chaînes en paramètres\n" \
    "  v3.1.0 - Support void, système de versioning\n" \
    "  v3.0.0 - Fonctions, architecture modulaire\n" \
    "  v2.0.0 - Structures de contrôle, tableaux\n" \
    "  v1.0.0 - Version initiale"

// Fonction pour afficher la version
void print_version();
void print_help();

#endif // VERSION_H
