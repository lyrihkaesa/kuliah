// MinGW Compailler VSCode codeblock
#include <iostream> // cout, cin {untuk tipe data tanpa spasi}
using namespace std;

struct smhs
{
    char nim[6];
    char nama[15];
    float nilai;
};
smhs mahasiswa[5];

int main() {
    for (int i = 0; i < 5; i++)
    {
        // input data...................
        cin.ignore();
        cout << "Isi Data Mahasiswa : " << endl;
        cout << "masukan NIM    = "; cin.getline(mahasiswa[i].nim, 6);
        cout << "masukan Nama   = "; cin.getline(mahasiswa[i].nama, 15);
        cout << "masukan Nilai  = "; cin >> mahasiswa[i].nilai;
        cout << endl;
    };
    // cetak data....................
    cout << "\n\nCetakData yang sudah diisikan : \n";
    cout << " No    NIM     Nama    Nilai       NilaiHuruf\n";
    cout << "====================================\n";
    for (int a = 0; a < 5; a++)
    {
        cout << " " << a;
        cout << "\t" << mahasiswa[a].nim;
        cout << "\t" << mahasiswa[a].nama;
        cout << "\t" << mahasiswa[a].nilai;
        if (mahasiswa[a].nilai < 60) {
            cout << "       C";
        } else if (mahasiswa[a].nilai < 80) {
            cout << "\tB";
        } else if (mahasiswa[a].nilai >= 80) {
            cout << "\tA";
        } else {
            cout << "\t???";
        };
        cout << endl;
    };

    cout << endl;
    return 0;
};