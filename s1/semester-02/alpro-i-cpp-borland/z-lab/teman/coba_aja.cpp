#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
	char* temp = "Ora puas!";
   cout << temp << endl;
   cout << *temp << endl;
   temp = temp + 2;
   cout << *temp << endl;
   temp--;
   cout << *temp << endl;
   int x = 0;
   for(;* temp != '\0';temp++)++x;{
        cout << &temp << endl;
        cout << * temp << endl;
        cout << x << endl;
    }


   char* s = "hhhdef\n";
	cout << s << endl;
	s[4] = '\0';
	cout << s << endl;
	cout << "hhh\0defef" << endl;

   getch();
}
