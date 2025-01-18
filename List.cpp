#include <exception>
#include <fstream>
#include <iomanip>

#include "Base.h"
#include "ListHeader.h"
#include "pch.h"
class DivisionByZero : std::exception {
 public:
  DivisionByZero() noexcept = default;
  virtual ~DivisionByZero() noexcept = default;
  virtual const char *what() const noexcept {
    return "Error: Division by zero";
  }
};
class NegativeValue {
 public:
  NegativeValue() noexcept = default;
  virtual ~NegativeValue() = default;
  virtual const char *what() const noexcept { return "Error: Negative value"; }
};
void divide(const double &a, const double &b) {
  // Divides a by b, throws exceptions for invalid operations
  if (b == 0) {
    throw DivisionByZero{};
  } else if (a < 0 || b < 0) {
    throw NegativeValue{};
  }
  std::cout << a / b << std::endl;
}
void printadd(std::initializer_list<int> nums) {
  std::cout << typeid(nums).name() << std::endl;
  // for (auto num : nums) {
  //   std::cout << num << " + ";
  // }
  // std::cout << " = " << std::accumulate(nums.begin(), nums.end(), 0)
  //           << std::endl;
}
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> v =
      std::make_unique<std::vector<std::shared_ptr<Test>>>();
  // for (int i = 0; i < 10; i++)
  // {
  //   v->push_back(std::make_shared<Test>(i));
  // }
  return v;
}
void fill(std::vector<std::shared_ptr<Test>> &v, int num) {
  int temp;
  for (int i = 0; i < num; i++) {
    std::cout << "Enter the value for [" << i << "]" << std::endl;
    std::cin >> temp;
    v.push_back(std::make_shared<Test>(temp));
  }
}
void display(const std::vector<std::shared_ptr<Test>> &v) {
  for (const auto &element : v) {
    std::cout << element->get_data() << std::endl;
  }
  std::cout << std::endl;
}
auto a = 1.34l;
auto begin() -> decltype(a) { return a; }
decltype(a) end() { return a; }
int main(int argc, char const *argv[]) {
  // List<int> a{};
  // a.push_back(1);
  // a.push_back(2);
  // a.push_back(3);
  // a.push_back(4);
  // printadd({1, 2, 3, 4});

  // for (auto it = a.begin(); it != a.end(); it++) {
  //   std::cout << *it << " ";
  // }
  // std::cout << typeid(begin()).name() << std::endl;
  // std::cout << typeid(end()).name() << std::endl;
  // Base a{10};
  // Base b{std::move(a)};

  // a.test();
  // std::cout << a.b << std::endl;
  // std::cout << typeid(std::cout).name() << std::endl;

  // std::cout << typeid(b).name() << std::endl;
  // std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
  // std::shared_ptr<int> ptr2 = std::make_shared<int>(100);
  // std::cout << ptr1.use_count() << std::endl;
  // std::cout << ptr2.use_count() << std::endl;
  // {
  //   std::vector<decltype(ptr2)> v;
  //   v.push_back(ptr1);
  //   v.push_back(ptr2);

  //   for (auto p : v)
  //   {
  //     std::cout << *p << " ";
  //   }
  //   std::cout << ptr1.use_count() << std::endl;
  //   std::cout << ptr2.use_count() << std::endl;
  // }

  // std::cout << std::endl;
  // std::cout << ptr1.use_count() << std::endl;
  // std::cout << ptr2.use_count() << std::endl;
  // std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
  // int b{0};
  // vec_ptr = make();
  // std::cout << "how many data points :" << std::endl;
  // std::cin >> b;
  // fill(*vec_ptr, b);
  // display(*vec_ptr);
  try {
    double a, b;
    std::cin >> a >> b;
    divide(a, b);
  } catch (const DivisionByZero &ex) {
    std::cout << "division by Zero:   " << ex.what() << std::endl;
  } catch (const NegativeValue &ex) {
    std::cout << "Invalid Input:   " << ex.what() << std::endl;
  }
  std::cerr << "hello" << std::endl;

  return 0;
}