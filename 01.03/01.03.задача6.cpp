// 01.03.задача6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int rec(int n, char x)
{
    if (x == 'M')
    {
        if (n != 0)
        {
            return n - rec(rec(n - 1, 'M'), 'F');
        }
        if (n == 0)
        {
            return 0;
        }
    }
    if (x == 'F')
    {
        if (n != 0)
        {
            return n - rec(rec(n - 1,'F'), 'M');
        }
        if (n == 0)
        {
            return 1;
        }
    }
}

int main()
{
    int n;
    std::cin  >> n;
    std::cout << "M(n) :" << rec(n,'M')<<"\n";
    std::cout << "F(n) :" << rec(n,'F');
}

