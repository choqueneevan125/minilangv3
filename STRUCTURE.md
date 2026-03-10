# 📐 Structure du Projet MiniLang v3.2.3

## 🎯 Organisation Professionnelle

MiniLang v3.2.3 adopte une structure modulaire et organisée pour faciliter le développement et la maintenance.

---

## 📁 Arborescence Complète

```
minilang_v3.2.3/
│
├── 📂 src/                         Sources C (.c)
│   ├── main.c                     Point d'entrée principal
│   ├── lexer.c                    Analyseur lexical (tokenization)
│   ├── parser.c                   Analyseur syntaxique
│   ├── evaluator.c                Évaluation d'expressions
│   ├── symbols.c                  Table des symboles
│   ├── utils.c                    Fonctions utilitaires
│   └── version.c                  Gestion de version
│
├── 📂 include/                     Headers (.h)
│   ├── minilang.h                 Déclarations principales
│   └── version.h                  Version et changelog
│
├── 📂 tests/                       Tests et exemples (.ml)
│   ├── calculatrice_v2.ml         Calculatrice interactive
│   ├── test_concat_complet.ml     Tests concaténation
│   ├── test_bool.ml               Tests type bool
│   ├── test_break_continue.ml     Tests break/continue
│   ├── test_input.ml              Tests input()
│   ├── test_functions.ml          Tests fonctions
│   ├── test_factorial.ml          Factorielle récursive
│   ├── test_fibonacci_func.ml     Suite de Fibonacci
│   └── hello.ml                   Hello World
│
├── 📂 build/                       Objets compilés (.o)
│   └── (créé automatiquement)
│
├── 📄 Makefile                     Système de build
├── 📄 README.md                    Documentation principale
├── 📄 STRUCTURE.md                 Ce fichier
└── 🔧 minilang                     Exécutable (après make)
```

---

## 🔍 Détail des Dossiers

### 📂 src/ - Sources C

Contient tous les fichiers sources (.c) de l'interpréteur.

