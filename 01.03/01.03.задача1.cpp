// 01.03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void rec()
{
    int a;
    std::cin >> a;
    if (a % 2 == 1)
    {
        std::cout << a << "\n";
    }
    if (a != 0)
    {
        rec();
    }

}


int main()
{
    rec();
}

