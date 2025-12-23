// Test des fonctions basiques

print("=== FONCTIONS BASIQUES ===");

// Fonction sans paramètres
func int getNumber() {
    return 42;
}

int nombre = getNumber();
print("Nombre:");
print(nombre);

// Fonction avec paramètres
func int addition(int a, int b) {
    return a + b;
}

int somme = addition(10, 20);
print("10 + 20 =");
print(somme);

// Fonction avec plusieurs opérations
func int carre(int x) {
    int resultat = x * x;
    return resultat;
}

print("Carré de 5:");
print(carre(5));
print("Carré de 12:");
print(carre(12));

// Fonction avec float
func float moyenne(int a, int b) {
    float somme = a + b;
    float moy = somme / 2.0;
    return moy;
}

float moy = moyenne(10, 20);
print("Moyenne de 10 et 20:");
print(moy);

// Fonction qui utilise une condition
func int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

print("Max entre 15 et 25:");
print(max(15, 25));

// Fonction qui utilise une boucle
func int sommeJusqua(int n) {
    int total = 0;
    for (int i = 1; i <= n; i = i + 1) {
        total = total + i;
    }
    return total;
}

print("Somme de 1 à 10:");
print(sommeJusqua(10));

print("Somme de 1 à 100:");
print(sommeJusqua(100));

print("=== FIN DES TESTS ===");
