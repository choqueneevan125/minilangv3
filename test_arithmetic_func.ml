// Fonctions arithmétiques

print("=== BIBLIOTHEQUE MATHEMATIQUE ===");

func int puissance(int base, int exp) {
    int resultat = 1;
    for (int i = 0; i < exp; i = i + 1) {
        resultat = resultat * base;
    }
    return resultat;
}

func int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

func int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

func int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

func int pgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

func int estPremier(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    
    for (int i = 3; i * i <= n; i = i + 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Tests
print("2^10 =");
print(puissance(2, 10));

print("Valeur absolue de -15:");
print(abs(-15));

print("Min(25, 17):");
print(min(25, 17));

print("Max(25, 17):");
print(max(25, 17));

print("PGCD(48, 18):");
print(pgcd(48, 18));

print("Nombres premiers jusqu'à 30:");
for (int i = 2; i <= 30; i = i + 1) {
    if (estPremier(i)) {
        print(i);
    }
}

// Utilisation combinée
int a = puissance(2, 5);
int b = puissance(3, 3);
print("PGCD de 2^5 et 3^3:");
print(pgcd(a, b));
