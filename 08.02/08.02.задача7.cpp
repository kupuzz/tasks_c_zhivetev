// 08.02.задача7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
static int w, a, s, d;

int func()
{
    int N, x, y, i;
    std::cin >> N;
    for(i=1;i<(N+1);i++)
    {
        std::cin >> x >> y;
        if (x > 0 && y > 0) 
        {
            w++;
        }
        if (x < 0 && y > 0)
        {
            a++;
        }
        if (x < 0 && y < 0)
        {
            s++;
        }
        if (x > 0 && y < 0)
        {
            d++;
        }
    }
    if (w > a && w > s && w > d)
    {
        return 1;
    }
    if (a > w && a > s && a > d)
    {
        return 2;
    }
    if (s > w && s > a && s > d)
    {
        return 3;
    }
    if (d > w && d > a && d > s)
    {
        return 4;
    }
}

int main()
{
    int e;
    e  = func();
    if (e == 1)
    {
        std::cout << "Number:" << e << "\n";
        std::cout << "Summary:" << w;
    }
    if (e == 2)
    {
        std::cout << "Number:" << e << "\n";
        std::cout << "Summary:" << a;
    }
    if (e == 3)
    {
        std::cout << "Number:" << e << "\n";
        std::cout << "Summary:" << s;
    }
    if (e == 4)
    {
        std::cout << "Number:" << e << "\n";
        std::cout << "Summary:" << d;
    }
}
