# 🚀 MiniLang v3.5.0 - TABLEAUX EN RETOUR DE FONCTION

**Fonctionnalité Majeure Roadmap !**

---

## ✨ NOUVELLE FONCTIONNALITÉ v3.5.0

### Tableaux en Retour de Fonction

Les fonctions peuvent maintenant **retourner des tableaux** !

```c
func int[] creer_nombres() {
    int tab[3];
    tab[0] = 10;
    tab[1] = 20;
    tab[2] = 30;
    return tab;
}

int[] resultat = creer_nombres();
print(resultat[0]);  // 10
print(resultat[1]);  // 20
print(resultat[2]);  // 30
```

---

## 🎯 SYNTAXE

### Déclaration de Fonction

```c
func int[] ma_fonction() {
    // ...
    return tableau;
}

func float[] autre_fonction() {
    // ...
    return tableau_float;
}

func str[] derniere_fonction() {
    // ...
    return tableau_string;
}
```

### Affectation du Résultat

```c
int[] resultat = ma_fonction();
float[] notes = autre_fonction();
str[] noms = derniere_fonction();
```

---

## 📚 EXEMPLES COMPLETS

### Exemple 1 : Créer des Nombres

```c
func int[] generer_suite(int debut, int fin) {
    int tab[10];
    int index = 0;
    
    for (int i = debut; i <= fin; i += 1) {
        tab[index] = i;
        index += 1;
    }
    
    return tab;
}

int[] nombres = generer_suite(1, 10);

for (int i = 0; i < 10; i += 1) {
    print(nombres[i]);
}
```

### Exemple 2 : Suite de Fibonacci

```c
func int[] fibonacci(int n) {
    int fib[10];
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < n; i += 1) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib;
}

int[] suite = fibonacci(10);
print("Fibonacci:");
for (int i = 0; i < 10; i += 1) {
    print(suite[i]);
}
```

**Sortie :**
```
Fibonacci:
0
1
1
2
3
5
8
13
21
34
```

### Exemple 3 : Notes d'Élèves

```c
func float[] calculer_moyennes() {
    float moyennes[3];
    moyennes[0] = 15.5;
    moyennes[1] = 17.2;
    moyennes[2] = 14.8;
    return moyennes;
}

float[] notes = calculer_moyennes();

print("Moyennes de classe:");
for (int i = 0; i < 3; i += 1) {
    print(notes[i]);
}
```

### Exemple 4 : Liste de Noms

```c
func str[] obtenir_equipe() {
    str equipe[4];
    equipe[0] = "Alice";
    equipe[1] = "Bob";
    equipe[2] = "Charlie";
    equipe[3] = "Diana";
    return equipe;
}

str[] membres = obtenir_equipe();

print("Membres de l'equipe:");
for (int i = 0; i < 4; i += 1) {
    print(membres[i]);
}
```

---

## 🔧 GESTION MÉMOIRE

### Comment ça Marche ?

Quand une fonction retourne un tableau :
1. Le tableau est **copié** dans la variable de destination
2. La mémoire est gérée automatiquement
3. Pas de fuites mémoire !

### Types Supportés

- ✅ `int[]` - Tableaux d'entiers
- ✅ `float[]` - Tableaux de flottants
- ✅ `str[]` - Tableaux de chaînes

---

## 📊 COMPARAISON

### Avant v3.5.0 ❌

```c
// IMPOSSIBLE !
func int[] creer() {
    int tab[3];
    return tab;  // ❌ Erreur
}
```

### Avec v3.5.0 ✅

```c
// FONCTIONNE !
func int[] creer() {
    int tab[3];
    tab[0] = 10;
    return tab;  // ✅ OK
}

int[] resultat = creer();
print(resultat[0]);  // 10
```

---

## 🎓 CAS D'USAGE

### 1. Générateurs de Données

```c
func int[] generer_aleatoire(int taille) {
    int donnees[10];
    // ... générer données
    return donnees;
}
```

### 2. Transformations

```c
func float[] convertir_celsius_fahrenheit(float[] celsius, int n) {
    float fahrenheit[10];
    for (int i = 0; i < n; i += 1) {
        fahrenheit[i] = celsius[i] * 9.0 / 5.0 + 32.0;
    }
    return fahrenheit;
}
```

### 3. Filtres

```c
func int[] filtrer_pairs(int[] nombres, int n) {
    int pairs[10];
    int index = 0;
    
    for (int i = 0; i < n; i += 1) {
        if (nombres[i] % 2 == 0) {
            pairs[index] = nombres[i];
            index += 1;
        }
    }
    
    return pairs;
}
```

---

## ⚙️ FONCTIONNALITÉS COMPLÈTES v3.5.0

### Types

- ✅ int, float, str, bool, void
- ✅ Tableaux : int[], float[], str[]
- ✅ **Tableaux en retour de fonction** ⭐

### Fonctions

- ✅ Paramètres multiples
- ✅ Récursivité
- ✅ Tableaux en paramètres
- ✅ **Tableaux en retour** ⭐
- ✅ Type void

### Opérateurs

- ✅ Arithmétiques : +, -, *, /, %
- ✅ Composés : +=, -=, *=, /=
- ✅ Comparaison : ==, !=, <, >, <=, >=
- ✅ Logiques : &&, ||, !

### Chaînes

- ✅ Type str et str[]
- ✅ .length
- ✅ .substring(start, end)
- ✅ Concaténation + et +=

### Sécurité

- ✅ Validation stricte
- ✅ Messages d'erreur clairs
- ✅ Protection contre débordements

---

## 🧪 TESTS

Tous les tests passent :

```bash
make test
```

4 nouveaux tests pour tableaux en retour :
- ✅ test_array_return_01.ml (int[])
- ✅ test_array_return_02.ml (float[])
- ✅ test_array_return_03.ml (str[])
- ✅ test_array_return_04.ml (Fibonacci)

---

## 🚀 INSTALLATION

```bash
make
./minilang --version  # v3.5.0
```

---

## 📈 ÉVOLUTION

| Version | Fonctionnalité |
|---------|----------------|
| v3.4.2 | Corrections bugs |
| v3.4.1 | Type tableau vérifié |
| v3.4.0 | str[], .length, .substring |
| **v3.5.0** | **Tableaux en retour** ⭐ |

---

## 🎯 ROADMAP

✅ Tableaux en retour de fonction ← **FAIT !**
🔄 Structures (struct)
🔄 Tableaux dynamiques
🔄 Import de fichiers

---

**MiniLang v3.5.0 - Fonctionnalité Roadmap Complétée !** 🎉
