#include<iostream>
using namespace std;

class Rectangle{
    private:
    int length;
    int breadth;

    public
    Rectangle(){          // default constructor
        int length = 0;
        int breadth = 0;
    }
    Rectangle(int l , int b){ //parametric contructor
        length =l;
        breadth = b;
    }
    // *************** constructor overloading *****************
    int area(){  
        return (length *breadth); // Facilitator
    }
    int perimeter(){                 // Facilitator
        return 2*(length*breadth);
    }
    void SetLength(int l){ // mutator
        length = l;
    }
    void Setbreadth(int b){ // mutator
        breadth = b;
    }
    int getlength(){      // Accessor
        return length;
    }
    int getbreadth(){      // Accessor
        return breadth;
    }
};

int main(){
    Rectangle r{10 , 2}; // object definition

    cout<<"Area "<<r.area()<<endl;          // see how function is accessed using r.area() ie without passsing any arguement
    cout<<"Perimeter"<<r.perimeter();
    
    return 0;
}