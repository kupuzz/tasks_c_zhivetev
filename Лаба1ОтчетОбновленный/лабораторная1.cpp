// лабораторная1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

//v отвечает за модернизацию программы: v = 0 - старый вариант(один тип дислокаций), v = 1 - два типа дислокаций.

int check(int x, int y, int* j, int v)
{
    for (int p = 0; p < x * y; p++)
    {
        if (j[p] == 1)
        {
            if (p / y + 1 == 1 || p % y + 1 == 1 || p / y + 1 == x || p % y + 1 == y ||
                j[p - y] == 1 || j[p - 1] == 1 || j[p + y] == 1 || j[p + 1] == 1 ||
                j[p - y] == 2 || j[p - 1] == 2 || j[p + y] == 2 || j[p + 1] == 2)
            {
                j[p] = 2;
            }
        }
        if (v == 1)
        {
            if (j[p] == 3)
            {
                if (p / y + 1 == 1 || p % y + 1 == 1 || p / y + 1 == x || p % y + 1 == y ||
                    j[p - y] == 3 || j[p - 1] == 3 || j[p + y] == 3 || j[p + 1] == 3 ||
                    j[p - y] == 4 || j[p - 1] == 4 || j[p + y] == 4 || j[p + 1] == 4)
                {
                    j[p] = 4;
                }
            }
        }
    }
    return 0;
}

int spawn_2(int x, int y, int a, int* j, int v)
{
    for (int p = 0; p < a * (x * y) / 100; p++)
    {
        int k = rand() % (x * y);
        if (j[k] != 1 && j[k] != 3)
        {
            int m = rand() % 2;
            if (v == 1) 
            {
                if (m == 0)
                {
                    j[k] = 1;
                }
                if (m == 1)
                {
                    j[k] = 3;
                }
            }
            else
            {
                j[k] = 1;
            }
        }
        else { p -= 1; }
    }
    check(x, y, j, v);
    return 0;
}

int move_2(int x, int y, int* j, int v)
{
    int d[2500] = { 0 };
    for (int p = 0; p < x * y; p++) 
    {
        d[p] = j[p]; 
    }
    for (int p = 0; p < x * y; p++)
    {
        if (j[p] == 1)
        {
            int v = rand() % 4;
            if (v == 0 && p / y + 1 >= 2 && d[p - y] == 0) 
            { 
                d[p - y] = 1; d[p] = 0; 
            }
            if (v == 1 && p % y + 1 >= 2 && d[p - 1] == 0) 
            {
                d[p - 1] = 1; d[p] = 0; 
            }
            if (v == 2 && p / y + 1 <= x - 1 && d[p + y] == 0) 
            {
                d[p + y] = 1; d[p] = 0; 
            }
            if (v == 3 && p % y + 1 <= y - 1 && d[p + 1] == 0) 
            {
                d[p + 1] = 1; d[p] = 0;
            }
        }
        if (v == 1)
        {
            if (j[p] == 3)
            {
                int v = rand() % 4;
                if (v == 0 && p / y + 1 >= 2 && d[p - y] == 0)
                {
                    d[p - y] = 3; d[p] = 0;
                }
                if (v == 1 && p % y + 1 >= 2 && d[p - 1] == 0)
                {
                    d[p - 1] = 3; d[p] = 0;
                }
                if (v == 2 && p / y + 1 <= x - 1 && d[p + y] == 0)
                {
                    d[p + y] = 3; d[p] = 0;
                }
                if (v == 3 && p % y + 1 <= y - 1 && d[p + 1] == 0)
                {
                    d[p + 1] = 3; d[p] = 0;
                }
            }
        }
    }
    for (int p = 0; p < x * y; p++) 
    {
        j[p] = d[p];
    }
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
        if (j[p] == 1) 
        {
            return 1;
        }
        if (j[p] == 3)
        {
            return 1;
        }
    }
    return 0;
}

double work_2(int x, int y, int a, int v)
{
    const int w = 1000;//количество измерений для одной точки
    double q = 0;
    int t[w];
    for (int r = 0; r < w; r++) 
    {
        t[r] = 0; 
    }
    for (int z = 0; z < w; z++)
    {
        int j[2500];
        for (int g = 0; g < x * y; g++) 
        {
            j[g] = 0;
        }
        spawn_2(x, y, a, j, v);
        while (stop(x, y, j))
        {
            move_2(x, y, j, v);
            check(x, y, j, v);
            t[z]++;
        }
        q += t[z];
    }
    return q / w;
}

int counting_2(int v)
{
    for (int a = 14; a < 100; a += 1)
    {
        const int x = 50;
        const int y = 50;
        std::cout << "a:  " << a << "%   t_all:  " << work_2(x, y, a, v) << "\n";
    }
    return 0;
}

int spawn_1(int x, int y)
{
    int i = rand() % (x * y);
    return i;
}

