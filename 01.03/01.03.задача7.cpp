// 01.03.задача7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void rec(int* a, int n, int k)
{
    if (2 * n + 2 <= k)
    {
        if (a[2 * n + 2] >= a[n] && a[2 * n + 2] >= a[2 * n + 1])
        {
            int b;
            b = a[n];
            a[n] = a[2 * n + 2];
            a[2 * n + 2] = b;
            if (2 * (2 * n + 2) + 1 <= k)
            {
                rec(a, 2 * n + 2, k);
            }
        }
        else if (a[2 * n + 1] >= a[n] && a[2 * n + 1] >= a[2 * n + 2])
        {
            int b;
            b = a[n];
            a[n] = a[2 * n + 1];
            a[2 * n + 1] = b;
            if (2 * (2 * n + 1) + 1 <= k)
            {
                rec(a, 2 * n + 1, k);
            }
        }
        else if (n - 1 >= 0)
        {
            rec(a, n - 1, k);
        }
    }
    else if (2 * n + 1 == k)
    {
        if (a[2 * n + 1] >= a[n] )
        {
            int b;
            b = a[n];
            a[n] = a[2 * n + 1];
            a[2 * n + 1] = b;
        }
        else if (n - 1 >= 0)
        {
            rec(a, n - 1, k);
        }
    }
    if (n - 1 >= 0)
    {
        rec(a, n - 1, k);
    }
    else
    {
        return;
    }
}

void work(int* a, int k)
{
    rec(a, k/2, k);
    int b;
    b = a[k];
    a[k] = a[0];
    a[0] = b;
    if (k - 1 >= 0)
    {
        work(a, k - 1);
    }
    else
    {
        return;
    }
}

void enter(int* a, int x)
{
    for (int i = 0; i < x; i++)
    {
        std::cin >> a[i];
    }
}

void show(int* a, int x)
{
    for (int i = 0; i < x; i++)
    {
        std::cout << a[i] << " ";
    }
}

int main()
{
    const int x = 10;//размер сортируемого массива
    int a[x];
    enter(a, x);
    work(a, x - 1);
    show(a, x);
}
