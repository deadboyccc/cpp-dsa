#include "pch.h"

class Player {
 public:
  std::string name;
  Player();
  ~Player();
};

Player::Player() : name{"Empty"} {}

Player::~Player() {}

int main(int argc, char const *argv[]) {
  std::cout << "1234/10=" << 1234 / 10 << std::endl;
  std::cout << "12/10=" << 12 / 10 << std::endl;
  std::cout << "1/10=" << 1 / 10 << std::endl;
  Player a{};
  std::cout << "Player's name: " << a.name << std::endl;

  std::cout << "123%10=" << 123 % 10 << std::endl;

  return 0;
}
