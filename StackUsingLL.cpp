#include <iostream>
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr)
    {
    }
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList
{
public:
    Node *top;
    LinkedList() : top(nullptr) {}
    void push(int a);
    int pop();
    int isFull();
    int isEmpty();
};
int LinkedList::isEmpty()
{
    if (!top)
    {
        std::cout << "Stack Underflow";
        return 1;
    }
    return 0;
}
int LinkedList::isFull()
{
    Node *t = new Node();
    return !t;
}
void LinkedList::push(int a)
{
    if (!isFull())
    {
        Node *t = new Node(a);
        t->next = top;
        top = t;
    }
    else
    {
        std::cout << "Stack Overflow" << std::endl;
    }
}
int LinkedList::pop()
{
    int x = -1;
    if (!isEmpty())
    {
        Node *t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}
int main(int argc, char const *argv[])
{
    std::string exp = "[{()}]";

    LinkedList test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << test.pop() << " ";
    }

    return 0;
}
