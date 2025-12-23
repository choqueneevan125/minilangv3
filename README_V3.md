# 🚀 MiniLang v3 - Langage de Programmation Complet

## 📦 Architecture Modulaire

MiniLang v3 adopte une architecture modulaire professionnelle pour faciliter la maintenance et l'évolution.

### Structure du Projet

```
v3/
├── minilang.h          # En-tête principal (structures, prototypes)
├── main.c              # Point d'entrée du programme
├── lexer.c             # Analyse lexicale (tokenisation)
├── parser.c            # Analyse syntaxique et exécution
├── evaluator.c         # Évaluation des expressions
├── symbols.c           # Gestion des variables et fonctions
├── utils.c             # Fonctions utilitaires
├── Makefile            # Compilation automatisée
└── test_*.ml           # Fichiers de test
```

---

## ✨ Nouveauté v3: Fonctions / Procédures

### Déclaration de Fonction

```c
func type_retour nom_fonction(type param1, type param2, ...) {
    // Corps de la fonction
    return valeur;
}
```

### Exemples

#### Fonction sans paramètres
```c
func int getNumber() {
    return 42;
}

int n = getNumber();
print(n);  // Affiche: 42
```

#### Fonction avec paramètres
```c
func int addition(int a, int b) {
    return a + b;
}

int somme = addition(10, 20);
print(somme);  // Affiche: 30
```

#### Fonction avec logique
```c
func int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

print(max(15, 25));  // Affiche: 25
```

#### Fonction avec boucle
```c
func int factorielle(int n) {
    int result = 1;
    for (int i = 2; i <= n; i = i + 1) {
        result = result * i;
    }
    return result;
}

print(factorielle(5));  // Affiche: 120
```

---

## 🎯 Caractéristiques des Fonctions

### ✅ Scopes Isolés

Chaque fonction a son propre scope isolé :

```c
int x = 100;  // Variable globale

func int testScope(int x) {
    // Ce x est un paramètre, indépendant du x global
    x = x + 10;
    return x;
}

int result = testScope(5);
print(result);  // Affiche: 15
print(x);       // Affiche: 100 (inchangé)
```

### ✅ Appels Imbriqués

Les fonctions peuvent s'appeler entre elles :

```c
func int double(int n) {
    return n * 2;
}

func int quadruple(int n) {
    int temp = double(n);
    return double(temp);
}

print(quadruple(5));  // Affiche: 20
```

### ✅ Types de Retour

- `int` - Entier
- `float` - Nombre décimal
- Pas encore de `void` explicite (utiliser `int` et ignorer le retour)

### ✅ Passage par Valeur

Les paramètres sont passés par valeur (copie) :

```c
func int modifier(int x) {
    x = x * 2;
    return x;
}

int a = 5;
int b = modifier(a);
// a vaut toujours 5
// b vaut 10
```

---

## 📚 Exemples Complets

### Bibliothèque Mathématique

```c
func int puissance(int base, int exp) {
    int resultat = 1;
    for (int i = 0; i < exp; i = i + 1) {
        resultat = resultat * base;
    }
    return resultat;
}

func int pgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

func int estPremier(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    
    for (int i = 3; i * i <= n; i = i + 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Utilisation
print(puissance(2, 10));  // 1024
print(pgcd(48, 18));      // 6
print(estPremier(17));    // 1 (vrai)
```

### Fibonacci avec Fonction

```c
func int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    int a = 0;
    int b = 1;
    int temp = 0;
    
    for (int i = 2; i <= n; i = i + 1) {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return b;
}

// Les 10 premiers nombres de Fibonacci
for (int i = 0; i < 10; i = i + 1) {
    print(fibonacci(i));
}
```

---

## 🔧 Compilation et Exécution

### Compilation

```bash
cd v3
make
```

### Exécution

```bash
./minilang mon_programme.ml
```

### Tests

```bash
make test-all                # Tous les tests
make test-functions          # Tests fonctions basiques
make test-factorial          # Test factorielle
make test-fibonacci          # Test Fibonacci
make test-arithmetic-func    # Tests arithmétiques
make test-scope              # Tests scopes
```

---

## 📖 Référence Complète

### Tous les Types

- `int` - Entiers
- `float` - Nombres décimaux  
- `str` - Chaînes de caractères
- `int[n]` / `float[n]` - Tableaux

### Tous les Opérateurs

**Arithmétiques**: `+`, `-`, `*`, `/`, `%`  
**Comparaison**: `==`, `!=`, `<`, `>`, `<=`, `>=`  
**Logiques**: `&&`, `||`, `!`

### Toutes les Structures

- `if (condition) { ... } else { ... }`
- `while (condition) { ... }`
- `for (init; condition; increment) { ... }`
- `func type nom(params) { ... return value; }`

