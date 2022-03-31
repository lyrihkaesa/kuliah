#include <conio.h>
#include <iostream.h>

void main ()
{
   int jumlah[4];
   int i,j,k;

   for (i=0; i<4;i++)
   {
      cout << " Data Ke-%d:", i+1);
      cout << "%d", &A[i];

   }
   j=0;
   	for (i=0; i<4;i++)
   {
     		if (A[i]==k)
        {
           jumlah [j]=i;
           j++;
        }
   }
    if (j>0)
    {
     cout<<"Data %d yang dicari ada %d buah\n",k,j;
     cout<<"Data tersebut terdapat dalam index ke : ";
     for (i=0;i<j;i++)
     {
       cout<<" %d ", index[i];
       }
     cout <<"\n";
     }
     else
     {
    cout <<"data tidak ditemukan dalam array \n";
     }
     cout << endl;
    getch();
};