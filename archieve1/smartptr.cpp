#include <memory>
#include <iostream>
#include <print>
#define a 100 // very elegant code
class Testy
{
private:
public:
    int test{100};
    Testy();
    ~Testy();
};

Testy::Testy()
{
    std::cout << "Testy constructor" << std::endl;
}

Testy::~Testy()
{
    std::cout << "Testy destructor" << std::endl;
}

int main()
{
    // std::unique_ptr<Testy> uptr1 = std::make_unique<Testy>();
    // std::cout << uptr1->test << std::endl;
    // std::cout << uptr1 << std::endl;
    std::shared_ptr<Testy> shpt1 = std::make_shared<Testy>();
    std::shared_ptr<Testy> shpt2 = shpt1;
    std::cout << std::boolalpha;
    std::weak_ptr<Testy> wept1 = shpt1;
    shpt2.reset();
    std::cout << shpt1.use_count() << std::endl;
    if (wept1.lock()) // create a shared ptr based on the weak ptr that dies when the original references die, but it's used to safely access if the original reference shared pointers aren't out of life.
    {
        std::cout << wept1.lock()->test << std::endl;
    }
    std::cout << wept1.expired() << std::endl;
    // std::println("pointer address is : {}, value is: {}", uptr1, *uptr1);
    shpt1.reset();
    std::cout << wept1.expired() << std::endl;
    std::cout << a;
    return 0;
}
