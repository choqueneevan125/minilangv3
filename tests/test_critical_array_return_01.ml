// Test : Retourner un tableau non initialisé
func int[] creer_vide() {
    int tab[3];
    return tab;
}

int[] resultat = creer_vide();
print("Valeurs:");
print(resultat[0]);
print(resultat[1]);
print(resultat[2]);
