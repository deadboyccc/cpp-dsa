#include <math.h>

#include <iostream>
int power(int base, int expo) {
  int result = 1;
  while (expo > 0) {
    result *= base;
    expo--;
  }
  return result;
}
class term {
 public:
  int coeff;
  int expo;
};
class poly {
 private:
  int n;
  term *ele;

 public:
  poly(int n);
  ~poly();
  void read() {
    std::cout << "Enter coefficients and exponents of the polynomial (in "
                 "descending order of exponents):"
              << std::endl;
    for (int i = 0; i < n; i++) {
      std::cin >> ele[i].coeff >> ele[i].expo;
      std::cout << ele[i].coeff << ele[i].expo;
      std::cout << std::endl;
    }
  }
  void display() {
    for (int i = 0; i < n; i++) {
      std::cout << ele[i].coeff << "x^" << ele[i].expo;
      if (i < n - 1)
        std::cout << " + ";
      else
        std::cout << std::endl;
    }
  }
  void eval(int x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (ele[i].coeff) * power(x, ele[i].expo);
    }
    std::cout << "Value of the polynomial at x: " << x << " =" << sum
              << std::endl;
  }
  poly *join(poly &p2) {
    poly *result = new poly(this->n + p2.n);
    int i, j, k;
    i = j = k = 0;
    while (i < this->n && j < p2.n) {
      if (ele[i].expo > p2.ele[j].expo) {
        result->ele[k++] = ele[i++];
      } else if (ele[i].expo < p2.ele[j].expo) {
        result->ele[k++] = p2.ele[j++];
      } else {
        result->ele[k].coeff = ele[i].coeff + p2.ele[j].coeff;
        result->ele[k].expo = ele[i].expo;
        i++;
        j++;
        k++;
      }
    }
    while (i < this->n) {
      result->ele[k++] = ele[i++];
    }
    while (j < p2.n) {
      result->ele[k++] = p2.ele[j++];
    }
    result->n = k;
    return result;  // Return the joined polynomial
  }
};

poly::poly(int n) {
  this->n = n;
  this->ele = new term[n];
}

poly::~poly() { delete[] ele; }

int main(int argc, char const *argv[]) {
  poly p(2);  // Create a polynomial with degree 3
  p.read();   // Read coefficients and exponents of the polynomial
  p.display();
  p.eval(2);
  poly p2(2);
  p2.read();

  poly *p3 = new poly(5);
  p3 = p.join(p2);
  p3->display();
  return 0;
}
