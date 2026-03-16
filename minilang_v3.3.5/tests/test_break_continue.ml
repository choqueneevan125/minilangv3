// Test break et continue - v3.2.0

print("=== BREAK ET CONTINUE ===");

// Test break dans for
print("Break dans for (arrêt à 5):");
for (int i = 0; i < 10; i = i + 1) {
    if (i == 5) {
        break;
    }
    print(i);
}

// Test continue dans for
print("Continue dans for (skip pairs):");
for (int j = 0; j < 10; j = j + 1) {
    if (j % 2 == 0) {
        continue;
    }
    print(j);
}

// Test break dans while
print("Break dans while:");
int k = 0;
while (k < 10) {
    if (k == 3) {
        break;
    }
    print(k);
    k = k + 1;
}

// Test continue dans while
print("Continue dans while (skip 5):");
int m = 0;
while (m < 10) {
    m = m + 1;
    if (m == 5) {
        continue;
    }
    print(m);
}

// Recherche avec break
print("Recherche de 7:");
int nombres[10];
for (int i = 0; i < 10; i = i + 1) {
    nombres[i] = i;
}

bool trouve = false;
for (int i = 0; i < 10; i = i + 1) {
    if (nombres[i] == 7) {
        print("Trouvé à l'index:");
        print(i);
        trouve = true;
        break;
    }
}

if (!trouve) {
    print("Non trouvé");
}

print("=== FIN TEST BREAK/CONTINUE ===");