**main.c** (Point d'entrée)
- Parse les arguments CLI
- Lit le fichier source
- Lance la compilation et l'exécution

**lexer.c** (Analyseur lexical)
- Transforme le code source en tokens
- Reconnaît les mots-clés, opérateurs, littéraux
- Gère les commentaires

**parser.c** (Analyseur syntaxique)
- Parse les statements (déclarations, affectations, etc.)
- Gère les structures de contrôle (if, while, for)
- Gère les appels de fonctions

**evaluator.c** (Évaluateur)
- Évalue les expressions arithmétiques
- Gère les opérateurs logiques
- Implémente la concaténation de chaînes

**symbols.c** (Table des symboles)
- Gestion des variables et scopes
- Gestion des fonctions
- Allocation/libération mémoire

**utils.c** (Utilitaires)
- Affichage des erreurs
- Fonctions helper

**version.c** (Version)
- Affichage de la version
- Affichage de l'aide

### 📂 include/ - Headers

Contient les déclarations et définitions partagées.

**minilang.h** (Header principal)
- Définition des types (Token, Variable, Function, etc.)
- Déclarations de toutes les fonctions publiques
- Constantes globales

**version.h** (Version)
- Numéro de version
- Changelog
- Informations de build

### 📂 tests/ - Tests et Exemples

Programmes de test en MiniLang (.ml).

**Organisés par fonctionnalité :**
- Input/Output
- Types de données
- Structures de contrôle
- Fonctions
- Exemples complets

### 📂 build/ - Objets Compilés

Dossier automatiquement créé lors de la compilation.
Contient les fichiers .o (objets compilés).

**Avantages :**
- Sépare les objets du code source
- Facilite le nettoyage
- Accélère la recompilation incrémentale

---

## 🔗 Dépendances entre Fichiers

### Diagramme de Dépendances

```
main.c
  ├─> minilang.h
  └─> version.h

lexer.c
  └─> minilang.h

parser.c
  └─> minilang.h
      └─> evaluator.c
      └─> symbols.c

evaluator.c
  └─> minilang.h

symbols.c
  └─> minilang.h

utils.c
  └─> minilang.h

version.c
  ├─> minilang.h
  └─> version.h
```

### Inclusion des Headers

Tous les fichiers .c dans src/ incluent :
```c
#include "../include/minilang.h"
```

version.c inclut aussi :
```c
#include "../include/version.h"
```

---

## 🛠️ Processus de Compilation

### Étapes

1. **Création du dossier build/** (si absent)
   ```bash
   mkdir -p build
   ```

2. **Compilation des fichiers .c en .o**
   ```bash
   gcc -Iinclude -c src/main.c -o build/main.o
   gcc -Iinclude -c src/lexer.c -o build/lexer.o
   # ... pour chaque fichier
   ```

3. **Linking des objets**
   ```bash
   gcc build/*.o -o minilang
   ```

### Flags de Compilation

- `-std=gnu99` : Standard C99 avec extensions GNU
- `-Wall -Wextra` : Warnings étendus
- `-O2` : Optimisation niveau 2
- `-g` : Informations de debug
- `-Iinclude` : Chercher les headers dans include/

---

## 📝 Conventions de Nommage

### Fichiers

- Sources : `nom.c`
- Headers : `nom.h`
- Tests : `test_fonctionnalite.ml` ou `exemple.ml`

### Fonctions

- Préfixe par module : `parse_statement()`, `evaluate_expression()`
- Snake_case : `find_variable()`, `add_function()`

### Variables

- Snake_case : `current_token`, `token_count`
- Constantes : `TOKEN_PLUS`, `VAR_INT`

### Types

- PascalCase : `Token`, `Variable`, `ExprResult`
- Suffixe Type : `TokenType`, `VarType`

---

## 🔧 Makefile Targets

### Compilation

```bash
make          # Compile le projet
make debug    # Compile en mode debug
make clean    # Nettoie build/ et minilang
```

### Tests

```bash
make test              # Tous les tests
make test-concat       # Test concaténation
make test-bool         # Test bool
make test-break        # Test break/continue
make test-functions    # Test fonctions
```

### Installation

```bash
make install    # Installe dans /usr/local/bin/
make uninstall  # Désinstalle
```

### Informations

```bash
make info     # Infos sur le projet
make count    # Compte lignes de code
```

---

## 🎯 Avantages de cette Structure

### ✅ Maintenabilité

- Code organisé par responsabilité
- Headers séparés des sources
- Tests isolés

### ✅ Lisibilité

- Facile de trouver un fichier
- Hiérarchie claire
- Documentation intégrée

### ✅ Évolutivité

- Facile d'ajouter de nouveaux modules
- Séparation claire des concerns
- Tests faciles à ajouter

### ✅ Professionnalisme

- Structure standard dans l'industrie
- Compatible avec IDE/éditeurs
- Facilite la collaboration

---

## 📊 Statistiques du Projet

### Par Dossier

```
src/       : ~1800 lignes (7 fichiers)
include/   : ~200 lignes  (2 fichiers)
tests/     : ~50 lignes   (10+ fichiers)
Total      : ~2050 lignes
```

### Par Fichier (approximatif)

```
parser.c    : ~700 lignes
evaluator.c : ~300 lignes
lexer.c     : ~250 lignes
symbols.c   : ~150 lignes
minilang.h  : ~150 lignes
main.c      : ~80 lignes
version.c   : ~50 lignes
utils.c     : ~30 lignes
version.h   : ~50 lignes
```

---

## 🚀 Comment Contribuer

### Ajouter une Fonctionnalité

1. **Modifier les headers** (include/)
   - Ajouter types/constantes si nécessaire
   - Déclarer nouvelles fonctions

2. **Implémenter** (src/)
   - Ajouter code dans fichier approprié
   - Ou créer nouveau fichier si gros module

3. **Tester** (tests/)
   - Créer fichier de test
   - Ajouter target dans Makefile

4. **Compiler et tester**
   ```bash
   make clean
   make
   make test
   ```

---

**Structure professionnelle pour un développement organisé ! 🎯**
