#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
// using namespace std;

void main()
{
    int i,num;
    cout<<"Enter the number : ";
    cin>>num;
    for(i=2;i<=num/2;i++)
    {
        cout << i << endl;
        if(num%i==0)
        {
            cout<<"\nNot a prime number!";
            getch();
            exit(1);
            // break;
        }
    }
    cout<<"\nIt is a prime number!";
    // return 0;
    getch();
}