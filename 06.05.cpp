#include <iostream>
#include <queue>

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

void queue(BinaryTree* t, int* b, int i)
{
    std::queue <BinaryTree*> q;
    q.push(t);
    b[0] = t->data;
    while (q.empty() == false)
    {
        if (q.front()->left != NULL && q.front()->right != NULL)
        {
            q.push(q.front()->left);
            b[i + 1] = q.front()->left->data;
            q.push(q.front()->right);
            b[i + 2] = q.front()->right->data;
            i += 2;
        }
        else if (q.front()->left == NULL && q.front()->right != NULL)
        {
            q.push(q.front()->right);
            b[i + 1] = q.front()->right->data;
            i++;
        }
        else if (q.front()->left != NULL && q.front()->right == NULL)
        {
            q.push(q.front()->left);
            b[i + 1] = q.front()->left->data;
            i++;
        }
        q.pop();
    }
}

void space(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << " ";
    }
}

int main()
{
    int a;
    std::cin >> a;
    BinaryTree* t = NULL;
    int n = 0;
    while (a != 0)
    {
        enter(&t, a);
        std::cin >> a;
        n += 1;
    }
    int* b = new int[n];
    queue(t, b, 0);
    int k = 0;
    for (int i = 0; i <= log(n+1) / log(2); i++)
    {
        space(50 - pow(2, i)+1);
        for (int j = k; j < k+pow(2, i) && j < n; j++)
        {
            std::cout << b[j] << " ";
        }
        std::cout << "\n";
        k += pow(2, i);
    }
}
