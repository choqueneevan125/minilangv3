// Test des procédures void

print("=== PROCEDURES VOID ===");

// Procédure simple sans retour
func void afficherMessage() {
    print("Message depuis une procédure void");
}

afficherMessage();

// Procédure avec paramètres
func void afficherNombre(int n) {
    print("Le nombre est:");
    print(n);
}

afficherNombre(42);
afficherNombre(100);

// Procédure qui modifie et affiche
func void afficherCarre(int x) {
    int carre = x * x;
    print("Carré:");
    print(carre);
}

afficherCarre(5);
afficherCarre(10);

// Procédure avec conditions
func void verifierParite(int n) {
    if (n % 2 == 0) {
        print("Le nombre est pair");
    } else {
        print("Le nombre est impair");
    }
}

verifierParite(4);
verifierParite(7);

// Procédure avec boucle
func void compterJusqua(int max) {
    print("Comptage:");
    for (int i = 1; i <= max; i = i + 1) {
        print(i);
    }
}

compterJusqua(5);

// Procédure qui affiche un tableau
func void afficherTableau(int taille) {
    print("Table de multiplication de 5:");
    for (int i = 1; i <= taille; i = i + 1) {
        int resultat = 5 * i;
        print(resultat);
    }
}

afficherTableau(10);

// Procédure avec plusieurs paramètres
func void afficherSomme(int a, int b) {
    int somme = a + b;
    print("Somme:");
    print(somme);
}

afficherSomme(15, 25);

// Procédure qui utilise d'autres fonctions
func int calculer(int x) {
    return x * 2;
}

func void afficherDouble(int n) {
    int double = calculer(n);
    print("Double:");
    print(double);
}

afficherDouble(7);

// Procédure complexe
func void analyserNombre(int n) {
    print("=== Analyse du nombre ===");
    print("Nombre:");
    print(n);
    
    if (n > 0) {
        print("Positif");
    } else {
        if (n < 0) {
            print("Négatif");
        } else {
            print("Zéro");
        }
    }
    
    if (n % 2 == 0) {
        print("Pair");
    } else {
        print("Impair");
    }
    
    if (n > 100) {
        print("Grand nombre");
    }
}

analyserNombre(42);
analyserNombre(-15);
analyserNombre(0);

print("=== FIN DES TESTS VOID ===");
