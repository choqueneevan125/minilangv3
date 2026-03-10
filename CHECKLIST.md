# 📋 Checklist de Vérification - MiniLang v3.2.0 COMPLET

## ✅ Fichiers Requis (19 fichiers)

### Sources C/H (9 fichiers)
- [ ] minilang.h
- [ ] version.h
- [ ] main.c
- [ ] lexer.c
- [ ] parser.c
- [ ] evaluator.c
- [ ] symbols.c
- [ ] utils.c
- [ ] version.c

### Build (1 fichier)
- [ ] Makefile

### Tests (6 fichiers)
- [ ] test_bool.ml
- [ ] test_break_continue.ml
- [ ] test_input.ml
- [ ] test_functions.ml
- [ ] test_factorial.ml
- [ ] test_fibonacci_func.ml

### Documentation (3 fichiers)
- [ ] README.md
- [ ] INSTALL.txt
- [ ] CHECKLIST.md (ce fichier)

---

## 🔍 Commande de Vérification Rapide

```bash
ls -1 | wc -l
```
**Résultat attendu** : 19 (ou 20 avec hello.ml)

```bash
ls *.c *.h
```
**Résultat attendu** : 9 fichiers .c et 2 fichiers .h

```bash
ls test_*.ml
```
**Résultat attendu** : 6 fichiers de tests

---

## 🧪 Test d'Intégrité

### 1. Compiler
```bash
make
```
**Attendu** : ✓ MiniLang v3.2.0 compilé avec succès

### 2. Version
```bash
./minilang --version
```
**Attendu** : MiniLang v3.2.0

### 3. Aide
```bash
./minilang --help
```
**Attendu** : Affiche l'aide complète

### 4. Tests
```bash
./minilang test_bool.ml
./minilang test_functions.ml
./minilang test_factorial.ml
```
**Attendu** : Tous s'exécutent sans erreur

---

## ✓ Package OK si :

1. ✅ Les 19 fichiers sont présents
2. ✅ `make` compile sans erreur (warnings OK)
3. ✅ `./minilang --version` affiche v3.2.0
4. ✅ Les tests s'exécutent correctement

---

## ❌ Package Incomplet si :

- Moins de 19 fichiers
- Compilation échoue
- Tests crashent

**Solution** : Re-télécharger le package complet

---

## 📦 Taille du Package

**Total** : ~80 KB (sources seulement)
**Avec exécutable compilé** : ~150 KB

---

**Ce package est COMPLET et autonome. Aucun fichier supplémentaire requis !**
