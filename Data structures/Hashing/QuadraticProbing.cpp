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
    while ( H[(index+i*i)%10] != 0)
    {
        i++;
    }
    return (index+i*i)%SIZE;
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

    while (H[(index+i*i)%10]!= key)
    {
        i++;
    }
    return (index+i*i)%SIZE;
}

int main() {

    int HT[10]={0};
    
    insert(HT , 23);
    insert(HT , 43);
    insert(HT , 13);
    insert(HT , 27);

    cout<<"fOUND @ "<<search(HT , 13);
    return 0;
}