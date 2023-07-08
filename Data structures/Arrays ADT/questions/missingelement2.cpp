// more efficient method
//uses hashing like mechanism

#include<iostream>
using namespace std;

int main(){
    
    int *A;
    int *H;
    int sizeA=10;
    int sizeH = 100;
    int lengthA;
    int lengthH;

    A = new int [sizeA];
    A[0]={10};
    A[1]={11};
    A[2]={13};
    A[3]={14};
    A[4]={17};
    A[5]={18};  
    lengthA=6;
// max ele
    int max=A[0];
        for (int i = 1; i < lengthA; i++)
        {
            if (A[i]>max)
            {
                max=A[i];
            }
            
        }
// min ele
        int min=A[0];
        for (int i = 1; i < lengthA; i++)
        {
            if (A[i]<min)
            {
                min=A[i];
            }
            
        }
//********
        lengthH = max;
        H = new int[sizeH];
// make an array H of size max-min element of array A and assign every element as 0
        for (int i = 0; i < max; i++)
        {
            H[i]=0;
        }
        

        for (int i = 0; i < lengthA; i++)
        {
            H[A[i]]++;
        }

    for (int i = min; i < max; i++)
    {
        if (H[i]==0)
        {
            cout<<"missing element : "<<i<<endl;
        }
        
    }
       
        

    return 0;
}