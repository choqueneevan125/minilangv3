// Fonction qui affiche un tableau d'entiers
func void afficher_tableau(int tab[], int taille) {
    print("Contenu du tableau:");
    for (int i = 0; i < taille; i += 1) {
        print(tab[i]);
    }
}

// Fonction qui modifie un tableau (passage par référence)
func void doubler_valeurs(int tab[], int taille) {
    for (int i = 0; i < taille; i += 1) {
        tab[i] *= 2;
    }
}

// Test
int nombres[5];
nombres[0] = 10;
nombres[1] = 20;
nombres[2] = 30;
nombres[3] = 40;
nombres[4] = 50;

print("=== AVANT ===");
afficher_tableau(nombres, 5);

print("=== DOUBLER ===");
doubler_valeurs(nombres, 5);

print("=== APRES ===");
afficher_tableau(nombres, 5);
