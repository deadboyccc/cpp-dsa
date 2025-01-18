#include "pch.h"
class Base {
 public:
  std::string name;
  Base(std::string id) : name{id} {};
  virtual void say_hello() const {
    std::cout << "hello, I'm a Base class" << std::endl;
  }
  virtual ~Base() {
    std::cout << name << " || " << "-[Base Desctructor!]" << std::endl;
  }
};
class Derived : public Base {
 public:
  Derived(std::string id) : Base(id) {};
  virtual void say_hello() const {
    std::cout << "hello, I'm a Derived class" << std::endl;
  }
  ~Derived() {
    std::cout << name << " || " << "-[Derived Desctructor!]" << std::endl;
  }
};
void hello(const Base &test) { test.say_hello(); }
int main(int argc, char const *argv[]) {
  //   Base b{"hello"};
  //   b.say_hello();

  //   Derived d{"hello"};
  //   d.say_hello();
  //   d.Base::say_hello();

  Base *ptr1 = new Base{"Base object"};
  Base *ptr2 = new Derived{"Derived object"};
  //   ptr->say_hello();
  ptr1->say_hello();
  ptr2->say_hello();
  delete ptr1;
  delete ptr2;
  ptr1 = ptr2 = nullptr;
  //   ptr = nullptr;
  //   std::unique_ptr<Base> smart_ptr = std::make_unique<Derived>();
  //   smart_ptr->say_hello();
  return 0;
}
