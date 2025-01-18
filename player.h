#pragma once
#include <iostream>
#include <string>
class Player {
 private:
  std::string name;
  int xp;
  int hp;

 public:
  friend std::ostream &operator<<(std::ostream &out, const Player &p) {
    out << "Name: " << p.name << ", XP: " << p.xp << ", HP: " << p.hp
        << std::endl;
    return out;
  }

  void print(std::ostream &out = std::cout) {
    out << "Name: " << name << ", XP: " << xp << ", HP: " << hp << std::endl;
  }
  static int counter;
  // Default constructor
  Player() : name("Unknown"), xp(0), hp(100) {}

  // Parameterized constructor
  Player(std::string nameVal, int xpVal, int hpVal)
      : name(nameVal), xp(xpVal), hp(hpVal) {
    counter++;
    std::cout << counter << " Create" << std::endl;
  }
  Player(const Player &source) : Player(source.name, source.hp, source.xp) {}

  // Destructor
  ~Player() {
    counter--;
    std::cout << counter << " deleted" << std::endl;
    // std::cout << "Player " << this->name << " has died." << std::endl;
  }

  // Getters and setters for each attribute
  void setName(std::string nameVal) { name = nameVal; }
  std::string getName() const { return name; }

  void setXp(int xpVal) { xp = xpVal; }
  int getXp() const { return xp; }

  void setHp(int hpVal) { hp = hpVal; }
  int getHp() const { return hp; }
  static int get_counter();
};
int Player::counter{0};
int Player::get_counter() { return Player::counter; }