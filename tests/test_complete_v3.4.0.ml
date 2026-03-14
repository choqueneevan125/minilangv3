print("=== TEST COMPLET v3.4.0 ===");

// 1. Tableaux de chaînes
str langages[3];
langages[0] = "Python";
langages[1] = "JavaScript";
langages[2] = "Rust";

print("Langages:");
for (int i = 0; i < 3; i += 1) {
    print(langages[i]);
}

// 2. .length et .substring sur str[]
print("Longueurs:");
for (int i = 0; i < 3; i += 1) {
    print(langages[i].length);
}

print("3 premiers caracteres:");
for (int i = 0; i < 3; i += 1) {
    str extrait = langages[i].substring(0, 3);
    print(extrait);
}

// 3. Tableaux en paramètres avec vérification type
func void afficher_int(int tab[], int n) {
    for (int i = 0; i < n; i += 1) {
        print(tab[i]);
    }
}

func void afficher_str(str tab[], int n) {
    for (int i = 0; i < n; i += 1) {
        print(tab[i]);
    }
}

int nombres[3];
nombres[0] = 10;
nombres[1] = 20;
nombres[2] = 30;

print("Nombres:");
afficher_int(nombres, 3);

print("Langages via fonction:");
afficher_str(langages, 3);

print("=== FIN TEST ===");
