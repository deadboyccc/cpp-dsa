#include <iostream>
#include <vector>
class test
{
    int *data;

public:
    static int cute;
    test(int n);
    test(const test &src);
    test(test &&src) noexcept;
    static int get_cuter();
    ~test();
    // dec
};
test::test(int n)
{
    data = new int(n);
    cute++;
    std::cout << cute << " co"<<std::endl;
    std::cout << data << " Created" << std::endl;
}
test::test(const test &src) : data{src.data}
{
    std::cout << data << " Copied" << std::endl;
}
test::test(test &&src) noexcept : data{src.data}
{
    src.data = nullptr;
    std::cout << data << " Moved" << std::endl;
}
test::~test()
{
    delete data;
    cute--;
    std::cout << cute <<" de" << std::endl;
    // std::cout << data << " Destroyed" << std::endl;
}
int test::cute{0};
int get_cuter()
{
    return test::cute;
}
int main()
{
    std::vector<test> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    return 0;
}
