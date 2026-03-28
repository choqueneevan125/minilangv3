// Test : Utiliser directement le retour
func int[] creer() {
    int tab[2];
    tab[0] = 10;
    tab[1] = 20;
    return tab;
}

print(creer()[0]);
