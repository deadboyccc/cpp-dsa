
#include <iostream>
class matrix
{
private:
    int *A;
    int n;

public:
    matrix(int size) : n(size)
    {
        A = new int[n * (n - 1) / 2];
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
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j] = x;
    }
}
int matrix::get(int i, int j)
{
    if (i >= j)
    {
        return A[i * (i - 1) / 2 + j];
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
            if (i >= j)
            {
                std::cout << A[i * (i - 1) / 2 + j] << " ";
            }
            else
            {
                std::cout << 0 << " ";
            }
        }
        std::cout << std::endl;
    }
}
int main(int argc, char const *argv[])
{

    matrix test(4);
    // set the values for an upper value matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            test.set(i, j, i + j);
        }
    }
    test.display();
    std::cout << test.get(1, 1) << std::endl;
    std::cout << test.get(3, 2) << std::endl;

    return 0;
}
