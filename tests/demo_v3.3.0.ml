// Programme complet v3.3.0 - Gestionnaire de noms

print("=== GESTIONNAIRE DE NOMS v3.3.0 ===");

// Collecte de noms
str nom1 = input("Premier nom: ");
str nom2 = input("Deuxième nom: ");
str nom3 = input("Troisième nom: ");

// Affichage avec longueurs
print("--- Liste des noms ---");
print(nom1 + " (longueur: " + nom1.length() + ")");
print(nom2 + " (longueur: " + nom2.length() + ")");
print(nom3 + " (longueur: " + nom3.length() + ")");

// Recherche
str recherche = input("Nom à rechercher: ");
bool trouve = false;

if (nom1 == recherche) {
    print("Trouvé en position 1");
    trouve = true;
}
if (nom2 == recherche) {
    print("Trouvé en position 2");
    trouve = true;
}
if (nom3 == recherche) {
    print("Trouvé en position 3");
    trouve = true;
}

if (!trouve) {
    print("Nom non trouvé");
}

// Tri alphabétique simple
print("--- Ordre alphabétique ---");
if (nom1 < nom2 && nom1 < nom3) {
    print("Premier alphabétiquement: " + nom1);
}
if (nom2 < nom1 && nom2 < nom3) {
    print("Premier alphabétiquement: " + nom2);
}
if (nom3 < nom1 && nom3 < nom2) {
    print("Premier alphabétiquement: " + nom3);
}

// Statistiques
print("--- Statistiques ---");
int total_lettres = 0;
total_lettres += nom1.length();
total_lettres += nom2.length();
total_lettres += nom3.length();
print("Total de lettres: " + total_lettres);

int moyenne = total_lettres / 3;
print("Moyenne par nom: " + moyenne);

// Extraire initiales
print("--- Initiales ---");
str initiales = "";
initiales += nom1.substring(0, 1);
initiales += nom2.substring(0, 1);
initiales += nom3.substring(0, 1);
print("Initiales: " + initiales);

print("=== FIN ===");
