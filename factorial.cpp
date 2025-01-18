#include <iostream>
long long factorial(int a) {
  long long result = 1;
  for (int i = 1; i <= a; i++) result *= i;
  return result;
}
int main(int argc, char const *argv[]) {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;
  std::cout << "Factorial of " << n << " is: " << factorial(n) << std::endl;

  return 0;
}
