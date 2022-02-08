// 08.02.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>



int func()
{
    int a,c;
    c = 0;
    std::cin >> a;
    while (a != 0)
    {
        std::cin >> a;
        if (a % 2 == 0 && a > c)
        {
            c = a;
        }
    }
    return c;
}

int main()
{   
    int g;
    g = func();
    std::cout << "Answer:" << g;
}
