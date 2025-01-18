#include "pch.h"

class Location {
 public:
  enum class Direction { South, North, East, West };
  // overload the insertion operator
};

std::ostream &operator<<(std::ostream &os, const Location::Direction &dir) {
  switch (dir) {
    case Location::Direction::South : os << "South"; break;
    case Location::Direction::North : os << "North"; break;
    case Location::Direction::East : os << "East"; break;
    case Location::Direction::West : os << "West"; break;
    default : os << "Unknown"; break;
  }
  return os;
}
std::istream &operator>>(std::istream &in, Location::Direction &dir) {
  int input;
  in >> input;
  switch (input) {
    case 0 : dir = Location::Direction::South; break;
    case 1 : dir = Location::Direction::North; break;
    case 2 : dir = Location::Direction::East; break;
    case 3 : dir = Location::Direction::West; break;
    default :
      std::cerr << "Invalid input. Please enter a number between 0 and 3."
                << std::endl;
      exit(1);
      break;
  }
  return in;
}
int main(int argc, char const *argv[]) {
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 1);

  int accumilation = std::accumulate(v.begin(), v.end(), 0);
  std::cout << "Sum of all numbers: " << accumilation << std::endl;

  // std::vector<Location::Direction> v;
  // std::tuple<int, std::string, std::string> t;

  // t = std::make_tuple(1, "Hello", "World");
  // // set the tuple int to 100
  // auto &a = std::get<0>(t);
  // a = 123;

  // v.emplace_back(Location::Direction::East);
  // v.emplace_back(Location::Direction::North);
  // v.emplace_back(Location::Direction::West);
  // v.emplace_back(Location::Direction::West);
  // std::cout << "Vector: ";
  // for (const auto &d : v) {
  //   std::cout << d << " ";
  // }
  // std::cout << std::get<0>(t) << std::endl;
  // Location::Direction dir;
  // std::cout << "Enter current direction (0-South, 1-North, 2-East,
  // 3-West):
  // "; std::cin >> dir; std::cout << "Current direction: " << dir <<
  // std::endl;

  return 0;
}
