# 🚀 MiniLang v3.2.0 - Installation Complète

## 📦 Contenu du Package

Ce package contient **TOUS** les fichiers nécessaires pour compiler et utiliser MiniLang v3.2.0.

### Fichiers Sources (9 fichiers)
```
minilang.h          - Header principal
version.h           - Gestion de version
main.c              - Point d'entrée
lexer.c             - Analyseur lexical
parser.c            - Analyseur syntaxique
evaluator.c         - Évaluateur d'expressions
symbols.c           - Gestion des symboles
utils.c             - Utilitaires
version.c           - Implémentation version
```

### Fichiers de Build
```
Makefile            - Compilation automatique
```

### Fichiers de Tests
```
test_bool.ml        - Tests du type bool
test_break_continue.ml - Tests break/continue
test_input.ml       - Tests input()
test_functions.ml   - Tests des fonctions
test_factorial.ml   - Factorielle récursive
test_fibonacci_func.ml - Fibonacci récursif
```

### Documentation
```
README.md           - Ce fichier
```

---

## ⚡ Installation Rapide

### 1. Compiler

```bash
make
```

Vous devriez voir :
```
✓ MiniLang v3.2.0 compilé avec succès
  Nouvelles fonctionnalités:
    - Type bool natif (true/false)
    - break et continue dans les boucles
    - input() pour lire l'entrée utilisateur
    - Concaténation de chaînes avec +
    - Print amélioré avec concaténation
```

### 2. Tester

```bash
./minilang --version
```

### 3. Exécuter des tests

```bash
./minilang test_bool.ml
./minilang test_break_continue.ml
./minilang test_functions.ml
```

---

## 🎯 Utilisation

### Commandes de base

```bash
# Exécuter un programme
./minilang programme.ml

# Afficher la version
./minilang --version
./minilang -v

# Afficher l'aide
./minilang --help
./minilang -h
```

### Exemples de Code

#### Hello World
```c
print("Hello, World!");
```

#### Variables et Types
```c
int age = 25;
float prix = 19.99;
str nom = "Alice";
bool actif = true;
```

#### Type Bool
```c
bool estMajeur = true;

if (estMajeur) {
    print("Accès autorisé");
} else {
    print("Accès refusé");
}

func bool estPair(int n) {
    return n % 2 == 0;
}

print(estPair(42));  // true
```

#### Break et Continue
```c
// Break - sortir de la boucle
for (int i = 0; i < 10; i = i + 1) {
    if (i == 5) {
        break;
    }
    print(i);  // 0 1 2 3 4
}

// Continue - passer à l'itération suivante
for (int j = 0; j < 10; j = j + 1) {
    if (j % 2 == 0) {
        continue;
    }
    print(j);  // 1 3 5 7 9
}
```

#### Input - Lecture Utilisateur
```c
str nom = input("Votre nom: ");
print("Bonjour " + nom);

int age = input("Votre âge: ");
print("Vous avez " + age + " ans");
```

#### Concaténation de Chaînes
```c
str prenom = "Alice";
int age = 25;

print("Nom: " + prenom);
print(prenom + " a " + age + " ans");
```

#### Fonctions
```c
func int addition(int a, int b) {
    return a + b;
}

func void saluer(str nom) {
    print("Bonjour " + nom);
}

func bool estPositif(int n) {
    return n > 0;
}

int resultat = addition(5, 3);
saluer("Alice");
bool test = estPositif(42);
```

#### Récursivité
```c
func int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

print(factorial(5));  // 120
```

---

## 🔧 Compilation Manuelle

Si `make` ne fonctionne pas, compilez manuellement :

```bash
# Compiler tous les fichiers
gcc -std=gnu99 -Wall -Wextra -O2 -g -c main.c -o main.o
gcc -std=gnu99 -Wall -Wextra -O2 -g -c lexer.c -o lexer.o
gcc -std=gnu99 -Wall -Wextra -O2 -g -c symbols.c -o symbols.o
gcc -std=gnu99 -Wall -Wextra -O2 -g -c evaluator.c -o evaluator.o
gcc -std=gnu99 -Wall -Wextra -O2 -g -c parser.c -o parser.o
gcc -std=gnu99 -Wall -Wextra -O2 -g -c utils.c -o utils.o
gcc -std=gnu99 -Wall -Wextra -O2 -g -c version.c -o version.o

# Linker
gcc -std=gnu99 -Wall -Wextra -O2 -g main.o lexer.o symbols.o evaluator.o parser.o utils.o version.o -o minilang

# Tester
./minilang --version
```

---

## 📚 Fonctionnalités Complètes

