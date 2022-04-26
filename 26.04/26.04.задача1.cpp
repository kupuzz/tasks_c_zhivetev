// 26.04.задача1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct BinaryTree
{
    BinaryTree* left;
    BinaryTree* right;
    int data;
};

void enter(BinaryTree** t, int a)
{
    if (*t == NULL)
    {
        *t = new BinaryTree;
        (*t)->data = a;
        (*t)->left = NULL;
        (*t)->right = NULL;
        return;
    }
    if (a > (*t)->data)
    {
        enter(&(*t)->right, a);
    }
    else
    {
        enter(&(*t)->left, a);
    }
}

void print(BinaryTree* t)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        std::cout << "(";
        print(t->left);
        std::cout << t->data;
        print(t->right);
        std::cout << ")";
    }
}

int main()
{
    int a;
    std::cin >> a;
    BinaryTree* t = NULL;
    while (a != 0)
    {
        enter(&t, a);
        std::cin >> a;
    }
    print(t);
}

