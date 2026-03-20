// Test 3 : str[]
func str[] creer_noms() {
    str personnes[3];
    personnes[0] = "Alice";
    personnes[1] = "Bob";
    personnes[2] = "Charlie";
    return personnes;
}

str[] liste = creer_noms();
print("Liste:");
print(liste[0]);
print(liste[1]);
print(liste[2]);
