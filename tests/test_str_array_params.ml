// Fonction qui affiche un tableau de chaînes
func void afficher_noms(str noms[], int taille) {
    print("Liste des noms:");
    for (int i = 0; i < taille; i += 1) {
        print(noms[i]);
    }
}

// Test
str personnes[3];
personnes[0] = "Alice";
personnes[1] = "Bob";
personnes[2] = "Charlie";

afficher_noms(personnes, 3);
