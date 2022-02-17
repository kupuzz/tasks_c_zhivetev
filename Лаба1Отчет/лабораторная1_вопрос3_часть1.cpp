// лабораторная1_вопрос3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int spawn(int x, int y)
{
    int i = rand() % (x * y);
    return i;
}

int move(int x, int y, int i)
{
    int v = rand() % 2;
    if (v == 0 && i % y + 1 != 1) { i -= 1; }
    if (v == 1 && i % y + 1 != y) { i += 1; }
    return i;
}

double work(int x, int y)
{
    double q = 0;
    int t[4000];
    for (int r = 0; r < 4000; r++) { t[r] = 0; }
    for (int j = 0; j < 4000; j++)
    {
        int i = spawn(x, y);
        while ( i % y + 1 != 1 && i % y + 1 != y)
        {
            i = move(x, y, i);
            t[j]++;

        }
        q += t[j];
    }
    return q / 4000;
}

int counting()
{
    for (int e = 1; e < 100; e += 10)
    {
        int x = 1;
        int y = e;
        std::cout << "e:  " << e << "   t_all:  " << work(x, y) << "\n";
    }
    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    counting();
}
