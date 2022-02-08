// 08.02.задача4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
static int M;
static int m;

int func()
{
    int N, i, a, c, d, q, w;
    c = 2147483647;
    d = 2147483647;
    q = 0;
    w = 0;
    std::cin >> N;
    for (i = 1; i < (N + 1); i++)
    {
        std::cin >> a;
        if (a <= d && c >= d)
        {
            c = a;
        }
        else if (a <= c && c <= d)
        {
            d = a;
        }
        else if (a <= d && c <= d)
        {
            d = a;
        }
        else if (a <= c && c >= d)
        {
            c = a;
        }
        if (a >= q && q >= w)
        {
            w = a;
        }
        else if (a >= w && w >= q)
        {
            q = a;
        }
        else if (a >= w && w <= q)
        {
            w = a;
        }
        else if (a >= q && w >= q)
        {
            q = a;
        }
    }
    M = q + w;
    m = c + d;
    return 0;
}

int main()
{
    func();
    std::cout << "Min:" << m << "\n";
    std::cout << "Max:" << M << "\n";
}
