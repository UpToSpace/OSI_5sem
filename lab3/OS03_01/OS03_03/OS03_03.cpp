#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    DWORD pid = GetCurrentProcessId();

    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

    PROCESSENTRY32 peProccessEntry;
    peProccessEntry.dwSize = sizeof(PROCESSENTRY32);

    wcout << L"Current PID " << pid << endl << L"----------------" << endl;
    try {
        if (!Process32First(snap, &peProccessEntry)) {
            throw L"Process32First";
        }
        do {
            wcout << L"Name: " << peProccessEntry.szExeFile
                << L"\nPID: " << peProccessEntry.th32ProcessID;
            if (peProccessEntry.th32ProcessID == pid) {
                wcout << " --> current process";
            }
            wcout << L"\nParent PID: " << peProccessEntry.th32ParentProcessID;


            wcout << endl << L"---------------------" << endl;

        } while (Process32Next(snap, &peProccessEntry));
    }
    catch (char* msg) {
        wcout << L"ERROR: " << msg << endl;
    }
    system("pause");
}