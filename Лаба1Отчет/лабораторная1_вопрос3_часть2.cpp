// лабораторная1_вопрос3_часть2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int check(int x, int y, int* j)
{
    for (int p = 0; p < x * y; p++)
    {
        if (j[p] == 1)
        {
            if (p % y + 1 == 1 || p % y + 1 == y ||
                j[p - 1] == 1 || j[p + 1] == 1 ||
                j[p - 1] == 2 || j[p + 1] == 2) {
                j[p] = 2;
            }
        }
    }
    return 0;
}

int spawn(int x, int y, int a, int* j)
{
    for (int p = 0; p < a * (x * y) / 100; p++)
    {
        int k = rand() % (x * y);
        if (j[k] != 1) { j[k] = 1; }
        else { p -= 1; }
    }
    check(x, y, j);
    return 0;
}

int move(int x, int y, int* j)
{
    int d[300];//ЗДЕСЬ НУЖНО МЕНЯТЬ РАЗМЕР МАССИВА ПРИ ИЗМЕНЕНИИ X, Y
    for (int p = 0; p < x * y; p++) { d[p] = j[p]; }
    for (int p = 0; p < x * y; p++)
    {
        if (j[p] == 1)
        {
            int v = rand() % 2;
            if (v == 0 && p % y + 1 >= 2 && d[p - 1] == 0) { d[p - 1] = 1; d[p] = 0; }
            if (v == 1 && p % y + 1 <= y - 1 && d[p + 1] == 0) { d[p + 1] = 1; d[p] = 0; }
        }
    }
    for (int p = 0; p < x * y; p++) { j[p] = d[p]; }
    return 0;
}

int visual(int x, int y, int* j)
{
    for (int g = 0; g < x; g++)
    {
        for (int z = 0; z < y; z++)
        {
            std::cout << j[g * y + z] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}


int stop(int x, int y, int* j)
{
    for (int p = 0; p < x * y; p++)
    {
        if (j[p] == 1) { return 1; }
    }
    return 0;
}

double work(int x, int y, int a)
{
    double q = 0;
    int t[1000];
    for (int r = 0; r < 1000; r++) { t[r] = 0; }
    for (int z = 0; z < 1000; z++)
    {
        int j[300];//ЗДЕСЬ НУЖНО МЕНЯТЬ РАЗМЕР МАССИВА ПРИ ИЗМЕНЕНИИ X, Y
        for (int g = 0; g < x * y; g++) { j[g] = 0; }
        spawn(x, y, a, j);
        while (stop(x, y, j))
        {
            move(x, y, j);
            check(x, y, j);
            t[z]++;
        }
        q += t[z];
    }
    return q / 1000;
}

int counting()
{
    for (int a = 11; a < 100; a += 10)
    {
        int x = 1, y = 300;
        std::cout << "a:  " << a << "%   t_all:  " << work(x, y, a) << "\n";
    }
    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    counting();
}
