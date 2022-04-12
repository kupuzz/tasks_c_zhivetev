// 12.04.задача3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct THING
{
    int p;
    int m;
};

void enter(THING *T, int N)
{
    for(int i = 0; i < N; i++)
    {
        std::cout << i << " ";
        std::cin >> T[i].p; 
        std::cout << " ";
        std::cin >> T[i].m;
    }
}

void sort(THING* T, int N, int* a)
{
    int p = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (T[a[i]].p < T[a[i + 1]].p)
        {
            int k = a[i];
            a[i] = a[i + 1];
            a[i + 1] = k;
            p = 1;
        }
    }
    if (p == 1)
    {
        sort(T, N, a);
    }
    if (p == 0)
    {
        return;
    }
}

void work(THING* T, int N, int* a, int M, int k)
{
    if (k < N && M > 0)
    {
        if (T[a[k]].m < M)
        {
            std::cout << "p = " << T[a[k]].p << " m = " << T[a[k]].m << ";\n";
            work(T, N, a, M - T[a[k]].m, k + 1);
        }
        else
        {
            std::cout << "p = " << T[a[k]].p << " m = " << M << ";\n";
            return;
        }
    }
    else
    {
        return;
    }
}

int main()
{
    int N;//количество разных предметов
    std::cin >> N;
    THING* T = new THING[N];//предметы
    int* a = new int[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    enter(T, N);
    int M;//вместимость рюкзака
    std::cin >> M;
    sort(T, N, a);
    work(T, N, a, M, 0);

    delete[] T;
    delete[] a;
}

