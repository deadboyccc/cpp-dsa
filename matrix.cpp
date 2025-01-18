#include <iostream>
class matrix
{
private:
    int *A;
    int n;

public:
    matrix(int size)
    {
        this->n = size;
        A = new int[size];
    }
    ~matrix()
    {
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};
void matrix::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i] = x;
    }
}
int matrix::get(int i, int j)
{
    if (i == j)
    {
        return A[i];
    }
    else
    {
        return 0;
    }
}
void matrix ::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                std::cout << A[i] << " ";
            }
            else
            {
                std::cout << 0 << " ";
            }
        }
        std::cout << "\n";
    }
}
int main(int argc, char const *argv[])
{

    matrix test(4);
    test.set(0, 0, 1);
    test.set(1, 1, 2);
    test.set(2, 2, 4);
    test.set(3, 3, 8);
    test.set(4, 4, 16);
    test.display();

    return 0;
}
