#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int hash[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hash[i] = -1;
    }
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d => %d\n", i, hash[i]);
    }
}

void insertLinear(int key) {
    int i = 0;
    int hkey = key % SIZE;
    int idx;
    while (i < SIZE) {
        idx = (hkey + i) % SIZE;
        if (hash[idx] == -1) {
            hash[idx] = key;
            printf("%d inserted at index %d (Linear)\n", key, idx);
            return;
        }
        i++;
    }
    printf("Hash Table is full! Cannot insert %d\n", key);
}

void insertQuadratic(int key) {
    int i = 0;
    int hkey = key % SIZE;
    int idx;
    while (i < SIZE) {
        idx = (hkey + i * i) % SIZE;
        if (hash[idx] == -1) {
            hash[idx] = key;
            printf("%d inserted at index %d (Quadratic)\n", key, idx);
            return;
        }
        i++;
    }
    printf("Hash Table is full! Cannot insert %d\n", key);
}

void insertDoubleHash(int key) {
    int i = 0;
    int h1 = key % SIZE;
    int h2 = 7 - (key % 7);  // Make sure 7 > SIZE and is a prime
    int idx;
    while (i < SIZE) {
        idx = (h1 + i * h2) % SIZE;
        if (hash[idx] == -1) {
            hash[idx] = key;
            printf("%d inserted at index %d (Double Hashing)\n", key, idx);
            return;
        }
        i++;
    }
    printf("Hash Table is full! Cannot insert %d\n", key);
}

int main() {
    int choice, key;
    initialize();

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert (Linear Probing)\n");
        printf("2. Insert (Quadratic Probing)\n");
        printf("3. Insert (Double Hashing)\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insertLinear(key);
            break;
        case 2:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insertQuadratic(key);
            break;
        case 3:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insertDoubleHash(key);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
