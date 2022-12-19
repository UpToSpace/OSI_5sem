// OS04_05.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>

DWORD WINAPI OS04_02_T1() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 50; ++i) {
        Sleep(1000);
        std::cout << i << ": T1 PID = " << pid << ", TID = " << tid << std::endl;
    }

    return 0;
}

DWORD WINAPI OS04_02_T2() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 125; ++i) {
        Sleep(1000);
        std::cout << i << ": T2 PID = " << pid << ", TID = " << tid << std::endl;
    }

    return 0;
}

int main() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();
    DWORD childId_T1, childId_T2 = NULL;

    HANDLE hChild1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_02_T1, NULL, 0, &childId_T1);
    HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_02_T2, NULL, 0, &childId_T2);

    for (int i = 0; i < 100; ++i) {
        Sleep(1000);
        std::cout << i << ": Parent Thread PID = " << pid << ", TID = " << tid << std::endl;
        if (i == 40) {
            TerminateThread(hChild2, 1);
            std::cout << "\n\n ---- Thread T2 terminated ---- \n\n";
        }
    }

    WaitForSingleObject(hChild1, INFINITE);
    WaitForSingleObject(hChild2, INFINITE);

    CloseHandle(hChild1);
    CloseHandle(hChild2);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
