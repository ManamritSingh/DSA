#include <iostream>
#define SIZE 10
using namespace std;

// functions for search , insert and probing
// delete not recommended as it needs rehashing which is time consuming

int hashkey(int key){
    return key%SIZE;
}

int probe(int H[] , int key){ // to find free space for insertion

    int index = hashkey(key);

    int i =0;
    while ( H[(index+i)%10] != 0)
    {
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int H[] , int key){
    int index = hashkey(key);

    if (H[index] != 0)
    {
        index = probe(H , key);
    }
    H[index]=key;
}

int search(int H[] , int key){
    int index = hashkey(key);
    int i =0;

    while (H[(index+i)%10]!= key)
    {
        i++;
    }
    return (index+i)%SIZE;
}

int main() {

    int HT[10]={0};
    
    insert(HT , 12);
    insert(HT , 25);
    insert(HT , 35);
    insert(HT , 26);

    cout<<"fOUND @ "<<search(HT , 35);
    return 0;
}