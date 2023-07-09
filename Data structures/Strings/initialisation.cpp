#include<iostream>
using namespace std;

int main(){
    char temp = 'A';
    //cout<<temp;

    // array of characters

    char X[4]={'J', 'O','H','N'};
    cout<<X<<endl;

    // string is marked with \0 is null character

    char Z[]={'J', 'O','H','N','\0'};
    cout<<Z<<endl;

    char K[]="JOHN";
    cout<<K<<endl;

    // getting a string as input

    //char m[10];
    //cin>>m;

    char n[10];
    gets(n);

    cout<<m<<endl;
    cout<<n<<endl;
    return 0;
}