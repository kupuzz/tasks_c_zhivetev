// 03.01.задача2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

void rec()
{
    int a;
    std::cin >> a;
    if (a != 0)
    {
        std::cout << a << "\n";
    }
    std::cin >> a;
    if (a != 0)
    {
        rec();
    }

}


int main()
{
    rec();
}
