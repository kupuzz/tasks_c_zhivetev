// 03.09.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Rect {
    int x;
    int y;
};

int comp_rect(void* a, void* b)
{
    int s1 = (*(Rect*)a).x * (*(Rect*)a).y;
    int s2 = (*(Rect*)b).x * (*(Rect*)b).y;
    if (s1 > s2)
    {
        return 1;
    }
    if (s1 < s2)
    {
        return -1;
    }
    if (s1 == s2)
    {
        return 0;
    }
}

int comp_double(void* a, void* b)
{
    if (*(double*)a > *(double*)b)
    {
        return 1;
    }
    if (*(double*)a < *(double*)b)
    {
        return -1;
    }
    if (*(double*)a == *(double*)b)
    {
        return 0;
    }
}

void swap(void* lha, void* rha, size_t element_byte_size)
{
    void* tmp = malloc(element_byte_size);
    memcpy(tmp, lha, element_byte_size);
    memcpy(lha, rha, element_byte_size);
    memcpy(rha, tmp, element_byte_size);
    free(tmp);
}

void sort(int (*comp)(void*, void*), void* a, size_t r, size_t n)
{
    if (n <= 1)
        return;
    void* x = (char*)a + r * (n - 1);
    int f = 1;
    for (int i = 0; i < n - 1; i++)
    {  
        void* e = (char*)a + r * i;
        if (f == 1 && comp(x, e) == 1)
        {
            swap(x, e, r);
            x = e;
            f = -1;
        }
        else if (f == -1 && comp(x, e) == -1)
        {
            while (x != e)
            {
                swap((char*)e - r, e, r);
                e = (char*)e - r;
            }
            x = (char*)x + r;
        }
    }
    sort(comp, a, r, ((char*)x - (char*)a) / r);
    sort(comp, (char*)x + r, r, n - 1 - ((char*)x - (char*)a) / r);
}

int main()
{
    int N1;
    std::cout << "number of rectangles"<<"\n";
    std::cin >> N1;
    Rect* a = new Rect [N1];
    std::cout << "parametres of rectangles"<<"\n";
    for (int i = 0; i < N1; i++)
    {
        std::cin >> a[i].x;
        std::cin >> a[i].y;
    }
    int N2;
    std::cout << "number of doubles" << "\n";
    std::cin >> N2;
    double* b = new double[N2];
    std::cout << "parametres of doubles" << "\n";
    for (int i = 0; i < N2; i++)
    {
        std::cin >> b[i];
    }
    sort(comp_rect, a, sizeof(Rect), N1);
    for (int i = 0; i < N1; i++)
    {
        std::cout << a[i].x << "," << a[i].y << ";";
    }
    std::cout << "\n";
    sort(comp_double, b, sizeof(double), N2);
    for (int i = 0; i < N2; i++)
    {
        std::cout << b[i]<<";";
    }
    std::cout << "\n";
    delete[] a;
    delete[] b;
}


