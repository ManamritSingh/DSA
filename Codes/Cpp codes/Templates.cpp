#include<iostream>
using namespace std;

class arithmetic{

    private:
    int a;
    int b;

    public:
    arithmetic(int a , int b){
        this->a = a;  // this-> is pointer to the current object
        this->b = b;  // this-> is pointer to the current object
    }

    int add(){
        int c=0;
        c = a+b;
        return c;
    }

    int sub(){
        int d=0;
        d = a-b;
        return d;
    }
};

int main(){
    arithmetic arr1{10,3} , arr2{12,4};

    cout<<arr1.add()<<endl;
    cout<<arr2.sub()<<endl;
    return 0;
}