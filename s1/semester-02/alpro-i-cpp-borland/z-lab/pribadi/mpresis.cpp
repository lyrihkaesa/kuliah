#include <iostream.h>
#include <math.h>
#include <conio.h>

double mpresis, reducedmg, a, pangkat, mp1, mp2, totalred = 0;
double bagian[100];

void main(){
    cout << "Masukan M/P Resis : "; cin >> mpresis;
    a = ceil(mpresis/50);
    cout << "Bagian: " << mpresis << "/50 = " << a << endl << "------------" << endl;
    for (int i = 0; i < a; i++) {
        mp1 = mpresis - 50;
        if(mp1 > 0){
        mp2 = mpresis - mp1;
        bagian[i] = mp2;
        mpresis = mpresis - 50;
        }
        else {
        mp2 = mpresis;
        bagian[i] = mp2;
        mpresis = mpresis - 50;
        }
    }
    for (int i = 0; i < a; i++) {
        pangkat = pow(2,i);
        reducedmg = bagian[i]/pangkat;
        totalred = reducedmg + totalred;
        cout << "bagian-" << i << ": (" << bagian[i] << "/2^" << i << ")"<<endl;
        cout << "ReduceDMG bagian-" << i << " : " << reducedmg << "%" << endl;
        cout << "Total ReduceDMG : " << totalred << "%" << endl;
        cout << "Total ReduceDMG (Floor): " << floor(totalred) << "%" << endl;
        cout << "------------------" << endl;
    }
    getch();
}
