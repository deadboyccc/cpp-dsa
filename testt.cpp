#include "pch.h"
void printAdd(std::initializer_list<int> nums)
{
    // basically this is a function to add nums (nums being arbitrary number of ints)
    for (int i : nums)
    {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    // this will print each element of the list separated by a space
}

int main(int argc, char const *argv[])
{
    // btw vector is just a dynamic array in c++ fully impelmeented by the langauge
    std::vector<int> a{100, 23, 378, 24, 25, 6};
    // basically a stack of type int
    // this is adynamic array a = an object of type vector(which is just a dyanamic array)
    a.push_back(100);
    a.push_back(2000);
    std::sort(a.begin(), a.end());
    int b = std::accumulate(a.begin(), a.end(), 0);
    std::cout << b << std::endl;
    for (auto item : a)
    {
        std::cout << item << " ";
    }

    // u can use each element + capacity +
    // but it's nto the best debugger out there for sure XD
    return 0;
}
