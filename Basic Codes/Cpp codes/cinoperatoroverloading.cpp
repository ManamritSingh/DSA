#include<iostream>
using namespace std;

class rectangle
{
private:
    int l;
    int b;
public:
    rectangle();
    ~rectangle();

   friend istream& operator>>(istream &is , rectangle &r);
   friend ostream& operator<<(ostream &os , rectangle &r);
};

rectangle::rectangle()
{
    l=0;
    b=0;
}

rectangle::~rectangle()
{
}

istream & operator>>(istream &is , rectangle &r) {
    cout<<"enter length"<<endl;
    cin>>r.l;
    cout<<"enter breadth"<<endl;
    cin>>r.b;

    return is;
}

ostream& operator <<(ostream &os , rectangle &r) {
    cout<< "length = "<<r.l << endl ;
    cout<< "breadth ="<<r.b << endl ;
    cout<<"area is ="<<r.l*r.b<<endl;

    return os;
}


int main(){

    rectangle r1;
    cin>>r1;
    cout<<r1;
    
    return 0;
}