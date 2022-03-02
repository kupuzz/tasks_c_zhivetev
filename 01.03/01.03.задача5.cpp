// 01.03.задача5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int zero(int z)
{
    if ((z % 10) == 0)
    {
        z = z / 10;
        zero(z);
    }
    else if ((z % 10) != 0)
    {
        return z;
    }
}

int rec(int n, int z, int k)
{
    z += int(int(n / pow(10, k))*pow(10,8-k));
    n -= int(int(n / pow(10, k)) * pow(10, k));
    if (k != 0)
    {
        rec(n, z, k-1);
    }
    if (k == 0)
    {
        z = zero(z);
        return z;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::cout<<rec(n, 0, 9);
}
