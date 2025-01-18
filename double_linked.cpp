#include <iostream>
class node
{
public:
    node *prev;
    node *next;
    int data;
};
class dlink
{
public:
    node *first;
    node *last;
    dlink()
    {
        first = last = nullptr;
    }
    dlink(int a[], int n)
    {
        node *t;
        node *tail;
        first = new node();
        first->data = a[0];
        first->prev = first->next = nullptr;
        tail = first;
        for (int i = 1; i < n; i++)
        {

            t = new node();
            t->data = a[i];
            t->next = tail->next;
            t->prev = tail;
            tail->next = t;
            tail = t;
        }
    }
    void display()
    {
        node *p = first;
        while (p)
        {
            std::cout << p->data << "    ";
            p = p->next;
        }
    }
};
int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3};
    dlink test(a, 3);
    test.display();
    return 0;
}
