// uses bits to check for duplicates

#include<iostream>
using namespace std;

int main(){
    
    char s[]="finding";
    int h=0;
    int x=0;
    for (int i = 0; s[i]!=0; i++)
    {
        x=1;
        x=x<<(s[i]-97);
        if ((x&h)>0)
        {
            cout<<s[i]<<" is duplicate"<<endl;
        }
        else{
            h=x|h;
        }
    }
    return 0;
}