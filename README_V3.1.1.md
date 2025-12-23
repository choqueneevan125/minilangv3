# 🐛 MiniLang v3.1.1 - Correctif Critique

## ⚠️ Bug Corrigé

### Problème
**Segmentation Fault** lors de l'utilisation de paramètres `str` dans les fonctions.

### Exemple du bug (v3.1.0)
```c
func void saluer(str nom) {
    print("Bonjour");
    print(nom);  // ❌ Segfault ici
}

saluer("Monde");  // ❌ Crash
```

### Cause
Deux problèmes dans le code :

1. **evaluator.c** : Les chaînes littérales (`TOKEN_STRING`) n'étaient pas gérées dans `parse_factor()`
2. **parser.c** : Les paramètres de type `str` n'étaient pas copiés lors de l'appel de fonction

### Solution
```c
// evaluator.c - Ajout de la gestion des chaînes littérales
if (token.type == TOKEN_STRING) {
    result.type = VAR_STRING;
    result.value.str_val = token.value;
    current_token++;
    return result;
}

// parser.c - Copie des chaînes pour les paramètres
} else if (param->type == VAR_STRING) {
    if (arg_value.type == VAR_STRING && arg_value.value.str_val != NULL) {
        var->value.str_val = strdup(arg_value.value.str_val);
    } else {
        var->value.str_val = NULL;
    }
}
```

---

## ✅ Tests de Validation

### Test 1 : Fonction simple avec string

```c
func void saluer(str nom) {
    print("Bonjour");
    print(nom);
}

saluer("Monde");
saluer("Alice");
```

**Résultat** :
```
Bonjour
Monde
Bonjour
Alice
```

✅ **Fonctionne correctement**

### Test 2 : Fonction avec plusieurs paramètres string

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

**Résultat** :
```
===================
INFO
Démarrage du programme
===================
===================
ERROR
Une erreur est survenue
===================
```

✅ **Fonctionne correctement**

---

## 📦 Changelog v3.1.1

### 🐛 Corrections
- **CRITIQUE** : Correction du segfault avec les paramètres `str`
  - Ajout de la gestion des `TOKEN_STRING` dans `parse_factor()`
  - Copie correcte des chaînes dans les paramètres de fonction

### 📝 Fichiers Modifiés
- `evaluator.c` : +7 lignes (gestion TOKEN_STRING)
- `parser.c` : +8 lignes (copie paramètres string)
- `version.h` : Version 3.1.0 → 3.1.1

### 🧪 Nouveaux Tests
- `test_string_bug1.ml` : Test fonction avec 1 paramètre str
- `test_string_bug2.ml` : Test fonction avec 2 paramètres str

---

## 🚀 Utilisation

### Installation

```bash
cd v3.1.1
make clean
make
```

### Vérification de la version

```bash
./minilang --version
# MiniLang v3.1.1
```

### Test du correctif

```bash
./minilang test_string_bug1.ml
./minilang test_string_bug2.ml
```

---

## 📊 Impact

### Avant (v3.1.0)
```bash
$ ./minilang test.ml
===================
Erreur de segmentation (core dumped)
```
❌ **Crash immédiat**

### Après (v3.1.1)
```bash
$ ./minilang test.ml
===================
INFO
Démarrage du programme
===================
```
✅ **Fonctionne parfaitement**

---

## 🎯 Fonctionnalités Complètes

Toutes les fonctionnalités de v3.1.0 sont conservées :

✅ Type `void` pour procédures  
✅ Fonctions avec paramètres et return  
✅ **Paramètres `str` maintenant fonctionnels**  
✅ Scopes isolés  
✅ CLI avec --version et --help  
✅ Architecture modulaire  

---

## 📖 Exemples Fonctionnels

### Logger Simple

```c
func void log(str msg) {
    print("[LOG]");
    print(msg);
}

log("Application démarrée");
log("Traitement en cours");
log("Application terminée");
```

### Affichage Formaté

```c
func void titre(str t) {
    print("============");
    print(t);
    print("============");
}

titre("Mon Programme");
titre("Section 1");
titre("Section 2");
```

### Menu avec Texte

```c
func void afficherOption(str num, str desc) {
    print(num);
    print(desc);
}

func void menu() {
    print("=== MENU ===");
    afficherOption("1.", "Démarrer");
    afficherOption("2.", "Configurer");
    afficherOption("3.", "Quitter");
}

menu();
```

---

## ⚡ Migration depuis v3.1.0

Si vous utilisez v3.1.0, **mettez à jour immédiatement** vers v3.1.1.

### Aucun changement de code nécessaire

Votre code existant continuera de fonctionner. En fait, le code qui crashait avant fonctionnera maintenant !

### Recompilation

```bash
cd v3.1.1
make clean
make
```

---

## 🔍 Détails Techniques

### Fichier evaluator.c

**Avant** :
```c
// parse_factor() ne gérait pas TOKEN_STRING
// Les chaînes littérales causaient un retour par défaut (0)
```

**Après** :
```c
// Chaîne littérale
if (token.type == TOKEN_STRING) {
    result.type = VAR_STRING;
    result.value.str_val = token.value;
    current_token++;
    return result;
}
```

### Fichier parser.c

**Avant** :
```c
if (var != NULL) {
    if (param->type == VAR_INT) { ... }
    else if (param->type == VAR_FLOAT) { ... }
    // VAR_STRING pas géré !
}
```

**Après** :
```c
if (var != NULL) {
    if (param->type == VAR_INT) { ... }
    else if (param->type == VAR_FLOAT) { ... }
    else if (param->type == VAR_STRING) {
        if (arg_value.type == VAR_STRING && arg_value.value.str_val != NULL) {
            var->value.str_val = strdup(arg_value.value.str_val);
        } else {
            var->value.str_val = NULL;
        }
    }
}
```

---

## 📝 Notes de Version

### v3.1.1 (23 Décembre 2025)
- 🐛 **CORRECTIF CRITIQUE** : Paramètres `str` fonctionnels
- 🧪 Ajout de tests de régression
- ✅ Validation complète

### v3.1.0 (23 Décembre 2025)
- ✨ Support `void`
- 🏷️ Système de versioning
- ⚠️ **Bug** : Paramètres `str` causent un segfault

### v3.0.0
- ✨ Fonctions avec paramètres
- 🏗️ Architecture modulaire

---

## 🎉 Recommandation

**Utilisez v3.1.1 au lieu de v3.1.0**

Cette version corrige un bug critique qui empêchait l'utilisation normale des paramètres de type `str` dans les fonctions.

---

## 📞 Support

### Tests
```bash
make test-all           # Tous les tests
./minilang test_string_bug1.ml
./minilang test_string_bug2.ml
```

### Aide
```bash
./minilang --version    # Vérifier la version
./minilang --help       # Aide
```

---

**MiniLang v3.1.1 est maintenant stable et prêt pour la production !** ✅
