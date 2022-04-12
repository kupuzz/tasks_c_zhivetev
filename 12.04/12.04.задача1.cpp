// 12.04.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct APP 
{
    int start;
    int stop;
};

void enter(int N, APP * a )
{
    std::cout << "Number, " << "Start, " << "Stop:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << i << " ";
        std::cin >> a[i].start;
        std::cout << " ";
        std::cin >> a[i].stop;
    }
    return;
}

void sort(APP* app, int N, int* a)
{
    int p = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (app[a[i]].stop > app[a[i + 1]].stop)
        {
            int k = a[i];
            a[i] = a[i + 1];
            a[i + 1] = k;
            p = 1;
        }
        if (app[a[i]].stop == app[a[i + 1]].stop && app[a[i]].start > app[a[i + 1]].start)
        {
            int k = a[i];
            a[i] = a[i + 1];
            a[i + 1] = k;
            p = 1;
        }
    }
    if (p == 1)
    {
        sort(app, N, a);
    }
    if (p == 0)
    {
        return;
    }
}

void work(APP* app, int N, int *a, int k)
{
    std::cout << a[k] << " ";
    for (int i = k + 1; i < N; i++)
    {
        if (app[a[i]].start >= app[a[k]].stop)
        {
            work(app, N, a, i);
            return;
        }
    }
    return;
}

int main()
{
    int N;
    std::cout << "number of application: ";
    std::cin >> N;
    APP* app = new APP[N];
    int *a = new int[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    enter(N, app);
    sort(app, N, a);
    work(app, N, a, 0);
    delete[] app;
    delete[] a;
}

