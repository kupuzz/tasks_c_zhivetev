// 29.03.задача2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

struct STUDENT
{
    std::string NAME;
    std::string SECONDNAME;
    int AGE = 0;
    int CLASS = 0;
    int H = 0;
    int MARKS[30] = {0};
};

void enter(STUDENT* S, int h)
{
    for (int i = 0; i < h; i++)
    {
        std::cin >> S[i].NAME;
        std::cin >> S[i].SECONDNAME;
        std::cin >> S[i].AGE;
        std::cin >> S[i].CLASS;
        std::cin >> S[i].H;
        for (int k = 0; k < S[i].H; k++)
        {
            std::cin >> S[i].MARKS[k];
        }
    }
    return;
}

void add_mark(STUDENT& s, int mark)
{
    s.H += 1;
    s.MARKS[s.H - 1] = mark;
    return;
}

void work(STUDENT* S, int h)
{
    int p = 0;
    for (int i = 0; i < h; i++)
    {
        float sum = 0;
        for (int k = 0; k < S[i].H; k++)
        {
            sum += S[i].MARKS[k];
        }
        float mid = sum / S[i].H;
        if (mid < 4.5)
        {
            add_mark(S[i], 5);
            p = 1;
        }
    }
    if (p == 1)
    {
        work(S, h);
    }
    if (p == 0)
    {
        return;
    }
}

void output(STUDENT* S, int h)
{
    for (int i = 0; i < h; i++)
    {
        std::cout << S[i].NAME << " ";
        std::cout << S[i].SECONDNAME << " ";
        std::cout << S[i].AGE << " ";
        std::cout << S[i].CLASS << " ";
        std::cout << S[i].H << "\n";
        for (int k = 0; k < S[i].H; k++)
        {
            std::cout << S[i].MARKS[k] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    const int h = 5;
    STUDENT S[h];
    enter(S, h);
    work(S, h);
    output(S, h);
}

