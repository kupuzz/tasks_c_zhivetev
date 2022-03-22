// 22.03.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int work(int const* a, int const N)
{
    int b = N;
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] < 0)
        {
            for (int k = i + 1; k < N; k++)
            {
                if (-a[i] == a[k])
                {
                    c = k - i;
                    break;
                }
            }
        }
        if (c < b)
        {
            b = c;
        }
    }
    if (b != N)
    {
        return b;
    }
    else
    {
        return 0;
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
    std::cout << work(a, N) << "\n";
    delete[] a;
}


