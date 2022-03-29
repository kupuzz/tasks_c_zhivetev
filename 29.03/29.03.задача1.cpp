// 29.03.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

struct STUDENT
{
    std::string NAME;
    std::string FIRSTNAME;
    int GROUP = 0;
    int SES[5] = { 0,0,0,0,0 };
};

void enter(STUDENT* STUD1, int h)
{
    for (int i = 0; i < h; i++)
    {
        std::cin >> STUD1[i].NAME;
        std::cin >> STUD1[i].FIRSTNAME;
        std::cin >> STUD1[i].GROUP;
        for (int k = 0; k < 5; k++)
        {
            std::cin >> STUD1[i].SES[k];
        }
    }
    return;
}



void sort(STUDENT* STUD1, int h, int *a)
{
    int p = 0;
    for (int i = 0; i < h - 1; i++)
    {
        if (STUD1[a[i]].NAME.compare(STUD1[a[i + 1]].NAME) == 1)
        {
            int k = a[i];
            a[i] = a[i + 1];
            a[i + 1] = k;
            p = 1;
        }
    }
    if (p == 1)
    {
        sort(STUD1, h, a);
    }
    if (p == 0)
    {
        return;
    }
}

void work(STUDENT* STUD1, int h, int *a)
{
    int p = 0;
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (STUD1[a[i]].SES[k] == 2)
            {
                std::cout << STUD1[a[i]].NAME + ' ' + STUD1[a[i]].FIRSTNAME << ' ' << STUD1[a[i]].GROUP << '\n';
                p = 1;
                break;
            }
        }
    }
    if (p == 0)
    {
        std::cout << '0';
    }
    return;
}

int main()
{
    const int h = 10;
    STUDENT STUD1[h];
    int a[h];
    for (int i = 0; i < h; i++)
    {
        a[i] = i;
    }
    enter(STUD1, h);
    sort(STUD1, h, a);
    work(STUD1, h, a);
}

