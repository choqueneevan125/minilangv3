// Test opérateurs d'assignation composés - v3.3.0

print("=== TEST OPÉRATEURS COMPOSÉS ===");

// Test +=
int x = 10;
print("x = 10");
x += 5;
print("x += 5");
print(x);  // 15

// Test -=
int y = 20;
print("y = 20");
y -= 8;
print("y -= 8");
print(y);  // 12

// Test *=
int z = 3;
print("z = 3");
z *= 4;
print("z *= 4");
print(z);  // 12

// Test /=
int w = 100;
print("w = 100");
w /= 5;
print("w /= 5");
print(w);  // 20

// Test avec float
float a = 10.5;
print("a = 10.5");
a += 2.3;
print("a += 2.3");
print(a);  // 12.8

// Test += avec chaînes
str message = "Hello";
print("message = Hello");
message += " ";
message += "World";
print("message += World");
print(message);  // Hello World

print("=== FIN TEST ===");
