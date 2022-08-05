#include <iostream>
#include "queueCpp.h"
using namespace std;

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void createTree();
    void Preorder(Node *p);
    void Inorder(Node *p);
    void Postorder(Node *p);
    void Levelorder() { Levelorder(root); } // Passing Private Parameter in Constructor
    void Levelorder(Node *p);
    int Height() { return Height(root); } // Passing Private Parameter in Constructor
    int Height(Node *p);
    Node *getRoot() { return root; }
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    queue q(100);

    printf("Eneter root value ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::Levelorder(Node *p)
{
    queue q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << ", " << flush;
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << ", " << flush;
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node *p)
{
    int l = 0;
    int r = 0;
    if (p == nullptr)
    {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);
    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}

int main()
{
    Tree t;

    t.createTree();

    cout << "Preorder: " << flush;
    t.Preorder(t.getRoot());
    cout << endl;

    cout << "Inorder: " << flush;
    t.Inorder(t.getRoot());
    cout << endl;

    cout << "Postorder: " << flush;
    t.Postorder(t.getRoot());
    cout << endl;

    cout << "Levelorder: " << flush;
    t.Levelorder(t.getRoot());
    cout << endl;

    cout << "Height: " << t.Height(t.getRoot()) << endl;

    cout << "Recursive Passing Private Parameter in Constructor" << endl;

    cout << "Preorder: " << flush;
    t.Preorder(t.root);
    cout << endl;

    cout << "Inorder: " << flush;
    t.Inorder(t.root);
    cout << endl;

    cout << "Postorder: " << flush;
    t.Postorder(t.root);
    cout << endl;

    cout << "Levelorder: " << flush;
    t.Levelorder();
    cout << endl;

    cout << "Height: " << t.Height() << endl;
    return 0;
}