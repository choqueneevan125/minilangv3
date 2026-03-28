// Test validation : Type de tableau correct
func int[] creer_int() {
    int tab[3];
    tab[0] = 10;
    tab[1] = 20;
    tab[2] = 30;
    return tab;
}

func float[] creer_float() {
    float tab[2];
    tab[0] = 1.5;
    tab[1] = 2.5;
    return tab;
}

// OK - Types corrects
int[] entiers = creer_int();
float[] flottants = creer_float();

print("Entiers:");
print(entiers[0]);
print(entiers[1]);

print("Flottants:");
print(flottants[0]);
print(flottants[1]);
