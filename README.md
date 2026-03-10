# 🚀 MiniLang v3.1.0 - Procédures void + Versioning

## 📦 Nouveautés v3.1

### ✨ Procédures void

Les procédures sont des fonctions qui n'ont pas besoin de retourner de valeur.

#### Syntaxe

```c
func void nom_procedure(paramètres) {
    // Code de la procédure
    // Pas de return nécessaire
}
```

#### Exemples

**Procédure simple** :
```c
func void afficherMessage() {
    print("Hello World!");
}

afficherMessage();  // Affiche: Hello World!
```

**Procédure avec paramètres** :
```c
func void afficherCarre(int x) {
    int carre = x * x;
    print("Carré:");
    print(carre);
}

afficherCarre(5);  // Affiche: Carré: 25
```

**Procédure avec condition** :
```c
func void verifierParite(int n) {
    if (n % 2 == 0) {
        print("Pair");
    } else {
        print("Impair");
    }
}

verifierParite(4);  // Affiche: Pair
verifierParite(7);  // Affiche: Impair
```

**Procédure avec boucle** :
```c
func void compterJusqua(int max) {
    for (int i = 1; i <= max; i = i + 1) {
        print(i);
    }
}

compterJusqua(5);  // Affiche: 1 2 3 4 5
```

### 🏷️ Système de Versioning

#### Commande --version

```bash
$ ./minilang --version

MiniLang v3.1.0
Compilé le Dec 23 2025 à 17:23:08

Langage de programmation complet avec fonctions

Fonctionnalités:
  - Types: int, float, str, void, tableaux
  - Opérateurs: arithmétiques, comparaison, logiques
  - Structures: if/else, while, for
  - Fonctions avec paramètres et return
  - Procédures void (sans retour)
  - Scopes isolés
  - Commentaires // et /* */
Auteur: Claude
Licence: MIT
```

#### Commande --help

```bash
$ ./minilang --help

MiniLang v3.1.0 - Langage de programmation complet avec fonctions

Usage:
  minilang <fichier.ml>         Exécuter un programme
  minilang --version            Afficher la version
  minilang --help               Afficher cette aide
  minilang -v                   Afficher la version (court)
  minilang -h                   Afficher cette aide (court)

Exemples:
  minilang hello.ml             Exécuter hello.ml
  minilang test.ml              Exécuter test.ml

[...]
```

---

## 📖 Guide Complet

### Fonctions vs Procédures

| Aspect | Fonction | Procédure |
|--------|----------|-----------|
| Type retour | `int`, `float`, `str` | `void` |
| Return | **Obligatoire** | Optionnel |
| Usage | `int x = func();` | `proc();` |
| Objectif | Calculer et retourner | Effectuer une action |

### Exemples Pratiques

#### Affichage formaté

```c
func void afficherLigne() {
    print("===================");
}

func void afficherTitre(str titre) {
    afficherLigne();
    print(titre);
    afficherLigne();
}

afficherTitre("Mon Programme");
```

#### Menu interactif

```c
func void afficherMenu() {
    print("=== MENU ===");
    print("1. Option 1");
    print("2. Option 2");
    print("3. Quitter");
}

afficherMenu();
```

#### Validation de données

```c
func void validerAge(int age) {
    if (age < 0) {
        print("Erreur: âge négatif");
    } else {
        if (age < 18) {
            print("Mineur");
        } else {
            print("Majeur");
        }
    }
}

validerAge(15);  // Mineur
validerAge(25);  // Majeur
```

#### Traitement de tableaux

```c
func void afficherTableau(int taille) {
    int arr[10];
    
    // Remplir
    for (int i = 0; i < taille; i = i + 1) {
        arr[i] = i * i;
    }
    
    // Afficher
    print("Tableau des carrés:");
    for (int i = 0; i < taille; i = i + 1) {
        print(arr[i]);
    }
}

afficherTableau(5);
```

---

## 🎯 Cas d'Usage

### Quand utiliser void ?

✅ **Utiliser void quand** :
- Affichage de données
- Mise à jour de l'état
- Actions sans résultat calculé
- Procédures d'initialisation
- Affichage de menus
- Logging / Debug

❌ **Ne pas utiliser void quand** :
- Besoin d'un résultat
- Calculs mathématiques
- Transformations de données
- Vérifications retournant vrai/faux

### Exemples de Bonnes Pratiques

#### ✅ BON : Séparation claire

```c
// Fonction qui calcule
func int calculerSomme(int a, int b) {
    return a + b;
}

// Procédure qui affiche
func void afficherSomme(int a, int b) {
    int s = calculerSomme(a, b);
    print("Somme:");
    print(s);
}

afficherSomme(10, 20);
```

#### ✅ BON : Procédures utilitaires

```c
func void debug(str message, int valeur) {
    print("DEBUG:");
    print(message);
    print(valeur);
}

int x = 42;
debug("Valeur de x", x);
```

#### ❌ ÉVITER : Mélanger les responsabilités

```c
// Pas clair si ça calcule ou affiche
func void traiterNombre(int n) {
    int r = n * 2;
    print(r);
    // Fait-on un calcul ou un affichage ?
}
```

