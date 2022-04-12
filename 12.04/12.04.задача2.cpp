// 12.04.задача2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>

int enter(int* a, int N)
{
    int c;
    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + N);
    std::cin >> c;
    return c;
}

void work(int c, int* a, int N)
{
    if (c != 0)
    {
        if (c / a[N - 1] > 0)
        {
            
            std::cout << c / a[N - 1] << " * ''" << a[N - 1] << "'' ; ";
            work(c - (c / a[N - 1]) * a[N - 1], a, N - 1);
        }
        else
        {
            work(c, a, N - 1);
        }
    }
    else 
    {
        return;
    }
}

int main()
{
    int N;
    std::cout << "Number of coins: ";
    std::cin >> N;
    int* a = new int[N];
    int c = enter(a, N);
    work(c, a, N);
    delete[] a;
}

