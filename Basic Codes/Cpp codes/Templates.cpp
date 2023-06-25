#include<iostream>
using namespace std;

template <class T>
class arithmetic{

    private:
    T a;
    T b;

    public:

    arithmetic(T a , T b);
    T add();
    T sub();

};   
    template <class T>
    arithmetic<T>::arithmetic(T a , T b){         // :: is known as the scope resolution
        this->a = a;  // this-> is pointer to the current object
        this->b = b;  // this-> is pointer to the current object
    }

    template <class T>
    T arithmetic<T> :: add(){
        T c=0;
        c = a+b;
        return c;
    }

    template <class T>
    T arithmetic <T>:: sub(){
        T d=0;
        d = a-b;
        return d;
    }

int main(){
    arithmetic <int> arr1{10,3} ;
    arithmetic <float> arr2{1.2,0.4};

    cout<<arr1.add()<<endl;
    cout<<arr2.sub()<<endl;
    return 0;
}