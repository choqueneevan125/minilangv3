// Oublier les [] dans l'appel
func void tester(int tab[], int taille) {
    print(tab[0]);
}

int nombres[3];
nombres[0] = 10;

// Appel normal - devrait fonctionner
tester(nombres, 3);
