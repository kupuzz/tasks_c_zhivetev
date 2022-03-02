// 01.03.задача3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void rec(int s,int n)
{
    int a;
    std::cin >> a;
    if (a != 0)
    {
        s += a;
        n += 1;
        rec(s, n);
    }
    if (a == 0)
    {
        if (n != 0)
        {
            std::cout << s / n;
        }
        else 
        {
            std::cout << 0;
        }
    }
}


int main()
{
    rec(0, 0);
}
