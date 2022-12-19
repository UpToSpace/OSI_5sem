#include <iostream>
#include <Windows.h>

#define KB (1024)
#define PG (4 * KB)

using namespace std;

// К - 202(10) = CA(16) 
// о - 238(10) = EE(16)
// р - 240(10) = F0(16)

// страница CA = 202
// 202 * 4096 = 827392(10) = 0xCA000 - добавить чтоб перейти на страницу
// смещение 0xEEF
// к адресу начала arr + 0xCAEEF

void saymem() {
    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    std::cout << " -- Физическая память: " << ms.dwTotalPhys / KB << '\n';
    std::cout << " -- Доступно физической памяти: " << ms.dwAvailPhys / KB << '\n';
    std::cout << " -- Объем виртуальной памяти: " << ms.dwTotalVirtual / KB << '\n';
    std::cout << " -- Доступно виртуальной памяти: " << ms.dwAvailVirtual / KB << "\n\n";
}

int main() {
    setlocale(LOCALE_ALL, "rus");

    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    saymem();
    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);

    int* arr = (int*)xmemaddr;
    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }
    cout << endl;

    saymem();

    VirtualFree(xmemaddr, NULL, MEM_RELEASE) ? std::cout << "VirtualFree true\n" : std::cout << "VirtualFree false\n";
    saymem();

    system("pause");
}
