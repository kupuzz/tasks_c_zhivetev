// 08.02.задача6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int func()
{
    double x, y, a, b, r;
    std::cin >> x >> y >> a >> b >> r;
    if (r * r < (x - a) * (x - a) + (y - b) * (y - b))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int e;
    e = func();
    if (e == 1)
    {
        std::cout << "Yes\n";
    }
    if (e == 0)
    {
        std::cout << "No\n";
    }
}
