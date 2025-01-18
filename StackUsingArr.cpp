#include <iostream>
#include <string>
class stack
{
private:
    int size;
    int top;
    int *stk;

public:
    stack(int s) : size(s), top(-1)
    {
        stk = new int[size];
    }
    int isEmpty();
    int isFull();
    void push(int a);
    int pop();
    void display();
    int peek(int index);
};
int stack::isEmpty()
{
    return (top == -1);
}
int stack::isFull()
{

    return (size - top - 1 == 0);
}
void stack::push(int a)
{
    if (isFull())
    {
        std::cout << "StackOverflow" << std::endl;
    }
    else
    {
        top++;
        std::cout << "top = " << top << ",Size = " << size << std::endl;
        this->stk[top] = a;
    }
}
int stack::pop()
{
    int x = -1;
    if (isEmpty())
    {
        std::cout << "StackUnderflow" << std::endl;
    }
    else
    {
        std::cout << "top = " << top << ",Size = " << size << std::endl;
        x = this->stk[top--];
    }
    return x;
}
void stack::display()
{
    while (!isEmpty())
    {
        std::cout << this->stk[top--] << "   ";
    }
    std::cout << std::endl;
}
int stack::peek(int index)
{
    int x = -1;
    if (top - index + 1 < 0)
    {
        std::cout << "Invalid Index" << std::endl;
    }
    x = stk[top - index + 1];
    // TOP - INDEX THEN + 1
    return x;
}
int main(int argc, char const *argv[])
{
    std::string test = "{[()]}";
    std::cout << isBalanced(test) ? "True" : "False";

    return 0;
}
