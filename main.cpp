#include <stdio.h>

#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <vector>
class base {
 public:
  int a;

  // constructor
  base(int test) : a{test} { std::cout << "base constructor\n"; }
};
class derived : public base {
 public:
  int triple;
  // constructor
  derived(int test) : base{test}, triple{test * 3} {
    std::cout << "derived constructor\n";
  }
};
// write template for T type
template <typename T>
void display(const T *ptr, size_t size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << ptr[i] << " ";
  }
  std::cout << std::endl;
}

void TOH(int n, int a, int b, int c) {
  if (n > 0) {
    TOH(n - 1, a, c, b);
    printf("(%d, %d) ", (a, c));
    TOH(n - 1, b, a, c);
  }
}
int power(int number, int po)

{
  if (po == 0) {
    return 1;
  }
  if (po % 2 == 0) {
    return power((number * number), (po / 2));
  } else {
    return number * power((number * number), ((po - 1) / 2));
  }
}
int I_factorial(int n) {
  int temp{1};
  for (int i = 2; i <= n; i++) {
    temp *= i;
  }
  return temp;
}
int return_sum(int n) {
  if (n == 1) {
    return 1;
  }
  return n + return_sum(n - 1);
}
long double taylor_series(int x, int n) {
  // long double sum{0};
  // for(int i=0;i<n;i++){
  //     sum+=pow(a,i)/I_factorial(i);
  // }
  // return sum;
  // taylor using recursive and static variables
  static long double p{1}, f{1};

  long double r{};
  if (n == 0) {
    return 1;
  }
  r = taylor_series(x, n - 1);
  p = p * x;
  f = f * n;
  return r + p / f;
}
long double expo_iterative(int x, int n) {
  long double s{1};
  long double num{1}, den{1};
  for (int i = 1; i <= n; i++) {
    num *= x;
    den *= i;
    s *= num / den;
    // 1(already added) + x/*i + *x/*i = s return s; easy
  }
  return s;
}
long double expo_recursive(int x, int n) {
  static long double s{1};
  if (n == 0) {
    return s;
  }
  s = 1 + x * s / n;
  return expo_recursive(x, n - 1);
}

int fib(int x) {
  static std::vector<int> memo(x, -1);
  if (x <= 1) {
    memo[x] = x;
    return memo[x];
  } else {
    if (memo[x - 2] == -1) {
      memo[x - 2] = fib(x - 2);
    }
    if (memo[x - 1] == -1) {
      memo[x - 1] = fib(x - 1);
    }
    return memo[x - 2] + memo[x - 1];
  }
}
int fib_iterative(int x) {
  int a{0}, b{1};
  int s{0};
  for (int i = 2; i <= x; i++) {
    s = a + b;
    a = b;
    b = s;
  }

  return s;
}
int ncr(int c, int r) {
  if (r == 0) return 1;
  if (r == c) return 1;
  return ncr(c - 1, r - 1) + ncr(c - 1, r);
}
int main() {
  // 2^9 = 2*(2^2)^4 for odd
  // 2^4 = (2^2)^2
  //  char *p = new char[10]("hello");
  //  std::cout << p << std::endl;
  //  std::cout << p[0] << std::endl;
  //  std::cout << p[1] << std::endl;
  //  std::cout << p[2] << std::endl;
  //  std::cout << p[3] << std::endl;
  //  std::cout << p[4] << std::endl;
  //  std::cout << (p[5] == 0?"True":"F") << std::endl;
  //  mbstring a{"bb"};
  //  mbstring b{"bbb"};
  //  int c = a>b;
  //  std::cout <<c << std::endl;
  // std::cout << std::setprecision(11) << taylor_series(1, 30) << std::endl;

  // std::cout << std::setprecision(11) << expo_recursive(1, 30) << std::endl;
  // std::cout << std::setprecision(11) << expo_recursive(1, 30) << std::endl;
  // std::cout << std::setprecision(11) << fib(13) << std::endl;
  // std::cout << std::setprecision(11) << fib_iterative(13) << std::endl;
  // std::cout << ncr(3, 2) << std::endl;
  // TOH(3, 1, 2, 3);
  // derived d{100};
  // std::cout << d.a << " " << d.l << std::endl;
  // int a[3][4]{0};
  // for (int i = 0; i < 3; i++)
  // {
  //     for (int j = 0; j < 4; j++)
  //     {
  //         std::cout << a[i][j] << " ";
  //     }
  //     std::cout << std::endl;
  // }
  // int *ptr[3]{nullptr};
  // ptr[0] = new int[4]{0};
  // ptr[1] = new int[4]{0};
  // ptr[2] = new int[4]{0};
  // for (int i = 0; i < 3; i++)
  // {
  //     for (int j = 0; j < 4; j++)
  //     {
  //         std::cout << ptr[i][j] << " ";
  //     }
  //     std::cout << std::endl;
  // }
  // // freeing the memory
  // for (int i = 0; i < 3; i++)
  // {
  //     delete[] ptr[i];
  //     ptr[i] = nullptr;
  // }
  // int **dptr = new int *[3]; // a double pointer pointing to an array of
  // pointers for (int i = 0; i < 3; i++)
  // {
  //     dptr[i] = new int[4]{0};
  // }
  // // printing the array
  // for (int i = 0; i < 3; i++)
  // {
  //     for (int j = 0; j < 4; j++)
  //     {
  //         std::cout << dptr[i][j] << " ";
  //     }
  //     std::cout << std::endl;
  // }
  // // freeing the memory
  // for (int i = 0; i < 3; i++)
  // {
  //     // deleting the areas from their heap pointers
  //     delete[] dptr[i];
  //     dptr[i] = nullptr;
  // }
  // // freeing the heap pointer array from its stack pointer dptr
  // delete[] dptr;

  // dptr = nullptr;
  // int arr[]{1, 2, 3};
  // double arr2[]{1.1, 2.2, 3.3, 4.4};
  // display<int>(arr, 3);
  // display<double>(arr2, 4);
  // int **ptr{nullptr};
  // ptr = new int *{nullptr};
  // *ptr = new int(10);
  // std::cout << **ptr << std::endl;
  // std::cout << *ptr << std::endl;
  // std::cout << ptr << std::endl;
  // delete *ptr;
  // delete ptr;
  // ptr = nullptr;
  // char **ptr2{nullptr};
  // ptr2 = new char *{nullptr};
  // *ptr2 = new char('A');
  // std::cout << **ptr2 << std::endl;
  // std::cout << *ptr2 << std::endl;
  // std::cout << ptr2 << std::endl;
  // delete *ptr2;
  // delete ptr2;
  // ptr2 = nullptr;
  // long long c = atoll("123127712981");
  // // print c
  // std::cout << c << std::endl;
  // std::unordered_map<char, bool> alpha;
  // for (char a = 'a'; a <= 'z'; a++)
  // {
  //     alpha[a] = true;
  // }
  // fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold |
  // bg(fmt::color::light_gray),
  //            "Hello, {}!\n", "world");
  // fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
  //                fmt::emphasis::underline,
  //            "Biden, {}!\n", "Joe");
  // fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic,
  //            "Donald{}！\n", "Trump");
  /**
   * @param myparam @author my author
   * @overload int
   */
  // TODO hello
  derived ooo{1000};
  // *
  // ?
  // !
  // TODO
  // ? should we use somehting else
  // *
  // ?
  // ! don't use this

  return 0;
}
