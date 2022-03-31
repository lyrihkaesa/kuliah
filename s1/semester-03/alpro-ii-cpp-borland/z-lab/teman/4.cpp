#include <conio.h>
#include <iostream.h>

   struct smhs
   {
   	char nim[5];
      char nama[15];
      float nilai;
      char huruf[2];
   };

   smhs mahasiswa[5];

   void main()
   {
   	clrscr();
      for(int i=0; i<2; i++)
      {
      	//input data.................................
         cout << "\nIsi Data Mahasiswa : \n";
         cout << "masukan NIM     = "; cin >> mahasiswa[i].nim;
         cout << "masukan Nama    = "; cin >> mahasiswa[i].nama;
         cout << "masukan Nilai   = "; cin >> mahasiswa[i].nilai;

         if(mahasiswa[i].nilai >=80){
         	 strcpy(mahasiswa[i].huruf,"A");
            	cout << "Nilai Huruf = A" << endl;
            	}
      	else if (mahasiswa[i].nilai >=60 && mahasiswa[i].nilai <80){
      		strcpy(mahasiswa[i].huruf,"B");
            	cout << "Nilai Huruf = B" << endl;
         		}
         else if (mahasiswa[i].nilai <60){
      		strcpy(mahasiswa[i].huruf,"C");
            	cout << "Nilai Huruf = C" << endl;
         		}
      }
      //cetak data....................................
      cout << "\nCetakData yang sudah diisikan : \n\n";
      cout << "No       NIM            Nama    Nilai     Nilai huruf\n";
      cout << "=============================================================\n";
      for(int a=1; a<2; a++)
      {
      	cout << " " << a;
         cout << "\t" << mahasiswa[a].nim;
         cout << "\t" << mahasiswa[a].nama;
         cout << "\t" << mahasiswa[a].nilai;
         cout << "\t" << mahasiswa[a].huruf <<endl;
      }

      cout << endl;
      getch();
   }