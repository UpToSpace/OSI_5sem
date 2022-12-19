#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    for (int i = 0; i < 1000000; i++) {
        cout << "OS06_02 - " << i << endl;
        Sleep(1000);
    }
}