#include <iostream.h>
#include <conio.h>

int nilai[3][4] = { {10, 15, 20, 25},
                    {30, 35, 40, 45},
                    {75, 80, 85, 90} };

void main()
{
    // cetak array.....................
    for (int brs=0; brs < 3; brs++)
    {
        for (int klm = 0; klm < 4; klm++)
        {
            cout<<nilai[brs][klm]<<"\t";
        }
        cout<<endl;        
    }
    getch();
}