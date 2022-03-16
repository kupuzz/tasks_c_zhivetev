// Лаба2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <numbers>
#include <cmath>
#include <iomanip>

float easy(float const psi[], float const pdf[], float const dv, int const size)
{
    float sum = 0;
    for (int v = 0; v < size; v++)
    {
        sum += psi[v] * pdf[v];
    }
    return dv * sum;
}

float rec(float const psi[], float const pdf[], float const dv, int size, int start)
{
    if (size == 1)
    {
        return psi[start] * pdf[start] * dv;
    }
    return (rec(psi, pdf, dv, size / 2, start) + rec(psi, pdf, dv, size - size / 2, start + size / 2));
}

float sum(float const psi[], float const pdf[], float const dv, int const size)
{
    float sum = 0;
    float* x = new float[10000001];
    x[0] = 0;
    for (int i = 0; i < size; i++)
    {
        x[i] = psi[i] * pdf[i];
    }
    int h = size - 1;
    int d = 1;
    while (h > 0)
    {
            for (int k = 0; k <= h; k += 2 * d)
            {
                if ((k + 2 * d) % (2 * d) == 0 && k + 2 * d == h)
                {
                    x[k] = x[k] + x[k + d] + x[k + 2 * d];
                }
                else
                {
                    x[k] = x[k] + x[k + d];
                }
            }
            if (h % (2 * d) == 0)
            {
                h -= 2 * d;
            }
            else
            {
                h -= d;
            }
            d *= 2;
    }
    sum = x[0];
    delete[] x;
    return sum * dv;
}

float kohan(float const psi[], float const pdf[], float const dv, int const size)
{
    float sum = 0;
    float t = 0;
    for (int k = 1; k < size; k++)
    {
        float y = psi[k] * pdf[k] - t;
        float z = sum + y;
        t = (z - sum) - y;
        sum = z;
    }
    return sum * dv;
}

float FMA(float const psi[], float const pdf[], float const dv, int const size)
{
    float sum = 0;
    for (int k = 0; k < size; k++)
    {
        sum = std::fma(psi[k], pdf[k], sum);
    }
    return sum * dv;
}

double di(double const psi[], double const pdf[], double const dv, int const size)
{
    double sum = 0;
    for (int v = 0; v < size; v++)
    {
        sum += psi[v] * pdf[v];
    }
    return dv * sum;
}

int main()
{
    double const pi = 3.14159265359;
    double const e = 2.718281828459;
    const int size = 10000001;
    float* psi = new float[size];
    float* pdf = new float[size];
    float dv = 0.001f;
    for (int k = 0; k < size; k++)
    {
        psi[k] = fabs( - (size + 1) * dv / 2 + k * dv);
    }
    for (int k = 0; k < size; k++)
    {
        pdf[k] = pow(300 * pi, (-0.5)) * pow(e, ( - psi[k] * psi[k] / 300));
    }
    std::cout << std::setprecision(10) << std::fixed;
    std::cout << "calc:   " << pow((300 / pi), (0.5)) << "\n";
    std::cout << "easy:   " << easy(psi, pdf, dv, size) << "\n";
    std::cout << "rec:    " << rec(psi, pdf, dv, size, 0) << "\n";
    std::cout << "sum:    " << sum(psi, pdf, dv, size) << "\n";
    std::cout << "kohan:  " << kohan(psi, pdf, dv, size) << "\n";
    std::cout << "fma:    " << FMA(psi, pdf, dv, size) << "\n";
    delete[] psi;
    delete[] pdf;
    double* psi1 = new double[size];
    double* pdf1 = new double[size];
    double dv1 = 0.001;
    for (int k = 0; k < size; k++)
    {
        psi1[k] = fabs(-(size + 1) * dv1 / 2 + k * dv1);
    }
    for (int k = 0; k < size; k++)
    {
        pdf1[k] = pow(300 * pi, (-0.5)) * pow(e, (-psi1[k] * psi1[k] / 300));
    }
    std::cout << "double: " << di(psi1, pdf1, dv, size) << "\n";
    delete[] psi1;
    delete[] pdf1;
}

