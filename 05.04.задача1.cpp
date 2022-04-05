// 05.04.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Unit
{
    int key;
    Unit* next;
};

void app(Unit **a) //Добавление нвоого элемента
{
    Unit* b = new Unit;
    std::cin >> b->key;
    b->next = *a;
    *a = b;
    return;
}

void dlt(Unit **a) //Удаление списка
{
    if (*a = nullptr)
    {
        return;
    }
    else
    {
        Unit* b;
        Unit* c = *a;
        while (c != nullptr)
        {
            b = c;
            c = c->next;
            delete b;
        }
    }
    return;
}

void print(Unit *a) //Распечатка
{
    if (a == nullptr)
    {
        std::cout << "-";
    }
    else
    {
        Unit* b = a;
        while (b != nullptr)
        {
            std::cout << b->key << " ";
            b = b->next;
        }
        std::cout << "\n";
    }
    return;
}

void appstr(Unit **a) //Добавление в упорядоченный по возрастанию!
{
    if (*a == nullptr)
    {
        app(a);
        return;
    }
    Unit* b = new Unit;
    std::cin >> b->key;
    Unit* c = *a;
    while (c->next != nullptr)
    {
        if (c->key < b->key && c->next->key >= b->key)
        {
            Unit* d = c->next;
            c->next = b;
            b->next = d;
            return;
        }
        else
        {
            c = c->next;    
        }
    }
        if (b->key >= c->key)
        {
            c->next = b;
            b->next = nullptr;
        }
        else
        {
            b->next = *a;
            *a = b;
        }
    return;
}

void dltkey(Unit **a) //Удаление по значению
{
    if (*a == nullptr)
    {
        return;
    }
    int b;
    std::cin >> b;
    Unit* c = *a;
    if ((*a)->key == b)
    {
        *a = c->next;
        delete c;
        return;
    }
    else 
    {
        while (c->next != nullptr)
        {
            if (c->next->key == b)
            {
                Unit* d = c->next;
                c->next = d->next;
                delete d;
                return;
            }
            c = c->next;
        }
    }
    return;
}

int main()
{
    Unit* a = nullptr;
    for (int i = 0; i < 5; i++)//Ввод пяти элементов
    {
        app(&a);
    }
    print(a);//Проверка работы ввода и распечатки
    appstr(&a);//Вставка в упорядоченный
    print(a);//Проверка вставки в упорядоченный
    dltkey(&a);//Удаляем по значению
    print(a);//Проверяем удаление по значению
    dlt(&a);//Удаляем список
    print(a);//Проверка работы удаления
}

