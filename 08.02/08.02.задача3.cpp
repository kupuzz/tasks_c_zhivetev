// 08.02.задача3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>



int func()
{
    int a, b, c, d;
    c = 0;
    std::cin >> a;
    while (a != 0)
    {   
        b = a;
        std::cin >> a;
        if (a>b)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    int g;
    g = func();
    std::cout << "Answer:" << g;
}
