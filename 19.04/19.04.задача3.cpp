// 19.04.задача3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int work()
{
    int n;
    std::cin >> n;
    std::string* a = new std::string[n+1];
    for (int i = 0; i <= n; i++)
    {
        std::cin >> a[i];
    }
    int* b = new int[n+1];
    for (int i = 0; i <= n; i++)
    {
        int x = 0;
        int y = 0;
        if (a[i][0] == 'a')
        {
            x = 0;
        }
        if (a[i][0] == 'b')
        {
            x = 1;
        }
        if (a[i][0] == 'c')
        {
            x = 2;
        }
        if (a[i][0] == 'd')
        {
            x = 3;
        }
        if (a[i][0] == 'e')
        {
            x = 4;
        }
        if (a[i][0] == 'f')
        {
            x = 5;
        }
        if (a[i][0] == 'g')
        {
            x = 6;
        }
        if (a[i][0] == 'h')
        {
            x = 7;
        }
        if (a[i][1] == '1')
        {
            y = 0;
        }
        if (a[i][1] == '2')
        {
            y = 1;
        }
        if (a[i][1] == '3')
        {
            y = 2;
        }
        if (a[i][1] == '4')
        {
            y = 3;
        }
        if (a[i][1] == '5')
        {
            y = 4;
        }
        if (a[i][1] == '6')
        {
            y = 5;
        }
        if (a[i][1] == '7')
        {
            y = 6;
        }
        if (a[i][1] == '8')
        {
            y = 7;
        }
        b[i] = x + y * 8;
    }
    int* c = new int[64];
    for (int g = 0; g < 64; g++)
    {
        c[g] = 0;
    }
    c[b[n]] = 1;
    for (int i = b[n] + 7; i < 64; i++)
    {
        if (n > 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (b[j] == i)
                {
                    if (b[j] % 8 == 0)
                    {
                        if (i >= 8)
                        {
                            c[i] = c[i - 7];
                        }
                    }
                    else if (b[j] % 8 == 7)
                    {
                        if (i >= 15)
                        {
                            c[i] = c[i - 9];
                        }
                    }
                    else
                    {
                        if (i >= 9)
                        {
                            c[i] = c[i - 7] + c[i - 9];
                        }
                    }
                    break;
                }
                else
                {
                    if (i >= 8)
                    {
                        c[i] = c[i - 8];
                    }
                }
            }
        }
        else
        {
            c[i] = c[i - 8];
        }
    }
    int m = c[63] + c[62] + c[61] + c[60] + c[59] + c[58] + c[57] + c[56];
    delete[] a, b, c;
    return m;
}

int main()
{
    std::cout << work();
}

