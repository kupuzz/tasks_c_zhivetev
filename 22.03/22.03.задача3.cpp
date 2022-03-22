// 22.03.задача3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void my_personal_swap(int* a, int* b)
{
	if (a == nullptr || b == nullptr)
	{
		return;
	}
	else
	{
		int z;
		z = *a;
		*a = *b;
		*b = z;
	}
	return;
}

int main() 
{
	int a, b;
	cin >> a >> b;
	my_personal_swap(&a, &b);
	cout << a << " " << b << endl;
	my_personal_swap(&a, nullptr);
	my_personal_swap(nullptr, &b);
	my_personal_swap(nullptr, nullptr);
	return 0;
}
