// 19.04.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int work(int n)
{
    int* a = new int[n];
    int* b = new int[n];
    int m = 0;
    for (int j = 0; j < n; j++)
    {
        b[j] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                b[i] = std::max(b[i], b[j] + 1);
            }
        }
    }
    for (int r = 0; r < n; r++)
    {
        if (b[r] > m)
        {
            m = b[r];
        }
    }
    delete[] a, b;
    return m;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << work(n);
}

