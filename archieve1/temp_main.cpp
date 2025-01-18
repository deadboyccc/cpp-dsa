#include <iostream>
#include <memory>
#include <iomanip>
#include <math.h>
struct circle
{
    int r;
    circle(int r) : r(r) {}
    double area()
    {
        return 3.14 * r * r;
    }
    inline double peri()
    {
        return 2 * 3.14 * r;
    }
    ~circle()
    {
        std::cout << "~circle()" << std::endl;
    }
};

class Rectangle
{
public:
    int width;
    int height;
    Rectangle(int w, int h) : width{w}, height{h}
    {
        std::cout << "Rectangle constructor" << this->height << std::endl;
    }
    ~Rectangle()
    {
        std::cout << "Rectangle destructor" << this->height << std::endl;
    }
};
// factorial

void meow()
{
    static int adder{0};
    adder++;
    std::cout << adder << std::endl;
}
int main()
{

    std::shared_ptr<Rectangle> shpt = std::make_shared<Rectangle>(20, 200);
    std::weak_ptr<Rectangle> wept = shpt;
    std::unique_ptr<Rectangle> uptr = std::make_unique<Rectangle>(10, 100);
    if (wept.lock())
    {
        std::cout << wept.lock()->height << std::endl;
    }
    circle c(10);
    for (int i = 0; i < 4; i++)
    {
        meow();
        meow();
    }
    // std::cout << std::setw(4) << std::setprecision(2) << sqrt(13.000) << std::endl;
    return 0;
}