### Fonctions Intégrées

- `print(expression)` - Affichage

---

## 🎓 Bonnes Pratiques

### 1. Nommage des Fonctions

```c
// ✅ Bon
func int calculerMoyenne(int a, int b) { ... }
func int estPair(int n) { ... }

// ❌ Éviter
func int f(int x, int y) { ... }
func int test(int a) { ... }
```

### 2. Une Fonction = Une Responsabilité

```c
// ✅ Bon - fonction simple et claire
func int doubler(int n) {
    return n * 2;
}

// ❌ Éviter - trop de responsabilités
func int faireBeaucoup(int n) {
    // Calcule plein de choses différentes...
}
```

### 3. Limiter la Taille

Gardez vos fonctions courtes (< 30 lignes idéalement)

### 4. Commentaires

```c
// Calcule la factorielle de n
// Retourne 1 si n <= 1
func int factorielle(int n) {
    if (n <= 1) {
        return 1;
    }
    
    int result = 1;
    for (int i = 2; i <= n; i = i + 1) {
        result = result * i;
    }
    return result;
}
```

---

## 🔍 Différences avec la v2

| Fonctionnalité | v2 | v3 |
|----------------|----|----|
| Architecture | Monolithique | Modulaire |
| Fichiers | 1 fichier | 7 fichiers |
| Fonctions | ❌ | ✅ |
| Scopes isolés | Partiel | Complet |
| Return | ❌ | ✅ |
| Paramètres | ❌ | ✅ |
| Appels imbriqués | ❌ | ✅ |

---

## 📊 Architecture Technique

### Flux d'Exécution

```
Source Code (.ml)
      ↓
  Lexer (lexer.c)
      ↓
  Tokens
      ↓
  Parser (parser.c) ←→ Evaluator (evaluator.c)
      ↓                      ↓
  Symbols (symbols.c) ←→ Functions
      ↓
  Exécution
```

### Modules

#### **minilang.h**
- Définitions des structures
- Types énumérés
- Prototypes de fonctions
- Variables globales externes

#### **main.c**
- Point d'entrée
- Lecture du fichier source
- Orchestration lexer → parser
- Nettoyage mémoire

#### **lexer.c**
- Tokenisation du code source
- Gestion des commentaires
- Reconnaissance mots-clés
- Gestion des nombres et chaînes

#### **parser.c**
- Analyse syntaxique
- Déclaration de fonctions
- Appel de fonctions
- Gestion des structures de contrôle

#### **evaluator.c**
- Évaluation des expressions
- Priorité des opérateurs
- Conversion de types
- Appel de fonctions dans expressions

#### **symbols.c**
- Table des symboles (variables)
- Table des fonctions
- Gestion des scopes
- Push/Pop de scopes

#### **utils.c**
- Fonctions utilitaires
- Gestion des erreurs
- Conversion de types
- Libération mémoire

---

## 🚀 Aller Plus Loin

### Exercices

1. **Écrivez une fonction `moyenne`** qui calcule la moyenne de 3 nombres

2. **Implémentez `estPalindrome`** pour vérifier si un nombre est palindrome

3. **Créez une fonction `sommePairs`** qui additionne tous les nombres pairs jusqu'à n

4. **Faites une fonction `triangle`** qui affiche un triangle de nombres

### Projets

1. **Calculatrice scientifique** - Créez une bibliothèque de fonctions mathématiques

2. **Jeu de devinettes** - Utilisez des fonctions pour structurer le jeu

3. **Analyse de tableau** - Fonctions min, max, moyenne, médiane

4. **Suite mathématique** - Implémentez différentes suites (arithmétique, géométrique, etc.)

---

## 🎉 Félicitations !

Vous maîtrisez maintenant **MiniLang v3** avec :

✅ **7 modules** bien organisés  
✅ **Fonctions** avec paramètres et retour  
✅ **Scopes isolés** pour chaque fonction  
✅ **Appels imbriqués** illimités  
✅ **Architecture professionnelle** maintenable  

**MiniLang est maintenant un vrai langage procédural !** 🎊

---

## 📝 Changelog

### v3.0 (Actuelle)
- ✨ Ajout des fonctions avec `func`
- ✨ Support des paramètres de fonction
- ✨ Instruction `return`
- ✨ Scopes isolés par fonction
- ✨ Architecture modulaire (7 fichiers)
- 🐛 Correction appels de fonction dans print
- 📚 Documentation complète

### v2.0
- ✨ Opérateurs de comparaison
- ✨ Opérateurs logiques
- ✨ Structures if/else, while, for
- ✨ Tableaux
- ✨ Commentaires

### v1.0
- ✨ Types de base (int, float, str)
- ✨ Opérations arithmétiques
- ✨ Variables
- ✨ Print
