#pragma once
#include <iostream>
using namespace std;

class base {
 public:
  base() : a{0} {}
  base(int b) : a{b} {}
  int a{10};

 protected:
  int c{30};

 private:
  int b{20};
};

class derived : public base {
 public:
  double l;
  derived() : l{0.0} {}
  derived(double l) : base{static_cast<int>(l)}, l{l} {}
  void print_acc() {
    cout << a << endl;
    cout << c << endl;
  }
};