// 01.03.задача4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

void rec(int b, int n)
{
    int a;
    std::cin >> a;
    if (a == b)
    {
        n++;
    }
    if (a > b)
    {
        b = a;
        n = 1;
    }
    if (a == 0)
    {
        std::cout << n;
    }
    if (a != 0)
    {
        rec(b, n);
    }
}

int main()
{
    rec(0, 0);
}
