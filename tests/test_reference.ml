func void modifier(int tab[], int taille) {
    tab[0] = 999;
    tab[1] = 888;
}

int nums[3];
nums[0] = 1;
nums[1] = 2;
nums[2] = 3;

print("Avant:");
print(nums[0]);
print(nums[1]);

modifier(nums, 3);

print("Apres:");
print(nums[0]);
print(nums[1]);
