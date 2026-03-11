# 🚀 MiniLang v3.3.0

**Langage de programmation complet avec interpréteur C**

[![Version](https://img.shields.io/badge/version-3.3.0-blue.svg)](https://github.com)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![C](https://img.shields.io/badge/language-C-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

---

## ✨ Nouveautés v3.3.0

### 1. Opérateurs Composés ✅

Assignation avec opération intégrée :

```c
int x = 10;
x += 5;   // x = x + 5  → 15
x -= 3;   // x = x - 3  → 12
x *= 2;   // x = x * 2  → 24
x /= 4;   // x = x / 4  → 6
```

**Fonctionne avec `int` et `float` !**

### 2. Comparaison de Chaînes ✅

```c
str nom1 = "Alice";
str nom2 = "Alice";
str nom3 = "Bob";

if (nom1 == nom2) {
    print("Identiques!");
}

if (nom1 != nom3) {
    print("Différents!");
}

// Avec input()
str motDePasse = input("Mot de passe: ");
if (motDePasse == "secret") {
    print("Accès autorisé!");
}
```

**Opérateurs supportés : `==` et `!=`**

---

## 🎯 Exemple Complet

```c
// Quiz interactif avec v3.3.0

print("=== QUIZ ===");

str nom = input("Votre nom: ");
int points = 0;

// Question 1
print("Combien font 5 + 3?");
int rep = input("Reponse: ");
if (rep == 8) {
    print("Correct!");
    points += 10;  // Opérateur composé !
}

// Question 2
print("Capitale de la France?");
str ville = input("Reponse: ");
if (ville == "Paris") {  // Comparaison chaînes !
    print("Bravo!");
    points += 10;
}

print("Score final: " + points + " / 20");
```

---

## 📦 Toutes les Fonctionnalités

### ✅ Types
- int, float, str, bool, void
- Tableaux (int[], float[])

### ✅ Opérateurs
- **Arithmétiques** : +, -, *, /, %
- **Composés** : +=, -=, *=, /= (NOUVEAU v3.3.0)
- **Comparaison** : ==, !=, <, >, <=, >=
- **Comparaison chaînes** : ==, != (NOUVEAU v3.3.0)
- **Logiques** : &&, ||, !
- **Concaténation** : + (pour chaînes)

### ✅ I/O
- print(expression) - Avec concaténation complète
- input("prompt") - Avec conversion automatique

### ✅ Structures
- if/else, while, for
- break, continue

### ✅ Fonctions
- Déclaration, retour, récursivité
- Type void pour procédures
- Scopes isolés

---

## 🚀 Installation

```bash
unzip minilang_v3.3.0.zip
cd minilang_v3.3.0
make
./minilang --version
```

---

## 📊 Évolution des Versions

| Version | Nouveautés |
|---------|------------|
| v3.3.0 | **Opérateurs composés (+=, -=, *=, /=)**, **Comparaison chaînes** |
| v3.2.3 | Structure professionnelle (src/, include/, tests/) |
| v3.2.2 | Concaténation complète |
| v3.2.1 | input() fonctionnel |
| v3.2.0 | Bool natif, break/continue |

---

## 🎮 Tests

```bash
make test                     # Tous les tests
make test-concat              # Concaténation
./minilang tests/demo_v3.3.0.ml  # Démo v3.3.0
```

---

## 📁 Structure

```
minilang_v3.3.0/
├── src/          Sources C (7 fichiers)
├── include/      Headers (2 fichiers)
├── tests/        Tests et démos (12+ fichiers)
├── Makefile      Build system
└── README.md     Cette documentation
```

---

## 🎯 Cas d'Usage v3.3.0

### Compteur avec +=
```c
int score = 0;
for (int i = 0; i < 5; i += 1) {
    score += 10;
}
print("Score: " + score);  // 50
```

### Système de Connexion
```c
str utilisateur = input("Nom: ");
str mdp = input("Mot de passe: ");

if (utilisateur == "admin" && mdp == "1234") {
    print("Bienvenue admin!");
} else {
    print("Accès refusé!");
}
```

### Calculatrice Avancée
```c
int total = 100;

str operation = input("Operation (+/-/*//): ");
int valeur = input("Valeur: ");

if (operation == "+") {
    total += valeur;
} else if (operation == "-") {
    total -= valeur;
} else if (operation == "*") {
    total *= valeur;
} else if (operation == "/") {
    total /= valeur;
}

print("Résultat: " + total);
```

---

## 🛠️ Commandes Make

```bash
make              # Compiler
make test         # Tests
make clean        # Nettoyer
make info         # Infos projet
make count        # Lignes de code
```

---

## 📈 Statistiques

- **Version** : 3.3.0
- **Lignes de code** : ~2000
- **Nouveautés** : 2 fonctionnalités majeures
- **Tests** : 12+
- **Statut** : Production Ready ✅

---

## 🗺️ Roadmap

### v3.4.0 (Futur proche)
- [ ] Tableaux en paramètres de fonction
- [ ] Opérations sur chaînes (.length, .substring)
- [ ] Tableaux de chaînes (str[])

### v4.0.0 (Futur)
- [ ] Structures (struct)
- [ ] Classes et objets
- [ ] Bibliothèque standard

---

**MiniLang v3.3.0 - Plus puissant, plus simple !** 🚀
