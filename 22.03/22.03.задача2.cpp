// 22.03.задача2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void work(int* a, int N)
{
    if (N % 2 == 1)
    {
        for (int i = N - 1; i >= 0; i -= 2)
        {
            std::cout << a[i];
        }
        for (int i = N - 2; i >= 0; i -= 2)
        {
            std::cout << a[i];
        }
    }
    else
    {
        for (int i = N - 2; i >= 0; i -= 2)
        {
            std::cout << a[i];
        }
        for (int i = N - 1; i >= 0; i -= 2)
        {
            std::cout << a[i];
        }
    }
}

int main()
{
    int N;
    std::cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
    work(a, N);
    delete[] a;
}

