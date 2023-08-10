// bin or basket sort

#include <iostream>
#include<cmath>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

int Findmax(int A[] , int n){
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max= A[i];
        }
    }
    return max;
}

int getbinIndex(int x , int index){
    return (int)(x/pow(10 , index))%10;
}

void intialiseBinsArray(node** p , int n){
    for (int i = 0; i < n; i++)
    {
        p[i]=nullptr;
    }
}

void insert(node** binptrs ,int value , int index){
    node * temp = new node;
    temp->data= value;
    temp->next = nullptr;

    if (binptrs[index] == nullptr)  // head condition
    {
        binptrs[index]=temp ;
    }
    else{
        node* p = binptrs[index];  // for subsequent nodes
        while (p->next != nullptr)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

int deletenode(node** binptrs , int index){
    node* p = binptrs[index];
    binptrs[index]= binptrs[index]->next;
    int x = p->data;
    delete p;
    return x;
}

int countdigits(int x){
    int c =0;
    while (x!=0)
    {
        x/=10;
        c++;
    }
    return c;
}

void RadixSort(int A[] , int n){
    int max = Findmax(A , n);
    int nPass = countdigits(max); 
    // no of passes based on max number's digit count
    node ** bins = new node* [10];
    intialiseBinsArray(bins , 10);

    for (int pass = 0; pass < nPass; pass++)
    {
        for (int i = 0; i < n; i++)
        {
            int binIndex = getbinIndex(A[i] , pass);
            insert(bins , A[i] , binIndex);
        }
        int i=0, j=0;

        while (i<10)
        {
            while (bins[i] !=nullptr)
            {
                A[j++]= deletenode(bins, i);
            }
            i++;
        }
        intialiseBinsArray(bins , 10);  // for next pass
    }
    delete [] bins;
}

int main() {
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};;
    int n = sizeof(A)/sizeof(A[0]);

    RadixSort(A , n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}