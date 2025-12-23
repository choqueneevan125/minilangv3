# 🎉 MiniLang v3.1.0 - Procédures void + CLI

## 📦 Contenu

### 💻 Code Source (9 fichiers)

**Nouveaux** :
- **version.h** (40 lignes) - Système de versioning
- **version.c** (50 lignes) - CLI --version/--help

**Mis à jour** :
- **minilang.h** (225 lignes) - Support TOKEN_VOID
- **main.c** (70 lignes) - Arguments CLI
- **lexer.c** (175 lignes) - Reconnaissance "void"
- **parser.c** (735 lignes) - Parsing fonctions void

**Inchangés** :
- **evaluator.c** (260 lignes)
- **symbols.c** (140 lignes)
- **utils.c** (30 lignes)

**Total: ~1725 lignes** organisées en 9 fichiers

### 📚 Documentation

- **README_V3.1.md** - Guide complet
  - Procédures void
  - Système de versioning
  - Bonnes pratiques
  - Exemples détaillés

### 🔧 Build

- **Makefile** - Compilation avec version.c

### 🧪 Tests

- **test_void.ml** ✨ NOUVEAU - Tests procédures
- **test_functions.ml** - Fonctions basiques
- **test_factorial.ml** - Factorielle
- **test_fibonacci_func.ml** - Fibonacci
- **test_arithmetic_func.ml** - Bibliothèque math
- **test_scope.ml** - Scopes isolés

---

## ✨ Nouveautés v3.1

### 🎯 Procédures void

Les procédures sont des fonctions sans valeur de retour :

```c
func void afficherMessage() {
    print("Hello!");
}

func void afficherCarre(int x) {
    int carre = x * x;
    print(carre);
}

afficherMessage();
afficherCarre(5);  // Affiche: 25
```

**Caractéristiques** :
- ✅ Type de retour `void`
- ✅ Pas de return nécessaire
- ✅ Idéal pour les actions (affichage, etc.)
- ✅ Même scoping que les fonctions

### 🏷️ Système de Versioning

**Commandes CLI** :

```bash
# Version complète
./minilang --version

MiniLang v3.1.0
Compilé le Dec 23 2025 à 17:23:08
Langage de programmation complet avec fonctions
[...]

# Version courte
./minilang -v

# Aide
./minilang --help
./minilang -h
```

**Fichiers** :
- `version.h` - Macros de version
- `version.c` - Implémentation

---

## 📊 Évolution du Projet

| Version | Fichiers | Lignes | Nouveautés |
|---------|----------|--------|------------|
| v1.0 | 1 | ~500 | Types, arithmétique |
| v2.0 | 1 | ~1500 | Structures, tableaux |
| v3.0 | 7 | ~1600 | Fonctions, modulaire |
| **v3.1** | **9** | **~1725** | **void, versioning, CLI** |

---

## 🚀 Démarrage Rapide

### Installation

```bash
cd v3.1
make
```

### Utilisation

```bash
# Version et aide
./minilang --version
./minilang --help

# Exécuter un programme
./minilang hello.ml

# Tests
make test-void
make test-all
```

### Premier Programme avec void

```c
// hello.ml
func void saluer(str nom) {
    print("Bonjour");
    print(nom);
}

saluer("Monde");
```

```bash
./minilang hello.ml
# Affiche:
# Bonjour
# Monde
```

---

## 🎓 Exemples d'Utilisation

### Affichage Formaté

```c
func void ligne() {
    print("=============");
}

func void titre(str t) {
    ligne();
    print(t);
    ligne();
}

titre("Mon App");
```

### Menu Interactif

```c
func void menu() {
    print("=== MENU ===");
    print("1. Addition");
    print("2. Soustraction");
    print("3. Quitter");
}

menu();
```

### Logging

```c
func void log(str niveau, str msg) {
    print(niveau);
    print(msg);
}

func void info(str m) {
    log("INFO", m);
}

func void error(str m) {
    log("ERROR", m);
}

info("Démarrage");
error("Erreur!");
```

### Validation

```c
func void verifier(int age) {
    if (age < 18) {
        print("Mineur");
    } else {
        print("Majeur");
    }
}

verifier(15);  // Mineur
verifier(25);  // Majeur
```

---

## 📖 Fonctions vs Procédures

| Aspect | Fonction | Procédure |
|--------|----------|-----------|
| **Déclaration** | `func int f()` | `func void p()` |
| **Return** | Obligatoire | Optionnel |
| **Usage** | `x = f();` | `p();` |
| **But** | Calculer | Agir |

### Quand utiliser quoi ?

**Fonction (avec return)** :
- Calculs mathématiques
- Transformations de données
- Tests/vérifications
- Recherche dans tableaux

