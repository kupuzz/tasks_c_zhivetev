// 26.04.задача2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct AVLTree
{
    AVLTree* left;
    AVLTree* right;
    int data;
    int height;
};

int bf(AVLTree* p)
{
    if ((p->right) == NULL && (p->left) == NULL)
    {
        return 0;
    }
    if ((p->right) == NULL && (p->left) != NULL)
    {
        return -1;
    }
    if ((p->right) != NULL && (p->left) == NULL)
    {
        return 1;
    }
    else
    {
        return (p->right)->height - (p->left)->height;
    }
}

void newheight(AVLTree* p)
{
    if ((p->right) != NULL && (p->left) != NULL)
    {
        if ((p->right)->height <= (p->left)->height)
        {
            p->height = (p->left)->height + 1;
        }
        if ((p->right)->height >= (p->left)->height)
        {
            p->height = (p->right)->height + 1;
        }
    }
    else
    {
        p->height = 1;
    }
}

AVLTree* right(AVLTree* p)
{
    AVLTree* r = p->left;
    p->left = r->right;
    r->right = p;
    newheight(p);
    newheight(r);
    return r;
}

AVLTree* left(AVLTree* p)
{
    AVLTree* l = p->right;
    p->right = l->left;
    l->left = p;
    newheight(p);
    newheight(l);
    return l;
}

AVLTree* balance(AVLTree* p)
{
    newheight(p);
    if (bf(p) == 2)
    {
        if (bf(p->right) < 0)
        {
            p->right = right(p->right);
        }
        return left(p);
    }
    if (bf(p) == -2)
    {
        if (bf(p->left) > 0)
        {
            p->left = left(p->left);
        }
        return right(p);
    }
    return p;
}

void enter(AVLTree** t, int a)
{
    if (*t == NULL)
    {
        *t = new AVLTree;
        (*t)->data = a;
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->height = 1;
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
    balance(*t);
}

void print(AVLTree* t)
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
    AVLTree* t = NULL;
    while (a != 0)
    {
        enter(&t, a);
        std::cin >> a;
    }
    print(t);
}
