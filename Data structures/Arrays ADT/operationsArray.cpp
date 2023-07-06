#include<iostream>
using namespace std;

class operationsArray
{
private:
    int *A;
    int size;
    int length;
public:
    operationsArray(int sze);
    void create();
    void display();
    int get(int index);
    void set(int index , int x);
    int max();
    int min();
    int sum();
    float avg();
    ~operationsArray();
};

operationsArray::operationsArray(int sze)
{
    size = sze;
    A = new int[sze];
}

void operationsArray::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void operationsArray::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

int operationsArray::get(int index){

    if(index>=0 && length>index ){

        return A[index];
    }
}

void operationsArray::set(int index , int x){
    if(index>=0 && length>index ){
        A[index]=x;
        display();
    }
}

int operationsArray::max(){
    
        int max=A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i]>max)
            {
                max=A[i];
            }
            
        }
        
    
    return max;
}

int operationsArray::min(){
        int min=A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i]<min)
            {
                min=A[i];
            }
            
        }
    return min;
}

int operationsArray::sum(){
        int sum =0;
        for (int i = 0; i < length; i++)
        {
            sum+=A[i];
        }
        return sum;
}

float operationsArray::avg()
{
    float avg = 0;
    int sum=0;
    for (int i = 0; i < length; i++)
    {
        sum+=A[i];
    }
    avg = sum/length;
    return avg;
    
}
operationsArray::~operationsArray()
{
    delete []A;
    cout<<"Destruction whoshh!!!!! "<<endl;
}


int main(){

    operationsArray ele(10);
    ele.create();
    ele.display();
    ele.set(3,46);
    cout<<"element 3 is "<<ele.get(3)<<endl;
    cout<<"max element is "<<ele.max()<<endl;
    cout<<"min element is "<<ele.min()<<endl;
    cout<<"sum of array is "<<ele.sum()<<endl;;
    cout<<"Average of array is "<<ele.avg()<<endl;
    
    return 0;
}