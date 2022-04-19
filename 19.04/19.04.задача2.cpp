// 19.04.задача2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int work(int n)
{
    int* a = new int[n];
    int* b = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    b[0] = 0;
    if (n > 1)
    {
        b[1] = abs(a[1] - a[0]);
    }
    for (int i = 2; i < n; i++)
    {
        b[i] = std::min(b[i - 1] + abs(a[i] - a[i - 1]), b[i - 2] + 3 * abs(a[i] - a[i - 2]));
    }
    int m = b[n-1];
    delete[] a, b;
    return m;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << work(n);
}

