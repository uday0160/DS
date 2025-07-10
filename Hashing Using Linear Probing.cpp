#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int main() {
    int hashTable[TABLE_SIZE] = {0};
    int keys[TABLE_SIZE] = {0};
    int key, value, index, originalIndex;

    for (int i = 0; i < 4; i++) {
        printf("Enter key and value: ");
        scanf("%d %d", &key, &value);
        index = key % TABLE_SIZE;
        originalIndex = index;

        while (hashTable[index] != 0) {
            if (keys[index] == key) {
                hashTable[index] = value;
                break;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                printf("Hash table is full. Cannot insert %d.\n", key);
                break;
            }
        }
        if (hashTable[index] == 0) {
            hashTable[index] = value;
            keys[index] = key;
        }
    }

    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != 0) {
            printf("Index %d: Key = %d, Value = %d\n", i, keys[i], hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }

    printf("Enter key to search: ");
    scanf("%d", &key);
    index = key % TABLE_SIZE;
    originalIndex = index;

    while (hashTable[index] != 0) {
        if (keys[index] == key) {
            printf("Value for key %d: %d\n", key, hashTable[index]);
            break;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Key %d not found in the hash table.\n", key);
            break;
        }
    }
    return 0;
}