---

## 🔧 Compilation et Utilisation

### Compiler

```bash
cd v3.1
make
```

### Utiliser

```bash
# Exécuter un programme
./minilang mon_programme.ml

# Afficher la version
./minilang --version
./minilang -v

# Afficher l'aide
./minilang --help
./minilang -h
```

### Tester

```bash
make test-void          # Test procédures void
make test-all           # Tous les tests
```

---

## 📊 Architecture v3.1

### Fichiers

```
v3.1/
├── version.h           # ✨ NOUVEAU - Définitions version
├── version.c           # ✨ NOUVEAU - Implémentation CLI
├── minilang.h          # ⬆️ MAJ - Support TOKEN_VOID
├── main.c              # ⬆️ MAJ - Gestion arguments CLI
├── lexer.c             # ⬆️ MAJ - Reconnaissance "void"
├── parser.c            # ⬆️ MAJ - Parsing fonctions void
├── evaluator.c         # Inchangé
├── symbols.c           # Inchangé
├── utils.c             # Inchangé
├── Makefile            # ⬆️ MAJ - Compilation version.c
└── test_void.ml        # ✨ NOUVEAU - Tests void
```

### Nouveaux Modules

#### version.h / version.c

Gère les informations de version :
- `MINILANG_VERSION` - Numéro de version
- `MINILANG_BUILD_DATE` - Date de compilation
- `print_version()` - Affiche la version
- `print_help()` - Affiche l'aide

---

## 🎓 Exemples Complets

### Programme avec Menu

```c
func void afficherMenu() {
    print("=== CALCULATRICE ===");
    print("1. Addition");
    print("2. Soustraction");
    print("3. Multiplication");
    print("4. Division");
}

func int addition(int a, int b) {
    return a + b;
}

func int soustraction(int a, int b) {
    return a - b;
}

func void demo() {
    afficherMenu();
    
    int a = 10;
    int b = 5;
    
    print("Résultats pour a=10, b=5:");
    print(addition(a, b));
    print(soustraction(a, b));
}

demo();
```

### Système de Logging

```c
func void log(str niveau, str message) {
    print("===================");
    print(niveau);
    print(message);
    print("===================");
}

func void info(str msg) {
    log("INFO", msg);
}

func void error(str msg) {
    log("ERROR", msg);
}

info("Démarrage du programme");
error("Une erreur est survenue");
```

### Affichage de Statistiques

```c
func int somme(int arr[5]) {
    int s = 0;
    for (int i = 0; i < 5; i = i + 1) {
        s = s + arr[i];
    }
    return s;
}

func void afficherStats(int taille) {
    int data[5];
    data[0] = 10;
    data[1] = 20;
    data[2] = 30;
    data[3] = 40;
    data[4] = 50;
    
    print("=== STATISTIQUES ===");
    print("Données:");
    for (int i = 0; i < taille; i = i + 1) {
        print(data[i]);
    }
    
    int total = somme(data);
    print("Total:");
    print(total);
    
    int moyenne = total / taille;
    print("Moyenne:");
    print(moyenne);
}

afficherStats(5);
```

---

## 📝 Changelog Détaillé

### v3.1.0 (23 Décembre 2025)

**Nouvelles Fonctionnalités** :
- ✨ Support des procédures `void`
- ✨ Système de versioning avec `version.h`
- ✨ CLI avec `--version` et `--help`
- ✨ Options courtes `-v` et `-h`

**Améliorations** :
- 📝 Documentation étendue pour void
- 🧪 Tests complets des procédures
- 📖 Guide des bonnes pratiques
- 🏷️ Affichage de la date de compilation

**Corrections** :
- 🐛 Aucune correction (pas de bugs connus)

### v3.0.0
- ✨ Fonctions avec paramètres et return
- ✨ Architecture modulaire (7 fichiers)
- ✨ Scopes isolés

### v2.0.0
- ✨ Structures de contrôle
- ✨ Tableaux
- ✨ Commentaires

### v1.0.0
- ✨ Version initiale

---

## 🎉 Félicitations !

Vous disposez maintenant de **MiniLang v3.1.0** avec :

✅ **Procédures void** - Actions sans retour  
✅ **Versioning** - Système de version intégré  
✅ **CLI professionnel** - --version et --help  
✅ **9 modules** bien organisés  
✅ **Documentation complète**  

**MiniLang continue d'évoluer vers un langage complet !** 🚀

---

## 📞 Commandes Utiles

```bash
# Développement
make                    # Compiler
make clean              # Nettoyer
make info              # Infos du projet

# Utilisation
./minilang prog.ml     # Exécuter
./minilang --version   # Version
./minilang --help      # Aide

# Tests
make test-void         # Test void
make test-all          # Tous les tests
```

---

## 🔮 Prochaines Étapes

Pour la **v3.2** et au-delà :
- 🔄 **Récursivité complète**
- 📚 **Tableaux en paramètres**
- ⚡ **break et continue**
- 🎨 **Type bool natif**
- 📝 **Manipulation de chaînes**
- 🚀 **Optimisations**

---

**Bon coding avec MiniLang v3.1 !** 💻
