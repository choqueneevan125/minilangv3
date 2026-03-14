# 🚀 MiniLang v3.4.0 - NOUVELLES FONCTIONNALITÉS MAJEURES

**3 Fonctionnalités Avancées** ✅

---

## ✨ NOUVEAUTÉS v3.4.0

### 1️⃣ Tableaux de Chaînes (str[])

```c
str noms[3];
noms[0] = "Alice";
noms[1] = "Bob";
noms[2] = "Charlie";

for (int i = 0; i < 3; i += 1) {
    print(noms[i]);
}
```

### 2️⃣ Opérations sur Chaînes

**`.length` - Longueur d'une chaîne**
```c
str texte = "Bonjour";
int longueur = texte.length;  // 7
print(longueur);
```

**`.substring(start, end)` - Extraction**
```c
str message = "Hello World";
str debut = message.substring(0, 5);   // "Hello"
str fin = message.substring(6, 11);    // "World"
```

### 3️⃣ Tableaux en Paramètres de Fonction

**Passage par référence !**

```c
// Fonction qui modifie le tableau (passage par référence)
func void doubler(int tab[], int taille) {
    for (int i = 0; i < taille; i += 1) {
        tab[i] *= 2;
    }
}

int nombres[3];
nombres[0] = 10;
nombres[1] = 20;
nombres[2] = 30;

doubler(nombres, 3);
// nombres contient maintenant : [20, 40, 60]
```

**Fonctionne avec tous les types de tableaux :**
- `int[]`
- `float[]`
- `str[]`

---

## 🎯 Exemple Complet

```c
// Fonction d'analyse de texte
func void analyser(str textes[], int nb) {
    for (int i = 0; i < nb; i += 1) {
        str texte = textes[i];
        print("Texte: " + texte);
        print("Longueur: " + texte.length);
        
        if (texte.length >= 5) {
            str extrait = texte.substring(0, 5);
            print("Extrait: " + extrait);
        }
    }
}

str phrases[2];
phrases[0] = "Hello World";
phrases[1] = "Bonjour";

analyser(phrases, 2);
```

---

## 📊 Récapitulatif Complet

| Fonctionnalité | Statut |
|----------------|--------|
| **Tableaux de chaînes (str[])** | ✅ NOUVEAU |
| **Opérations sur chaînes** | ✅ NOUVEAU |
| **Tableaux en paramètres** | ✅ NOUVEAU |
| Types de base | ✅ |
| Opérateurs composés | ✅ |
| Comparaison chaînes | ✅ |
| Validation stricte | ✅ |
| if/else if/else | ✅ |
| break/continue | ✅ |
| Récursivité | ✅ |

---

## 🚀 Installation

```bash
make
./minilang tests/demo_v3.4.0.ml
```

---

**MiniLang v3.4.0 - Plus Puissant que Jamais !** 🏆
