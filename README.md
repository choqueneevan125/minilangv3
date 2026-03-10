# 🚀 MiniLang v3.2.3

**Langage de programmation complet avec interpréteur C**

[![Version](https://img.shields.io/badge/version-3.2.3-blue.svg)](https://github.com)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![C](https://img.shields.io/badge/language-C-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

---

## 📋 Table des Matières

- [Nouveautés v3.2.3](#nouveautés-v323)
- [Installation](#installation)
- [Structure du Projet](#structure-du-projet)
- [Utilisation](#utilisation)
- [Fonctionnalités](#fonctionnalités)
- [Exemples](#exemples)
- [Développement](#développement)

---

## ✨ Nouveautés v3.2.3

### Structure Professionnelle Organisée

```
minilang_v3.2.3/
├── src/           # Sources C
├── include/       # Headers
├── tests/         # Fichiers de test
├── build/         # Objets compilés (auto-créé)
├── Makefile       # Build system
└── README.md      # Documentation
```

### Améliorations

- ✅ **Organisation professionnelle** avec séparation src/include/tests
- ✅ **Makefile avancé** avec targets de test
- ✅ **Build directory** pour objets compilés
- ✅ **Commandes de test** intégrées
- ✅ input() fonctionnel (v3.2.1)
- ✅ Concaténation complète (v3.2.2)

---

## 🚀 Installation

### Prérequis

- GCC (ou compilateur C compatible)
- Make
- Linux/Unix/MacOS

### Installation Rapide

```bash
# 1. Extraire
unzip minilang_v3.2.3.zip
cd minilang_v3.2.3

# 2. Compiler
make

# 3. Tester
./minilang --version
make test
```

### Installation Système (Optionnel)

```bash
sudo make install
```

Le binaire sera installé dans `/usr/local/bin/`

---

## 📁 Structure du Projet

```
minilang_v3.2.3/
│
├── src/                    # Sources C
│   ├── main.c             # Point d'entrée
│   ├── lexer.c            # Analyseur lexical
│   ├── parser.c           # Analyseur syntaxique
│   ├── evaluator.c        # Évaluateur d'expressions
│   ├── symbols.c          # Gestion des symboles
│   ├── utils.c            # Utilitaires
│   └── version.c          # Informations de version
│
├── include/               # Headers
│   ├── minilang.h         # Déclarations principales
│   └── version.h          # Version et changelog
│
├── tests/                 # Tests et exemples
│   ├── calculatrice_v2.ml         # Calculatrice interactive
│   ├── test_concat_complet.ml     # Test concaténation
│   ├── test_bool.ml               # Test type bool
│   ├── test_break_continue.ml     # Test break/continue
│   ├── test_input.ml              # Test input()
│   ├── test_functions.ml          # Test fonctions
│   ├── test_factorial.ml          # Factorielle récursive
│   └── test_fibonacci_func.ml     # Fibonacci
│
├── build/                 # Objets compilés (auto-créé)
│
├── Makefile              # Système de build
├── README.md             # Cette documentation
└── minilang              # Exécutable (après compilation)
```

---

## 💻 Utilisation

### Commandes de Base

```bash
# Compiler
make

# Exécuter un programme
./minilang tests/calculatrice_v2.ml

# Voir la version
./minilang --version

# Voir l'aide
./minilang --help
```

### Commandes de Test

```bash
# Tous les tests
make test

# Tests individuels
make test-concat      # Test concaténation
make test-bool        # Test bool
make test-break       # Test break/continue
make test-functions   # Test fonctions
```

### Autres Commandes

```bash
make info            # Informations sur le projet
make count           # Compter les lignes de code
make clean           # Nettoyer
make debug           # Compiler en mode debug
```

---

## ✨ Fonctionnalités

### Types de Données

- `int` - Entiers
- `float` - Nombres décimaux
- `str` - Chaînes de caractères
- `bool` - Booléens (true/false)
- `void` - Sans valeur
- Tableaux : `int[]`, `float[]`

### Entrées/Sorties

- `print(expression)` - Affichage avec concaténation
- `input("prompt")` - Lecture avec conversion automatique

### Structures de Contrôle

- `if (condition) { } else { }`
- `while (condition) { }`
- `for (init; condition; incr) { }`
- `break` - Sortir d'une boucle
- `continue` - Itération suivante

### Fonctions

- Déclaration avec paramètres et retour
- Récursivité complète
- Type void pour procédures
- Scopes isolés

### Opérateurs

- Arithmétiques : `+`, `-`, `*`, `/`, `%`
- Comparaison : `==`, `!=`, `<`, `>`, `<=`, `>=`
- Logiques : `&&`, `||`, `!`
- Concaténation : `+` (pour chaînes)

---

## 📝 Exemples

### Hello World

```c
print("Hello World!");
```

### Variables et Types

```c
int age = 25;
float prix = 19.99;
str nom = "Alice";
bool actif = true;
```

### Programme Interactif

```c
print("=== CALCULATRICE ===");

str nom = input("Votre nom: ");
print("Bonjour " + nom);

int a = input("Premier nombre: ");
int b = input("Deuxieme nombre: ");

print(a + " + " + b + " = " + (a + b));
print(a + " * " + b + " = " + (a * b));
```

### Fonction Récursive

```c
func int factorielle(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorielle(n - 1);
}

print(factorielle(5));  // 120
```

### Tableaux et Boucles

```c
int nombres[5];

for (int i = 0; i < 5; i = i + 1) {
    nombres[i] = i * 2;
}

for (int i = 0; i < 5; i = i + 1) {
    print(nombres[i]);
}
```

### Break et Continue

```c
// Break
for (int i = 0; i < 10; i = i + 1) {
    if (i == 5) {
        break;
    }
    print(i);  // 0 1 2 3 4
}

// Continue
for (int i = 0; i < 10; i = i + 1) {
    if (i % 2 == 0) {
        continue;
    }
    print(i);  // 1 3 5 7 9
}
```

---

## 🛠️ Développement

### Compiler

```bash
make
```

### Compiler en Mode Debug

```bash
make debug
```

### Ajouter un Test

1. Créer `tests/mon_test.ml`
2. Exécuter : `./minilang tests/mon_test.ml`

### Modifier le Code

1. Éditer les fichiers dans `src/` ou `include/`
2. Recompiler : `make`
3. Tester : `make test`

### Structure d'un Fichier Source

```c
#include "../include/minilang.h"

// Votre code ici
```

---

## 📊 Statistiques

- **Version** : 3.2.3
- **Lignes de code** : ~2000
- **Fichiers sources** : 7 (.c)
- **Fichiers headers** : 2 (.h)
- **Tests** : 10+
- **Langage** : C (GNU99)

---

## 🗺️ Roadmap

### v3.3.0 (À venir)

- [ ] Tableaux en paramètres de fonction
- [ ] Comparaison de chaînes
- [ ] Structures (struct)
- [ ] Plus d'opérations sur chaînes

### v4.0.0 (Futur)

- [ ] Classes et objets
- [ ] Gestion d'erreurs avancée
- [ ] Bibliothèque standard
- [ ] Modules et imports

---

## 📄 Licence

MIT License - Libre d'utilisation, modification et distribution.

---

## 👤 Auteur

Claude - Interpréteur MiniLang v3.2.3

---

## 🙏 Remerciements

Merci d'utiliser MiniLang ! Pour toute question ou suggestion, n'hésitez pas.

---

**Version actuelle : 3.2.3**  
**Date : 10 Mars 2026**  
**Statut : Stable et Production Ready ✅**