**Procédure (void)** :
- Affichage
- Logging
- Initialisation
- Menus
- Actions sans résultat

---

## 🔧 Compilation

### Structure Makefile

```makefile
SOURCES = main.c lexer.c symbols.c evaluator.c 
          parser.c utils.c version.c
```

### Commandes

```bash
make           # Compiler
make clean     # Nettoyer
make test-void # Test void
make test-all  # Tous tests
make version   # Afficher version
make help      # Aide make
```

---

## 🎯 Cas d'Usage Réels

### 1. Programme avec Menu

```c
func void menu() {
    print("1. Calculer");
    print("2. Afficher");
    print("3. Quitter");
}

func int calculer(int a, int b) {
    return a + b;
}

func void afficher(int v) {
    print("Résultat:");
    print(v);
}

// Main
menu();
int r = calculer(10, 20);
afficher(r);
```

### 2. Système de Debug

```c
func void debug(str msg, int val) {
    print("DEBUG:");
    print(msg);
    print(val);
}

int x = 42;
debug("x =", x);
```

### 3. Affichage de Tableaux

```c
func void afficher(int t[5]) {
    print("Tableau:");
    for (int i = 0; i < 5; i = i + 1) {
        print(t[i]);
    }
}

int data[5];
data[0] = 10;
data[1] = 20;
// ...
afficher(data);
```

---

## 📝 Changelog

### v3.1.0 (23 Dec 2025)

**Ajouts** :
- ✨ Type `void` pour procédures
- ✨ `--version` / `-v` : Afficher version
- ✨ `--help` / `-h` : Afficher aide
- ✨ `version.h` : Système de versioning
- ✨ `version.c` : Implémentation CLI
- 🧪 `test_void.ml` : Tests complets

**Modifications** :
- ⬆️ `minilang.h` : Support TOKEN_VOID
- ⬆️ `main.c` : Gestion arguments
- ⬆️ `lexer.c` : Reconnaissance "void"
- ⬆️ `parser.c` : Parsing void
- ⬆️ `Makefile` : Compile version.c

**Statistiques** :
- 9 fichiers sources (+2)
- ~1725 lignes (+125)
- 6 fichiers de tests (+1)

---

## 🎉 Avantages v3.1

### Pour le Développeur

✅ **CLI Professionnel**
- Version visible facilement
- Aide intégrée
- Options courtes et longues

✅ **Code Plus Clair**
- Séparation actions/calculs
- Procédures explicites
- Meilleure organisation

✅ **Maintenabilité**
- Version dans le code
- Historique tracé
- Documentation à jour

### Pour l'Utilisateur

✅ **Expressivité**
- `void` = "fait quelque chose"
- Fonction = "calcule quelque chose"
- Plus intuitif

✅ **Flexibilité**
- Procédures utilitaires
- Logging facile
- Menus simples

---

## 🔮 Roadmap

### v3.2 (Prochaine)
- 🔄 Récursivité optimisée
- ⚡ break / continue
- 📚 Tableaux en paramètres

### v3.3
- 🎨 Type bool natif
- 📝 Opérations sur strings
- 🔢 Type char

### v4.0
- 🏗️ Structures / Records
- 📦 Modules / Imports
- 🚀 Optimisations

---

## 💡 Bonnes Pratiques

### ✅ À FAIRE

```c
// Procédure pour afficher
func void afficher(int x) {
    print(x);
}

// Fonction pour calculer
func int doubler(int x) {
    return x * 2;
}

// Usage
int n = doubler(5);
afficher(n);
```

### ❌ À ÉVITER

```c
// Ne mélangez pas calcul et affichage
func void mauvais(int x) {
    int r = x * 2;  // Calcul
    print(r);       // Affichage
    // Responsabilités mélangées
}
```

---

## 📞 Support

### Documentation
- 📖 `README_V3.1.md` - Documentation complète
- 🧪 `test_void.ml` - Exemples de code
- 💻 `./minilang --help` - Aide CLI

### Tests
```bash
make test-void      # Test procédures
make test-all       # Tous les tests
```

### Info
```bash
./minilang --version  # Version
make info             # Info projet
```

---

## 🎊 Félicitations !

Vous avez **MiniLang v3.1.0** avec :

✅ **Procédures void** - Actions sans retour  
✅ **CLI complet** - --version, --help  
✅ **9 modules** organisés  
✅ **~1725 lignes** de code  
✅ **6 fichiers** de tests  
✅ **Versioning** intégré  

**MiniLang est maintenant un langage professionnel !** 🚀

---

**Bon coding avec MiniLang v3.1 !** 💻
