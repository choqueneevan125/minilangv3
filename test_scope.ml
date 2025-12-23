// Test des scopes isolés des fonctions

print("=== TEST DES SCOPES ===");

// Variable globale
int x = 100;

func int testScope1(int x) {
    // x est un paramètre, isolé du x global
    x = x + 10;
    return x;
}

func int testScope2() {
    // Cette fonction voit le x global
    int y = x + 50;
    return y;
}

func int testScope3(int a) {
    // Variable locale
    int z = a * 2;
    
    // Modifier z ne modifie rien à l'extérieur
    for (int i = 0; i < 3; i = i + 1) {
        z = z + i;
    }
    
    return z;
}

print("x global:");
print(x);

int result1 = testScope1(5);
print("testScope1(5):");
print(result1);

print("x global après testScope1:");
print(x);  // Toujours 100

int result2 = testScope2();
print("testScope2():");
print(result2);  // 150

int result3 = testScope3(10);
print("testScope3(10):");
print(result3);  // 23

// Variables locales dans les fonctions
func int compteur() {
    int count = 0;
    for (int i = 0; i < 10; i = i + 1) {
        count = count + 1;
    }
    return count;
}

func int autreCompteur() {
    int count = 100;  // count différent
    return count;
}

print("Premier compteur:");
print(compteur());

print("Autre compteur:");
print(autreCompteur());

// Appels imbriqués
func int double(int n) {
    return n * 2;
}

func int quadruple(int n) {
    int temp = double(n);
    return double(temp);
}

print("Quadruple de 5:");
print(quadruple(5));
