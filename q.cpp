#include <iostream>
class queue
{
public:
    int size, front, back, *Q;
    queue(int s) : size(s), front(0), back(0)
    {
        Q = new int[size];
    };
    ~queue()
    {
        delete[] Q;
    };
    int isEmpty();
    int isFull();
    void enqueue(int a);
    int dequeue();
    void display();
};
int queue::isEmpty()
{
    if (front == back)
    {
        return 1;
    }
    return 0;
}
int queue::isFull()
{
    if ((back + 1) % size == front)
    {
        return 1;
    }
    return 0;
}
void queue::enqueue(int a)
{
    if (!isFull())
    {

        back = (back + 1) % size;
        Q[back] = a;
    }
    else
    {
        std::cout << " Queue Overflow! \n";
    }
}
int queue::dequeue()
{
    int x = -1;
    if (!isEmpty())
    {
        front = (front + 1) % size;
        x = Q[++front];
    }
    return x;
}
void queue::display()
{
    int i = front + 1;
    do
    {
        std::cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (back + 1) % size);
}
int main(int argc, char const *argv[])
{
    queue test(5);
    test.enqueue(10);
    test.enqueue(20);
    test.enqueue(30);
    test.enqueue(40);
    test.enqueue(50);
    test.enqueue(60);

    test.display();
    // //? Circular nature of the % operator
    // std::cout << "\n---------------------------\n";
    // for (int i = 1; i <= 18; i++)
    // {
    //     std::cout << i << "%6= " << i % 6 << " ";
    //     if (i % 6 == 0)
    //     {
    //         std::cout << "\n-----Completed Full Circle! -----\n";
    //     }
    // }
    return 0;
}
