// Test 1 : Fonction retournant int[]
func int[] creer_nombres() {
    int tab[3];
    tab[0] = 10;
    tab[1] = 20;
    tab[2] = 30;
    return tab;
}

int[] resultat = creer_nombres();
print("Resultat:");
print(resultat[0]);
print(resultat[1]);
print(resultat[2]);
