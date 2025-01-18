#include "pch.h"
template <typename Type>
class Point {
 private:
  Type x;
  Type y;

 public:
  friend std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
  friend std::istream &operator>>(std::istream &in, Point &b) {
    in >> b.x >> b.y;
    return in;
  }
  Point(Type a, Type b) : x{a}, y{b} {};
  ~Point() = default;
};
// implementation of Euclid's algorithm gcd

int gcd(int a, int b) {
  // Euclid's algorithm for finding GCD
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

template <typename Container>
void print(const Container &c, std::ostream &out = std::cout) {
  for (auto &i : c) {
    out << i << " ";
  }
  out << std::endl;
}
template <typename Container>
void removeEveryOtherItem(Container &lst) {
  auto itr = lst.begin();
  while (itr != lst.end()) {
    itr = lst.erase(itr);
    if (itr != lst.end()) {
      ++itr;
    }
  }
}
template <typename Container>
void findNonRepeating(const Container &c) {
  using ItemType = typename Container::value_type;  // Deduce the item type from
                                                    // the container
  std::unordered_map<ItemType, int> countMap;

  // Count the occurrences of each item in the container
  for (const auto &item : c) {
    countMap[item]++;
  }

  bool found = false;
  // Check for non-repeating elements
  for (const auto &pair : countMap) {
    if (pair.second == 1) {
      std::cout << "Non-repeating element: " << pair.first << std::endl;
      found = true;
    }
  }

  if (!found) {
    std::cout << "No non-repeating elements found." << std::endl;
  }
}

int main() {
  Point a(10, 20);
  Point b(2.3f, 4.2f);

  std::cout << a << std::endl;
  std::cout << b << std::endl;

  std::vector<int> v = {1, 2, 3, 2, 1, 4, 5, 4};
  using typeItem = std::vector<int>::value_type;
  typeItem d = 13;
  // std::ccout type of a
  std::cout << typeid(std::cout).name() << std::endl;

  // findNonRepeating(v);
  // removeEveryOtherItem(v);
  // print(v);
  // std::cout << gcd(100, 50) << std::endl;
  return 0;
}
