// 08.02.задача5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
static double x, y;

int func()
{
    double a1,b1,c1,a2,b2,c2;
    std::cin >> a1>> b1>> c1>> a2>> b2>> c2;
    if (a1 == a2 && b1 == b2)
    {
        return 0;
    }
    else
    {
        x = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
        y = (c2 * a1 - c1 * a2) / (a2 * b1 - b2 * a1);
    }
    return 1;
}

int main()
{
    int e;
    e = func();
    if (e == 1)
    {
        std::cout << "Coordinates:" << x << "," << y << "\n";
    }
    if (e == 0)
    {
        std::cout << "No\n";
    }
}

