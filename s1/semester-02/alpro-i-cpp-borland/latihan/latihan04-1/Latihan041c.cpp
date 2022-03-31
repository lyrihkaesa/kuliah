#include <iostream.h>
#include <conio.h>

void main()
{
	int belanja = 0;
   float diskon, bayar;

   cout<<"Belanja      : "; cin>>belanja;

   if(belanja > 100000)
   {
      diskon = 0.10 * belanja;
   }
   else
   {
      diskon = 0.05 * belanja;
   }

   bayar = belanja - diskon;
   cout<<"Diskon       : "<<diskon<<endl;
   cout<<"Total Bayar  : "<<bayar<<endl;
   
   getch();
}