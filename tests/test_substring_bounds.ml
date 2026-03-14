str texte = "Hello";

print("Test start négatif:");
str r1 = texte.substring(-5, 3);
print(r1);

print("Test end > length:");
str r2 = texte.substring(0, 100);
print(r2);

print("Test start > end:");
str r3 = texte.substring(4, 2);
print(r3);

print("Test start > length:");
str r4 = texte.substring(10, 15);
print(r4);
