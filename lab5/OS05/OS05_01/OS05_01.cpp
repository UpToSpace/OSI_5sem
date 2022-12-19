// OS05_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

void getProcessPriority(HANDLE hp); 
void getThreadPriority(HANDLE ht);
void getAffinityMask(HANDLE hp, HANDLE ht);

int main()
{
	HANDLE processHandle = GetCurrentProcess();
	HANDLE threadHandle = GetCurrentThread();
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();

	cout << "PID: " << pid << "; TID: " << tid << endl;
	getProcessPriority(processHandle);
	getThreadPriority(threadHandle);
	getAffinityMask(processHandle, threadHandle);

	system("pause");
}

void getProcessPriority(HANDLE hp) {
	DWORD prty = GetPriorityClass(hp);

	switch (prty) {
	case IDLE_PRIORITY_CLASS:
		cout << "ProcessPriority: IDLE_PRIORITY_CLASS\n";
		break;
	case BELOW_NORMAL_PRIORITY_CLASS:
		cout << "ProcessPriority: BELOW_NORMAL_PRIORITY_CLASS\n";
		break;
	case NORMAL_PRIORITY_CLASS:
		cout << "ProcessPriority: NORMAL_PRIORITY_CLASS\n";
		break;
	case ABOVE_NORMAL_PRIORITY_CLASS:
		cout << "ProcessPriority: ABOVE_NORMAL_PRIORITY_CLASS\n";
		break;
	case HIGH_PRIORITY_CLASS:
		cout << "ProcessPriority: HIGH_PRIORITY_CLASS\n";
		break;
	case REALTIME_PRIORITY_CLASS:
		cout << "ProcessPriority: REALTIME_PRIORITY_CLASS\n";
		break;
	default: cout << "ERROR: PROCESS PRIORITY NOT RECOGNIZED\n\n"; break;
	}
}

void getThreadPriority(HANDLE ht) {
	DWORD prty = GetPriorityClass(ht);

	cout << "ThreadPriority: " << GetThreadPriority(ht) << " ";

	switch (prty) {
	case THREAD_PRIORITY_LOWEST:
		cout << "THREAD_PRIORITY_LOWEST\n";
		break;
	case THREAD_PRIORITY_BELOW_NORMAL:
		cout << "THREAD_PRIORITY_BELOW_NORMAL\n";
		break;
	case THREAD_PRIORITY_NORMAL:
		cout << "THREAD_PRIORITY_NORMAL\n";
		break;
	case THREAD_PRIORITY_ABOVE_NORMAL:
		cout << "THREAD_PRIORITY_ABOVE_NORMAL\n";
		break;
	case THREAD_PRIORITY_HIGHEST:
		cout << "THREAD_PRIORITY_HIGHEST\n";
		break;
	case THREAD_PRIORITY_IDLE:
		cout << "THREAD_PRIORITY_IDLE\n";
		break;
	default: cout << "ERROR: THREAD PRIORITY NOT RECOGNIZED\n\n"; break;
	}
}

void getAffinityMask(HANDLE hp, HANDLE ht) {
	DWORD pa = NULL, sa = NULL, icpu = -1;
	char buf[10];

	if (!GetProcessAffinityMask(hp, &pa, &sa)) {
		throw "GetProcessAffinityMask";
	}

	_itoa_s(pa, buf, 2);
	cout << "Process affinity Mask: " << buf << endl;
	_itoa_s(sa, buf, 2);
	cout << "System affinity Mask: " << buf << endl;

	SYSTEM_INFO sys_info;
	GetSystemInfo(&sys_info);
	cout << "Amount of available processors: " << sys_info.dwNumberOfProcessors << endl << endl;
	icpu = SetThreadIdealProcessor(ht, MAXIMUM_PROCESSORS);
	cout << "Thread IdealProcessor: " << dec << icpu << endl;


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
