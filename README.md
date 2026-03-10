# 🚀 MiniLang v3.2.1 - CORRECTIF input()

## ✅ Correctif Principal

**input() FONCTIONNE MAINTENANT !** 🎉

La v3.2.1 corrige le bug majeur de la v3.2.0 où input() ne fonctionnait pas.

---

## 🚀 Installation

```bash
make
./minilang --version
```

---

## ✨ Utilisation de input()

### Exemples Simples

```c
str nom = input("Votre nom: ");
int age = input("Votre age: ");
float prix = input("Prix: ");
bool actif = input("Actif (true/false): ");
```

### Programme Complet

```c
print("=== CALCULATRICE ===");

str nom = input("Votre nom: ");
print("Bonjour");
print(nom);

int a = input("Premier nombre: ");
int b = input("Deuxieme nombre: ");

int somme = a + b;
print("Somme:");
print(somme);
```

---

## ✅ Fonctionnalités

- ✅ input() fonctionnel avec conversion auto
- ✅ Type bool (true/false)
- ✅ break et continue
- ✅ Fonctions récursives
- ✅ Tableaux
- ✅ Toutes structures de contrôle

---

## 📦 Tests

```bash
./minilang test_input_simple.ml
./minilang test_bool.ml
./minilang test_functions.ml
```

---

**v3.2.1 - input() fonctionne enfin ! ✨**
