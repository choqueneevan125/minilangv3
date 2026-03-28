// Test : Grand tableau
func int[] creer_grand() {
    int tab[100];
    tab[0] = 1;
    tab[99] = 100;
    return tab;
}

int[] grand = creer_grand();
print(grand[0]);
print(grand[99]);
