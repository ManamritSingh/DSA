#include<iostream>
using namespace std;

int main(){
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

   /* for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<A[i][j]<<" ";
            
        }
        cout<<endl;
    }
    */
    // 2nd method partially in heap

    int *p[3];

    p[0]= new int[4];
    p[1]= new int[4];
    p[2]= new int[4];

 /*   for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<p[i][j]<<" ";
            
        }
        cout<<endl;
    }
*/

// completely in heap
    int **c;

    c= new int*[3];
    c[0]= new int[4];
    c[1]= new int[4];
    c[2]= new int[4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<c[i][j]<<" ";
            
        }
        cout<<endl;
    }

    return 0;
}