
#include "pch.h"
using std::cout;
using std::endl;
using tp = std::tuple<int, char, std::string>;
using iip = std::pair<int, int>;

// using (this shortcut ) as (this long thingie)
std::tuple<int, char, std::string> *test() {
  std::tuple<int, char, std::string> *a;
  a = new std::tuple<int, char, std::string>();
  // initialize elements of tuple
  std::get<0>(*a) = 10;
  std::get<1>(*a) = 'A';
  std::get<2>(*a) = "world";
  std::cout << a << std::endl;
  return a;
}
void memoryDrop(tp *a) {
  delete a;     // deletes the allocated memory
  a = nullptr;  // sets the pointer to nullptr to prevent dangling pointer
  std::cout << a
            << std::endl;  // will print nullptr now since memory was dropped
}
int main(int argc, char const *argv[]) {
  // auto a = test();
  // std::cout << a << std::endl;
  // memoryDrop(a);
  // int lowie = std::numeric_limits<int>::lowest();
  // int maxie = std::numeric_limits<int>::max();
  // cout << lowie << " " << maxie << endl;
  // cout << maxie - lowie + 1 << endl;
  unsigned int a = std::numeric_limits<unsigned int>::max();
  // display a and its bitset in a cout

  return 0;
}
