#include "Player.h"
#include <iostream>
#include <print>
#include <vector>
#include <rectangle.h>
template <typename T>
T return_addition(T a, T b)
{
    return a + b;
}

int main()
{

    // std::println("I love C/c++, DSA and Linux!");
    // Rectangle<int> rect1(10, 20);
    // Rectangle<double> rect2(20.2, 30.3);
    // Rectangle<unsigned int> rect3(30, 40);
    // Rectangle<double> rect4(1000.1, 100000.203);
    // std::vector<Rectangle<double>> rectangles{rect2, rect4};
    // for (auto &item : rectangles)
    // {
    //     std::println("length:{}, width:{}", item.getLength(), item.getWidth());
    // }

    // std::println("first addition <int>:{} second <float> :{}", return_addition<int>(10, 20), return_addition<long double>(10.2, 20.4));
    Player first_one("Ahmed", 100, 100);
    // std::cout << first_one.getName() << std::endl;
    // std::cout << "----------------------------------------" << std::endl;
    // std::cout << "Constructors incoming | code above !" << std::endl;
    Player new_player(first_one);
    std::cout <<&new_player<< std::endl;
    return 0;
}