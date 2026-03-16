// Test while infini avec break
int i = 0;
while (true) {
    print(i);
    i += 1;
    if (i >= 3) {
        break;
    }
}
print("Fin");
