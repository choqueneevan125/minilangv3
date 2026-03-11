# 🚀 MiniLang v3.3.0

**Langage de programmation complet avec nouvelles fonctionnalités avancées**

[![Version](https://img.shields.io/badge/version-3.3.0-blue.svg)](https://github.com)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

---

## ✨ Nouveautés v3.3.0

### 1. Comparaison de Chaînes ✅

```c
str nom = "Alice";
if (nom == "Alice") {
    print("Trouvé!");
}

str a = "abc";
str b = "def";
print(a < b);  // true (ordre alphabétique)
```

**Opérateurs supportés** : `==`, `!=`, `<`, `>`, `<=`, `>=`

### 2. Opérateurs d'Assignation Composés ✅

```c
int x = 10;
x += 5;   // x = 15
x -= 3;   // x = 12
x *= 2;   // x = 24
x /= 4;   // x = 6

str message = "Hello";
message += " World";  // "Hello World"
```

### 3. Méthodes sur Chaînes ✅

#### .length()
```c
str texte = "Bonjour";
int len = texte.length();  // 7
```

#### .substring(start, end)
```c
str mot = "MiniLang";
str partie = mot.substring(0, 4);  // "Mini"
```

---

## 📋 Installation

```bash
# 1. Extraire
unzip minilang_v3.3.0.zip
cd minilang_v3.3.0

# 2. Compiler
make

# 3. Tester
./minilang tests/demo_v3.3.0.ml
```

---

## 📝 Exemples Complets

### Comparaison de Mots de Passe

```c
str password = input("Mot de passe: ");

if (password == "secret123") {
    print("Accès autorisé");
} else {
    print("Accès refusé");
}
```

### Compteur avec +=

```c
int score = 0;

score += 10;   // +10 points
score += 5;    // +5 points
score -= 3;    // -3 points

print("Score: " + score);  // Score: 12
```

### Manipulation de Chaînes

```c
str nom = "Alexandre";

// Extraire initiale
str initiale = nom.substring(0, 1);
print("Initiale: " + initiale);  // A

// Vérifier longueur
if (nom.length() > 5) {
    print("Nom long");
}

// Comparer
if (nom < "Bob") {
    print("Avant Bob alphabétiquement");
}
```

### Programme Complet

```c
print("=== Gestionnaire de Mots ===");

str mot1 = input("Premier mot: ");
str mot2 = input("Deuxième mot: ");

// Comparer
if (mot1 == mot2) {
    print("Identiques");
} else if (mot1 < mot2) {
    print(mot1 + " vient avant " + mot2);
} else {
    print(mot2 + " vient avant " + mot1);
}

// Statistiques
int total = 0;
total += mot1.length();
total += mot2.length();

print("Total de lettres: " + total);
```

---

## 📁 Structure

```
minilang_v3.3.0/
├── src/          Sources C (7 fichiers)
├── include/      Headers (2 fichiers)
├── tests/        Tests (13+ fichiers)
├── Makefile      Build system
└── README.md     Documentation
```

---

## 🧪 Tests Disponibles

```bash
# Nouveaux tests v3.3.0
./minilang tests/test_compound_operators.ml    # Opérateurs +=, -=, *=, /=
./minilang tests/test_string_comparison.ml     # Comparaison chaînes
./minilang tests/test_string_methods.ml        # .length(), .substring()
./minilang tests/demo_v3.3.0.ml               # Démo complète

# Tests existants
./minilang tests/test_concat_complet.ml
./minilang tests/test_bool.ml
./minilang tests/test_functions.ml
```

---

## ✨ Toutes les Fonctionnalités

### Types
- int, float, str, bool, void, tableaux

### I/O
- print() avec concaténation
- input() avec conversion auto

### Opérateurs
- Arithmétiques : +, -, *, /, %
- Comparaison : ==, !=, <, >, <=, >=
- Logiques : &&, ||, !
- **Assignation composés** : +=, -=, *=, /= ✨ **NOUVEAU**

### Structures
- if/else, while, for
- break, continue

### Fonctions
- Déclaration, retour, récursivité
- Type void

### Chaînes **NOUVEAU v3.3.0** ✨
- **Comparaison** : ==, !=, <, >, <=, >=
- **Méthode .length()** : obtenir la longueur
- **Méthode .substring()** : extraire sous-chaîne
- **Concaténation** : + et +=

---

## 🎯 Cas d'Usage

### Validation de Formulaire
```c
str nom = input("Nom: ");
if (nom.length() < 3) {
    print("Nom trop court");
}
```

### Recherche dans Liste
```c
str recherche = input("Rechercher: ");
str items[3];
// ... remplir items ...

for (int i = 0; i < 3; i = i + 1) {
    if (items[i] == recherche) {
        print("Trouvé!");
        break;
    }
}
```

### Statistiques de Texte
```c
str texte = input("Texte: ");
int len = texte.length();

if (len > 100) {
    print("Texte long");
} else if (len > 50) {
    print("Texte moyen");
} else {
    print("Texte court");
}
```

---

## 📊 Historique des Versions

| Version | Nouveautés |
|---------|-----------|
| v3.3.0 | **Comparaison chaînes, +=/-=/\*=/=, .length()/.substring()** |
| v3.2.3 | Structure professionnelle |
| v3.2.2 | Concaténation complète |
| v3.2.1 | input() fonctionnel |
| v3.2.0 | Bool, break/continue |

---

## 🛠️ Commandes Make

```bash
make              # Compiler
make test         # Tous les tests
make clean        # Nettoyer
make info         # Informations
make count        # Compter lignes
sudo make install # Installer
```

---

## 📄 Licence

MIT License - Libre d'utilisation, modification et distribution.

---

**MiniLang v3.3.0 - Encore plus puissant ! 🎉**

**Version recommandée pour production ! ✅**
