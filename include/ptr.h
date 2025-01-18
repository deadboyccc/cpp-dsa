#pragma once
#include <iostream>
class ptr {
 private:
  int *data;

 public:
  ptr(int n);
  ptr(ptr &&p) noexcept;
  ~ptr();
};

ptr::ptr(int n) {
  data = new int(n);
  std::cout << this->data << " created" << std::endl;
}

ptr::ptr(ptr &&p) noexcept : data{p.data} {
  std::cout << p.data << " moved " << std::endl;
  p.data = nullptr;
}
ptr::~ptr() {
  if (data == nullptr) {
    std::cout << this->data << " null deleted" << std::endl;
  }
  std::cout << this->data << " deleted" << std::endl;
  delete data;
}
