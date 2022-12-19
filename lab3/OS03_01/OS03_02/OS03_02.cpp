// OS03_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
    LPCWSTR an1 = L"D:\\University\\OS\\lab3\\OS03_01\\Debug\\OS03_02_1.exe";
    STARTUPINFO si1;
    PROCESS_INFORMATION pi1;
    ZeroMemory(&si1, sizeof(STARTUPINFO));
    si1.cb = sizeof(STARTUPINFO);
    if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
    {
        cout << "Process OS03_02_1 created" << endl;
    }
    else 
    {
        cout << "Process OS03_02_1 NOT created" << endl;
    }

    LPCWSTR an2 = L"D:\\University\\OS\\lab3\\OS03_01\\Debug\\OS03_02_2.exe";
    STARTUPINFO si2;
    PROCESS_INFORMATION pi2;
    ZeroMemory(&si2, sizeof(STARTUPINFO));
    si2.cb = sizeof(STARTUPINFO);
    if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
    {
        cout << "Process OS03_02_2 created" << endl;
    }
    else
    {
        cout << "Process OS03_02_2 NOT created" << endl;
    }


    for (int i = 0; i < 100; i++) {
        std::cout << "PID " << GetCurrentProcessId() << std::endl;
        Sleep(1000);
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);

    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);

    return 0;
}

