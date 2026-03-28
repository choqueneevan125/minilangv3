// Test : Retourner tableau paramètre
func int[] copier(int tab[], int n) {
    return tab;
}

int original[3];
original[0] = 10;
original[1] = 20;
original[2] = 30;

int[] copie = copier(original, 3);
print("Copie:");
print(copie[0]);
print(copie[1]);
print(copie[2]);
