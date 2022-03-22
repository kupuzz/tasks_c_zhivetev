// 22.03.задача4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int work(int* a, int n)
{
    if (n == 1)
    {
        return a[0];
    }
    else
    {
        int sum = 0;
        for (int k = 0; k < n; k++)
        {
            int h = 0;
            int l = 0;
            int* b = new int[(n - 1) * (n - 1)];
            for (int i = 0; i < n*n; i++)
            {
                if (i == k + n * h)
                {
                    h += 1;
                } 
                else if (i>=n)
                {
                    b[l] = a[i];
                    l += 1;
                }
            }
            sum += pow(-1, k) * a[k] * work(b, n-1);
            delete[] b;
        }
        return sum;
    }
}

int main()
{
    int n;
    std::cin >> n;
    int* a = new int[n*n];
    for (int i = 0; i < n*n; i++)
    {
        std::cin >> a[i];
    }
    std::cout << work(a, n);
    delete[] a;
}
