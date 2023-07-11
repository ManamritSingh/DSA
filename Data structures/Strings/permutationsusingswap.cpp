// swap method

#include<iostream>
using namespace std;

void perm(char S[], int l , int h){

if (l==h)
{
    cout<<S<<" ";
}
else{
    for (int i = l; i <=h; i++)
    {
        swap(S[i],S[l]);
        perm(S,l+1,h);
        swap(S[i],S[l]);
    }
    
}

}

int main(){
    char A[]="ABC";
    perm(A,0,2);
    return 0;
}