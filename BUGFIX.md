# 🐛 BUGFIX v3.1.1 - Segmentation Fault avec paramètres string

## Rapport de Bug

### Symptômes
- **Erreur** : Segmentation Fault (core dumped)
- **Quand** : Lors de l'appel de fonction avec paramètres `str`
- **Versions affectées** : v3.1.0
- **Sévérité** : 🔴 CRITIQUE

### Reproduction

```c
func void saluer(str nom) {
    print("Bonjour");
    print(nom);
}

saluer("Monde");
```

**Résultat v3.1.0** :
```
Bonjour
Erreur de segmentation (core dumped)
```

---

## Analyse du Bug

### Trace d'Exécution

1. Appel de `saluer("Monde")`
2. Entrée dans `call_function()`
3. Évaluation de l'argument `"Monde"` avec `evaluate_logical()`
4. Dans `parse_factor()` : TOKEN_STRING rencontré
5. ❌ **Aucune gestion du TOKEN_STRING**
6. Retour d'un ExprResult par défaut (type=VAR_INT, value=0)
7. Dans `call_function()` : Tentative d'assigner le paramètre
8. ❌ **VAR_STRING non géré dans l'assignation**
9. Le pointeur `str_val` reste non initialisé ou invalide
10. Dans `print(nom)` : Tentative d'accès au pointeur invalide
11. 💥 **SEGFAULT**

### Code Problématique

#### evaluator.c (ligne ~44)
```c
// parse_factor() - AVANT
ExprResult parse_factor() {
    // ...
    
    // Nombre
    if (token.type == TOKEN_NUMBER) {
        // ...
    }
    
    // ❌ MANQUE: Gestion de TOKEN_STRING
    
    // Variable ou appel de fonction
    if (token.type == TOKEN_IDENTIFIER) {
        // ...
    }
    
    return result;  // Retourne {type:VAR_INT, value:0}
}
```

#### parser.c (ligne ~44)
```c
// call_function() - AVANT
if (var != NULL) {
    if (param->type == VAR_INT) {
        var->value.int_val = ...;
    } else if (param->type == VAR_FLOAT) {
        var->value.float_val = ...;
    }
    // ❌ MANQUE: Gestion de VAR_STRING
}
// var->value.str_val reste non initialisé !
```

---

## Solution Implémentée

### Correction 1 : evaluator.c

**Ajout de la gestion des TOKEN_STRING dans parse_factor()**

```c
// parse_factor() - APRÈS
ExprResult parse_factor() {
    // ...
    
    // Nombre
    if (token.type == TOKEN_NUMBER) {
        // ...
    }
    
    // ✅ AJOUTÉ: Chaîne littérale
    if (token.type == TOKEN_STRING) {
        result.type = VAR_STRING;
        result.value.str_val = token.value;  // Pointer vers le token
        current_token++;
        return result;
    }
    
    // Variable ou appel de fonction
    if (token.type == TOKEN_IDENTIFIER) {
        // ...
    }
    
    return result;
}
```

**Lignes ajoutées** : 7
**Position** : Après ligne 53

### Correction 2 : parser.c

**Ajout de la gestion des paramètres VAR_STRING**

```c
// call_function() - APRÈS
if (var != NULL) {
    if (param->type == VAR_INT) {
        var->value.int_val = (arg_value.type == VAR_FLOAT) ? 
            (int)arg_value.value.float_val : arg_value.value.int_val;
    } else if (param->type == VAR_FLOAT) {
        var->value.float_val = (arg_value.type == VAR_INT) ? 
            (float)arg_value.value.int_val : arg_value.value.float_val;
    } else if (param->type == VAR_STRING) {
        // ✅ AJOUTÉ: Copier la chaîne pour les paramètres string
        if (arg_value.type == VAR_STRING && arg_value.value.str_val != NULL) {
            var->value.str_val = strdup(arg_value.value.str_val);
        } else {
            var->value.str_val = NULL;
        }
    }
}
```

**Lignes ajoutées** : 8
**Position** : Après ligne 51

---

## Tests de Validation

### Test 1 : Cas Simple

**Code** :
```c
func void saluer(str nom) {
    print("Bonjour");
    print(nom);
}

saluer("Monde");
```

**v3.1.0** : ❌ Segfault
**v3.1.1** : ✅ Fonctionne
```
Bonjour
Monde
```

### Test 2 : Paramètres Multiples

**Code** :
```c
func void log(str niveau, str message) {
    print(niveau);
    print(message);
}

log("INFO", "Démarrage");
log("ERROR", "Erreur");
```

**v3.1.0** : ❌ Segfault
**v3.1.1** : ✅ Fonctionne
```
INFO
Démarrage
ERROR
Erreur
```

### Test 3 : Appels Imbriqués

**Code** :
```c
func void log(str n, str m) {
    print(n);
    print(m);
}

func void info(str msg) {
    log("INFO", msg);
}

info("Test");
```

**v3.1.0** : ❌ Segfault
**v3.1.1** : ✅ Fonctionne
```
INFO
Test
```

