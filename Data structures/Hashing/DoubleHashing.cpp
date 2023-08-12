#include <iostream>
#define SIZE 10
#define PRIME 7
using namespace std;

int hashkey(int key){
    return key % SIZE;
}

int primehash(int key){
    return PRIME - (key % PRIME);
}

int doublehash(int H[], int key){ // to find free space for insertion

    int index = hashkey(key);

    int i = 0;
    while (H[(hashkey(index) + i * primehash(key)) % SIZE] != 0) {
        i++;
    }
    return (index + i * primehash(key)) % SIZE;
}

void insert(int H[], int key){
    int index = hashkey(key);

    if (H[index] != 0) {
        index = doublehash(H, key);
    }
    H[index] = key;
}

int search(int H[], int key){
    int index = hashkey(key);
    int i = 0;

    while (H[(index + i * primehash(key)) % SIZE] != key) {
        i++;
        if (H[hashkey(key) + i * primehash(key) % SIZE] == 0) {
            return -1;
        }
    }
    return (index + i * primehash(key)) % SIZE;
}

int main() {

    int HT[10] = {0};
    
    insert(HT, 5);
    insert(HT, 25);
    insert(HT, 15);
    insert(HT, 35);
    insert(HT, 95);

    for (int i = 0; i < 10; i++) {
        cout << HT[i] << " ";
    }
    cout << endl;

    cout << "25 FOUND @ " << search(HT, 25) << endl;
    cout << "25 FOUND @ " << search(HT, 35) << endl;
    cout << "95 FOUND @ " << search(HT, 95) << endl;
    return 0;
}