int move_1(int x, int y, int i)
{
    int v = rand() % 4;
    if (v == 0 && i / y + 1 != 1) 
    {
        i -= y;
    }
    if (v == 1 && i % y + 1 != 1)
    { 
        i -= 1;
    }
    if (v == 2 && i / y + 1 != x)
    {
        i += y;
    }
    if (v == 3 && i % y + 1 != y)
    {
        i += 1;
    }
    return i;
}

double work_1(int x, int y)
{
    double q = 0;
    const int w = 4000;//количество измерений для одной точки
    int t[w];
    for (int r = 0; r < w; r++) 
    {
        t[r] = 0;
    }
    for (int j = 0; j < w; j++)
    {
        int i = spawn_1(x, y);
        while (i / y + 1 != 1 && i % y + 1 != 1 && i / y + 1 != x && i % y + 1 != y)
        {
            i = move_1(x, y, i);
            t[j]++;

        }
        q += t[j];
    }
    return q/w;
}

int counting_1()
{
    for (int e = 1; e <= 101; e += 10)
    {
        std::cout << "e:  " << e << "   t_all:  " << work_1(e, e) << "\n";
    }
    return 0;
}

int move_3_1(int x, int y, int i)
{
    int v = rand() % 2;
    if (v == 0 && i % y + 1 != 1) 
    {
        i -= 1;
    }
    if (v == 1 && i % y + 1 != y)
    {
        i += 1;
    }
    return i;
}

double work_3_1(int x, int y)
{
    double q = 0;
    const int w = 4000;
    int t[w];
    for (int r = 0; r < w; r++) 
    {
        t[r] = 0; 
    }
    for (int j = 0; j < w; j++)
    {
        int i = spawn_1(x, y);
        while (i % y + 1 != 1 && i % y + 1 != y)
        {
            i = move_3_1(x, y, i);
            t[j]++;
        }
        q += t[j];
    }
    return q / w;
}

int counting_3_1()
{
    for (int e = 1; e < 100; e += 10)
    {
        int x = 1;
        int y = e;
        std::cout << "e:  " << e << "   t_all:  " << work_3_1(x, y) << "\n";
    }
    return 0;
}

int check_3(int x, int y, int* j)
{
    for (int p = 0; p < x * y; p++)
    {
        if (j[p] == 1)
        {
            if (p % y + 1 == 1 || p % y + 1 == y ||
                j[p - 1] == 1 || j[p + 1] == 1 ||
                j[p - 1] == 2 || j[p + 1] == 2) 
            {
                j[p] = 2;
            }
        }
    }
    return 0;
}

int spawn_3(int x, int y, int a, int* j)
{
    for (int p = 0; p < a * (x * y) / 100; p++)
    {
        int k = rand() % (x * y);
        if (j[k] != 1) { j[k] = 1; }
        else { p -= 1; }
    }
    check_3(x, y, j);
    return 0;
}

int move_3_2(int x, int y, int* j)
{
    int d[300] = { 0 };
    for (int p = 0; p < x * y; p++) 
    {
        d[p] = j[p];
    }
    for (int p = 0; p < x * y; p++)
    {
        if (j[p] == 1)
        {
            int v = rand() % 2;
            if (v == 0 && p % y + 1 >= 2 && d[p - 1] == 0) 
            {
                d[p - 1] = 1; d[p] = 0;
            }
            if (v == 1 && p % y + 1 <= y - 1 && d[p + 1] == 0)
            {
                d[p + 1] = 1; d[p] = 0;
            }
        }
    }
    for (int p = 0; p < x * y; p++) 
    {
        j[p] = d[p];
    }
    return 0;
}

double work_3_2(int x, int y, int a)
{
    const int w = 1000;
    double q = 0;
    int t[w];
    for (int r = 0; r < w; r++) 
    {
        t[r] = 0;
    }
    for (int z = 0; z < w; z++)
    {
        int j[300];
        for (int g = 0; g < x * y; g++) 
        {
            j[g] = 0;
        }
        spawn_3(x, y, a, j);
        while (stop(x, y, j))
        {
            move_3_2(x, y, j);
            check_3(x, y, j);
            t[z]++;
        }
        q += t[z];
    }
    return q / w;
}

int counting_3_2()
{
    for (int a = 11; a < 100; a += 10)
    {
        const int x = 1;
        const int y = 300;
        std::cout << "a:  " << a << "%   t_all:  " << work_3_2(x, y, a) << "\n";
    }
    return 0;
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int h;
    std::cout << "1 - question 1, 2 - question 2, 3 - question 3, 0 - added question" << "\n";
    std::cin >> h;
    if (h == 1) 
    {
        counting_1(); 
    }
    if (h == 2) 
    {
        counting_2(0);
    }
    if (h == 3)
    {
        std::cout << "1 - analog 1, 2 - analog 2" << "\n";
        std::cin >> h;
        if (h == 1)
        {
            counting_3_1();
        }
        if (h == 2)
        {
            counting_3_2();
        }
    }
    if (h == 0)
    {
        counting_2(1);
    }
}