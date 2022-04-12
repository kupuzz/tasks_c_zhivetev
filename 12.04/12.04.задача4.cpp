// 12.04.задача4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void enter(int N, int *a)//вводятся длины дорог в виде 0 х х
                                                    // 0 0 x
                                                    // 0 0 0 (отмеченные х, по строкам)
{
    for (int i = 0; i < N * N; i++)
    {
        if (i / N == (i - (i / N) * N) % N)
        {
            a[i] = 0;
        }
        else if (a[i] != 0)
        {
            i += 1;
        }
        else
        {
            std::cin >> a[i];
            a[((i - (i / N) * N) % N) * N + i / N] = a[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << a[j + i * N]<<" ";
        }
        std::cout << "\n";
    }
}

int sort(int N, int* b, int* a, int k, int z)
{
    int l = 10000;
    int n = -1;
    for (int i = z * N; i < z * N + N; i++)
    {
        if (a[i] < l && a[i] != 0)
        {
            l = a[i];
            n = i - z * N;
        }
    }
    for (int j = 0; j <= k; j++)
    {
        if (b[j] == n)
        {
            a[z * N + n] = 0;
            n = sort(N, b, a, k, z);
            break;
        }
    }
    return n;
}

void work(int N, int* b, int* a, int k, int z)
{
    if (k < N)
    {
        b[k] = z;
        work(N, b, a, k + 1, sort(N, b, a, k, z));
        return;
    }
    else
    {
        return;
    }
}

int main()
{
    int N;//количество городов
    std::cin >> N;
    int* a = new int[N * N];
    for (int i = 0; i < N * N; i++)
    {
        a[i] = 0;
    }
    enter(N, a);
    int* b = new int[N];
    work(N, b, a, 0, 0);
    for (int y = 0; y < N; y++)
    {
        std::cout << b[y];
    }
    delete[]a;
    delete[]b;
}

