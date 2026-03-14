// Démonstration MiniLang v3.4.0 - Nouvelles fonctionnalités

print("=== MINILANG v3.4.0 - DEMO ===");

// 1. TABLEAUX DE CHAINES (str[])
print("--- 1. Tableaux de chaines ---");
str langages[4];
langages[0] = "C";
langages[1] = "Python";
langages[2] = "JavaScript";
langages[3] = "Rust";

print("Langages de programmation:");
for (int i = 0; i < 4; i += 1) {
    print(langages[i]);
}

// 2. OPERATIONS SUR CHAINES (.length, .substring)
print("--- 2. Operations sur chaines ---");
str message = "Bonjour le monde";
print("Message:");
print(message);
print("Longueur:");
print(message.length);

str debut = message.substring(0, 7);
print("Debut (0-7):");
print(debut);

str fin = message.substring(8, 16);
print("Fin (8-16):");
print(fin);

// 3. TABLEAUX EN PARAMETRES DE FONCTION
print("--- 3. Tableaux en parametres ---");

// Fonction qui calcule la somme d'un tableau
func int somme_tableau(int tab[], int taille) {
    int total = 0;
    for (int i = 0; i < taille; i += 1) {
        total += tab[i];
    }
    return total;
}

// Fonction qui trouve le maximum
func int trouver_max(int tab[], int taille) {
    int max = tab[0];
    for (int i = 1; i < taille; i += 1) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

// Fonction qui modifie un tableau
func void multiplier_par(int tab[], int taille, int facteur) {
    for (int i = 0; i < taille; i += 1) {
        tab[i] *= facteur;
    }
}

int notes[5];
notes[0] = 15;
notes[1] = 18;
notes[2] = 12;
notes[3] = 16;
notes[4] = 14;

print("Notes:");
for (int i = 0; i < 5; i += 1) {
    print(notes[i]);
}

int total = somme_tableau(notes, 5);
print("Somme:");
print(total);

int maximum = trouver_max(notes, 5);
print("Maximum:");
print(maximum);

print("Multiplication par 2:");
multiplier_par(notes, 5, 2);
for (int i = 0; i < 5; i += 1) {
    print(notes[i]);
}

// 4. EXEMPLE COMPLET : Traitement de texte
print("--- 4. Traitement de texte ---");

func void analyser_textes(str textes[], int nb) {
    print("Analyse des textes:");
    for (int i = 0; i < nb; i += 1) {
        str texte = textes[i];
        int longueur = texte.length;
        print("Texte:");
        print(texte);
        print("Longueur:");
        print(longueur);
        
        if (longueur >= 5) {
            str extrait = texte.substring(0, 5);
            print("5 premiers caracteres:");
            print(extrait);
        }
    }
}

str phrases[3];
phrases[0] = "Hello World";
phrases[1] = "Bonjour";
phrases[2] = "MiniLang est genial";

analyser_textes(phrases, 3);

print("=== FIN DEMO v3.4.0 ===");
