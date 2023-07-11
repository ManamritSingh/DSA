// to check weather a string is a vlid string or not

#include<iostream>
using namespace std;

int validate(const char *A){

    for (int i = 0; A[i]!='\0'; i++)
    {
        if (!(A[i]>65 && A[i]<90) || !(A[i]>97 && A[i]<122) || !(A[i]>48 && A[i]<57))
        {
            return 0;
        }
        
    }
    return 1;
}

int main(){
    
    const char *name="abc@pass";

    if (validate(name)==0)
    {
        cout<<"invalid"<<endl;
    }
    else{
        cout<<"valid"<<endl;
    }
    return 0;
}