---

## Validation Complète

### Tests Unitaires

| Test | Description | v3.1.0 | v3.1.1 |
|------|-------------|--------|--------|
| test_string_bug1.ml | 1 param str | ❌ Crash | ✅ OK |
| test_string_bug2.ml | 2 params str | ❌ Crash | ✅ OK |
| test_void.ml | Procédures void | ⚠️ Partiel | ✅ OK |
| test_functions.ml | Fonctions int/float | ✅ OK | ✅ OK |

### Tests de Régression

Tous les tests existants continuent de fonctionner :
- ✅ test_factorial.ml
- ✅ test_fibonacci_func.ml
- ✅ test_arithmetic_func.ml
- ✅ test_scope.ml

**Aucune régression détectée**

---

## Impact sur les Utilisateurs

### Utilisateurs de v3.1.0

**CRITIQUE** : Mettez à jour immédiatement vers v3.1.1

Le code suivant crashait en v3.1.0 :
```c
func void message(str txt) {
    print(txt);
}
message("Hello");  // ❌ Crash v3.1.0
```

Fonctionne parfaitement en v3.1.1 :
```c
message("Hello");  // ✅ OK v3.1.1
```

### Migration

**Aucun changement de code requis**

Recompilez simplement avec v3.1.1 :
```bash
cd v3.1.1
make clean
make
```

---

## Leçons Apprises

### 1. Couverture de Tests Incomplète

**Problème** : Les tests de v3.1.0 n'incluaient pas de cas avec paramètres `str`

**Solution** : Ajout de tests spécifiques :
- `test_string_bug1.ml`
- `test_string_bug2.ml`

### 2. Gestion Incomplète des Types

**Problème** : Nouveaux types ajoutés sans vérification exhaustive

**Solution** : Checklist pour chaque nouveau type :
- [ ] Lexer (reconnaissance)
- [ ] Parser (déclaration)
- [ ] Evaluator (expressions)
- [ ] Symboles (stockage)
- [ ] Tests (validation)

### 3. Importance du strdup()

**Problème** : Pointeurs partagés entre tokens et variables

**Solution** : Toujours copier les chaînes avec `strdup()` pour éviter les références invalides

---

## Checklist de Validation

Pour chaque type de données :

### Type INT
- [x] Lexer : TOKEN_NUMBER
- [x] Parser : Déclaration, assignation
- [x] Evaluator : Arithmétique, comparaison
- [x] Fonction : Paramètre, retour
- [x] Tests : Complets

### Type FLOAT
- [x] Lexer : TOKEN_NUMBER avec '.'
- [x] Parser : Déclaration, assignation
- [x] Evaluator : Arithmétique, conversion
- [x] Fonction : Paramètre, retour
- [x] Tests : Complets

### Type STRING (CORRIGÉ)
- [x] Lexer : TOKEN_STRING
- [x] Parser : Déclaration, assignation
- [x] Evaluator : **✅ CORRIGÉ dans parse_factor()**
- [x] Fonction : **✅ CORRIGÉ paramètres**
- [x] Tests : **✅ AJOUTÉS**

### Type VOID
- [x] Lexer : TOKEN_VOID
- [x] Parser : Déclaration fonction
- [x] Evaluator : N/A
- [x] Fonction : Type retour
- [x] Tests : Complets

---

## Prévention Future

### Tests Automatisés

Ajout d'un test de non-régression :
```bash
#!/bin/bash
# test_no_segfault.sh

./minilang test_string_bug1.ml > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "FAIL: Segfault détecté"
    exit 1
fi

echo "PASS: Aucun segfault"
```

### CI/CD (Future)

1. Compilation
2. Tests unitaires
3. Tests d'intégration
4. Vérification valgrind
5. Tests de non-crash

---

## Statistiques

### Lignes Modifiées
- **evaluator.c** : +7 lignes
- **parser.c** : +8 lignes
- **version.h** : 2 lignes modifiées
- **TOTAL** : 17 lignes

### Temps de Correction
- Identification : ~5 minutes
- Correction : ~10 minutes
- Tests : ~15 minutes
- Documentation : ~30 minutes
- **TOTAL** : ~1 heure

### Impact
- **Sévérité** : 🔴 CRITIQUE
- **Utilisateurs affectés** : Tous ceux utilisant str en paramètres
- **Workaround v3.1.0** : Aucun (impossible d'utiliser str)
- **Correction v3.1.1** : ✅ Complète

---

## Conclusion

Le bug était causé par une **gestion incomplète du type STRING** lors de l'ajout des fonctions en v3.0.

La correction est **simple** mais **essentielle** :
1. Gérer TOKEN_STRING dans l'évaluateur
2. Copier les chaînes pour les paramètres

**v3.1.1 est maintenant stable et recommandée pour tous les utilisateurs.**

---

**Rapport de bug : Clôturé** ✅
**Version corrigée : v3.1.1**
**Date : 23 Décembre 2025**
