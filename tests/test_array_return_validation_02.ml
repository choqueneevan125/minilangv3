// Test validation : Retourner mauvais type d'éléments
func int[] fonction() {
    float tab[3];
    tab[0] = 1.5;
    return tab;
}

int[] resultat = fonction();
print(resultat[0]);
