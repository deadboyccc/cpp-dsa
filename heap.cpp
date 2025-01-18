#include <iostream>

// insert create delete and sort
// insert takes an array + n
void insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];
    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}
// create

void create(int h[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        insert(h, i);
    }
}
// delete
int removeHeap(int a[], int n)
{
    int i, j, x, deleted;

    deleted = a[1];
    x = a[n];
    a[1] = a[n];
    a[n] = deleted;
    i = 1;
    j = i * 2;
    while (j < n - 1)
    {
        if (a[j + 1] > a[j])
        {
            j++;
        }
        if (a[i] < a[j])
        {
            std::swap(a[i], a[j]);
            i = j;
            j = j * 2;
        }
        else
        {
            break;
        }
    }
    return deleted;
}
// sort
void heapSort(int a[], int n)
{
    for (int i = n; i > 0; i--)
    {
        removeHeap(a, i);
    }
}

int main(int argc, char const *argv[])
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    create(H, 7);
    heapSort(H, 7);
    for (auto element : H)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    int n = sizeof(H) / sizeof(int);

    return 0;
}
