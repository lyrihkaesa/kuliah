#include <iostream>
#include <windows.h>
using namespace std;

COORD coord = {0,0};

void gotoxy(int x, int y) {
	coord.X = x;
    coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
  gotoxy(10, 20); cout << "Hallo";
  return 0;
}
