# 🧪 Guide de Tests MiniLang

## Lancer Tous les Tests

```bash
./run_tests.sh
```

## Options

```bash
./run_tests.sh --verbose    # Afficher plus de détails
./run_tests.sh -v           # Version courte
```

## Organisation des Tests

Les tests sont organisés dans le dossier `tests/` par catégorie :

### 1. Tests Basiques (`test_basic_*.ml`)
- Hello World
- Variables (int, float, str, bool)
- Arithmétique
- if/else
- Boucles
- Fonctions

### 2. Tests Critiques (`test_critical_*.ml`)
- Validation des bornes
- Sécurité des tableaux
- Types incompatibles
- Division par zéro
- Et plus...

### 3. Tests de Chaînes (`test_str*.ml`, `test_string*.ml`)
- Tableaux de chaînes
- Opérations .length et .substring
- Concaténation
- Opérateur +=

### 4. Tests de Tableaux (`test_array*.ml`)
- Tableaux en paramètres
- Passage par référence
- Opérateurs composés
- Validation des types

### 5. Démos (`demo_*.ml`)
- Démonstrations complètes
- Exemples d'utilisation

## Ajouter un Nouveau Test

1. Créer un fichier dans `tests/` :
```bash
nano tests/mon_test.ml
```

2. Écrire le code de test

3. Lancer les tests :
```bash
./run_tests.sh
```

Le script détecte automatiquement tous les fichiers `*.ml` dans `tests/`

## Tests qui Doivent Échouer

Les tests dont le nom contient :
- `error`
- `invalid`
- `wrong`
- Ou qui testent des erreurs connues (ex: `test_critical_31.ml` pour taille négative)

Sont automatiquement considérés comme devant échouer.

## Résultat Attendu

```
Total:   88 tests
Réussis: 77
Échoués: 11

Taux de réussite: 87%
```

Les 11 échecs sont **normaux** :
- 6 tests de division/modulo par zéro (arrêt attendu)
- 5 tests avec input() ou boucles infinies (timeout normal)

## Codes de Sortie

- `0` : Tous les tests passent (100%)
- `1` : Quelques tests échouent (< 100%)

## Exemples de Tests

### Test Simple
```c
// tests/test_hello.ml
print("Hello World");
```

### Test avec Validation
```c
// tests/test_invalid_size.ml
int tab[-5];  // Doit échouer
```

### Test de Fonctionnalité
```c
// tests/test_concat.ml
str msg = "Hello";
msg += " World";
print(msg);  // Doit afficher "Hello World"
```

## Déboguer un Test qui Échoue

```bash
# Exécuter un test manuellement
./minilang tests/mon_test.ml

# Avec verbose pour voir les détails
./run_tests.sh --verbose
```

## Performance

Le script utilise un timeout de 3 secondes par test pour éviter les blocages.

Tests longs ? Augmentez le timeout dans `run_tests.sh` :
```bash
timeout 10 ./minilang "$test_file"  # Au lieu de 3
```
