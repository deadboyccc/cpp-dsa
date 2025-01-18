#include "pch.h"
#include <iomanip>
#include "player.h"
#include "tree.h"
int main()
{
  // std::cout.setf(std::ios::boolalpha);

  // std::cout << (10 == 10) << std::endl;
  // std::cout << (10 == 210) << std::endl;

  // std::cout << std::resetiosflags(std::ios::boolalpha);
  // std::cout << (10 == 10) << std::endl;
  // std::cout << (10 == 210) << std::endl;

  std::cout << std::showbase << std::uppercase << std::showpos << std::hex << 100 << std::endl;
  std::cout << std::showbase << std::uppercase << std::showpos << std::dec << 100 << std::endl;

  // Player ahmed{"ahmed", 100, 100};
  // Player mohammad{"mohammad", 100, 100};
  // Player ali{"ali", 100, 100};
  // Player ali2{"ali2", 100, 100};
  // std::cout << ahmed << mohammad << ali;

  return 0;
}
