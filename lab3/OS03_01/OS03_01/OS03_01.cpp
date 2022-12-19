// OS03_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>

int main()
{
    for (int i = 0; i < 1000; i++) {
        std::cout << "PID " << GetCurrentProcessId() << std::endl;
        Sleep(5000);
    }
}
