// 08.02.задача2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
static int k;

int func()
{
    int N, i, a, c;
    k = 1;
    c = 2147483647;
    std::cin >> N;
    for (i = 1; i < N+1; i++)
    {
        std::cin >> a;
        if (a == c)
        {
            k++;
        }
        if (a < c) 
        {
            c = a;
            k = 1;
        }
    }
    return c;
}

int main()
{
    int e;
    e = func();
    std::cout << "Min:" << e<<"\n";
    std::cout << "Repetitions:" << k;
}

