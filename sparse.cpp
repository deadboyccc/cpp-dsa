#include <iostream>
class Element
{
public:
    int i;
    int j;
    int x;
};
class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;

public:
    Sparse()
    {
        m = n = num = 0;
        ele = nullptr;
    }
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }
    void read()
    {
        for (int i = 0; i < num; i++)
        {
            std::cin >> this->ele[i].i >> this->ele[i].j >> this->ele[i].x;
        }
    }
    void display()
    {
        int k = 0;
        for (int i = 0; i < this->num; i++)
        {
            for (int j = 0; j < this->num; j++)
            {
                if (ele[k].i == i && ele[k].j == j)
                {
                    std::cout << ele[k++].x << " ";
                }
                else
                {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }

    Sparse *add(Sparse &s1)
    {
        Sparse *sum = new Sparse(this->m, this->n, this->num + s1.num);
        int i, j, k;
        if (m != s1.m || n != s1.n)
        {
            return nullptr;
        }
        i = j = k = 0;
        while (i < num && j < s1.num)
        {
            if (ele[i].i < s1.ele[j].i)
            {
                sum->ele[k++] = ele[i++];
            }
            else if (ele[i].i > s1.ele[j].i)
            {
                sum->ele[k++] = s1.ele[j++];
            }
            else
            {

                if (ele[i].j < s1.ele[j].j)
                {
                    sum->ele[k++] = ele[i++];
                }
                else if (ele[i].j > s1.ele[j].j)
                {
                    sum->ele[k++] = s1.ele[j++];
                }
                else
                {
                    sum->ele[k] = ele[i];
                    sum->ele[k++].x = ele[i++].x + s1.ele[j++].x;
                }
            }
        }
        for (; i < num; i++)
            sum->ele[k++] = ele[i];
        for (; j < num; j++)
            sum->ele[k++] = ele[j];
        sum->num = k;
        return sum;
    }
    void PrintDetails()
    {
        std::cout << "rows: " << this->m << " cols: " << this->n << std::endl;
    }
};
int main()
{
    Sparse s1(5, 5, 5);
    s1.read();
    s1.display();
    Sparse s2(5, 5, 2);
    s2.read();
    s2.display();
    Sparse *s3 = new Sparse();
    s3 = s1.add(s2);
    s3->display();
    return 0;
}