### Types de Données
- `int` - Entiers
- `float` - Nombres à virgule flottante
- `str` - Chaînes de caractères
- `bool` - Booléens (true/false)
- `void` - Sans valeur (pour procédures)
- Tableaux de int et float

### Opérateurs

**Arithmétiques** : `+`, `-`, `*`, `/`, `%`  
**Comparaison** : `==`, `!=`, `<`, `>`, `<=`, `>=`  
**Logiques** : `&&`, `||`, `!`  
**Concaténation** : `+` (pour chaînes)

### Structures de Contrôle
- `if (condition) { ... } else { ... }`
- `while (condition) { ... }`
- `for (init; condition; increment) { ... }`
- `break` - Sortir d'une boucle
- `continue` - Passer à l'itération suivante

### Fonctions
- Déclaration : `func type nom(params) { ... }`
- Return : `return valeur;`
- Récursivité supportée
- Scopes isolés

### Entrées/Sorties
- `print(expression)` - Afficher
- `input("prompt")` - Lire l'entrée utilisateur

### Commentaires
```c
// Commentaire sur une ligne

/* Commentaire
   sur plusieurs
   lignes */
```

---

## 🧪 Tests Disponibles

| Test | Description |
|------|-------------|
| `test_bool.ml` | Type bool natif |
| `test_break_continue.ml` | Contrôle de flux |
| `test_input.ml` | Lecture utilisateur (interactif) |
| `test_functions.ml` | Fonctions de base |
| `test_factorial.ml` | Récursivité (factorielle) |
| `test_fibonacci_func.ml` | Récursivité (Fibonacci) |

```bash
# Exécuter tous les tests (sauf input qui est interactif)
./minilang test_bool.ml
./minilang test_break_continue.ml
./minilang test_functions.ml
./minilang test_factorial.ml
./minilang test_fibonacci_func.ml
```

---

## 🛠️ Commandes Make

```bash
make            # Compiler
make clean      # Nettoyer
make test       # Exécuter tests de base
make install    # Installer dans /usr/local/bin (sudo requis)
make uninstall  # Désinstaller
```

---

## ⚠️ Prérequis

- **GCC** (ou tout compilateur C compatible)
- **Make** (optionnel, pour compilation automatique)
- **Linux** ou **Unix-like** OS

### Installation des prérequis

**Debian/Ubuntu** :
```bash
sudo apt-get update
sudo apt-get install build-essential
```

**Arch Linux** :
```bash
sudo pacman -S base-devel
```

**macOS** :
```bash
xcode-select --install
```

---

## 📊 Statistiques

- **Version** : 3.2.0
- **Fichiers sources** : 9
- **Lignes de code** : ~1900
- **Tests** : 6
- **Date** : 24 Décembre 2025

---

## 🎓 Exemples Avancés

### Programme Interactif Complet

```c
print("=== CALCULATRICE ===");

str nom = input("Votre nom: ");
int a = input("Premier nombre: ");
int b = input("Deuxième nombre: ");

int somme = a + b;
int produit = a * b;

print("Bonjour " + nom);
print(a + " + " + b + " = " + somme);
print(a + " * " + b + " = " + produit);
```

### Recherche avec Break

```c
int nombres[10];
for (int i = 0; i < 10; i = i + 1) {
    nombres[i] = i * 2;
}

int cherche = 12;
bool trouve = false;

for (int i = 0; i < 10; i = i + 1) {
    if (nombres[i] == cherche) {
        print("Trouvé à l'index:");
        print(i);
        trouve = true;
        break;
    }
}

if (!trouve) {
    print("Non trouvé");
}
```

### Validation avec Bool

```c
func bool estValide(int age) {
    return age >= 18 && age <= 120;
}

int age = input("Votre âge: ");

if (estValide(age)) {
    print("Âge valide");
} else {
    print("Âge invalide");
}
```

---

## 🐛 Dépannage

### Erreur: "control_flow undefined"

Vérifiez que `main.c` contient bien (ligne 12) :
```c
ControlFlow control_flow = {false, false};
```

### Erreur: "command not found"

```bash
# Vérifier que make est installé
which make

# Si pas installé
sudo apt-get install make
```

### Warning: "unused variable"

Ce sont des avertissements, pas des erreurs. La compilation continue.

---

## 📜 Licence

MIT License - Libre d'utilisation, modification et distribution.

---

## 👤 Auteur

**Claude** - Interpréteur MiniLang

---

## 🎉 C'est Tout !

**MiniLang v3.2.0 est prêt à l'emploi !**

```bash
# Compiler
make

# Tester
./minilang test_bool.ml

# Créer votre premier programme
echo 'print("Hello MiniLang!");' > hello.ml
./minilang hello.ml
```

**Bon coding ! 🚀**
