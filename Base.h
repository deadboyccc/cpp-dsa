#pragma once
#include <iostream>
class I_printable
{
  friend std::ostream &operator<<(std::ostream &out, const I_printable &obj)
  {
    obj.getClassName(out);
    return out;
  }

public:
  virtual void getClassName(std::ostream &out) const = 0;
  virtual ~I_printable() = default;
};
class Shape : public I_printable
{
public:
  virtual void draw() = 0;
  virtual void getClassName(std::ostream &out) const = 0;
  virtual ~Shape() = default;
};
class Circle : public Shape
{
public:
  void draw() override
  {
    std::cout << "Drawing circle" << std::endl;
  }
  virtual void getClassName(std::ostream &out) const override
  {
    out << "Shape: dCircle" << std::endl;
  }
};
class Line : public Shape
{
public:
  void draw() override
  {
    std::cout << "Drawing line" << std::endl;
  }
  virtual void getClassName(std::ostream &out) const override
  {
    out << "Shape: dLine" << std::endl;
    ;
  }
};
class Base
{
public:
  int b;
  Base() : b{0} { std::cout << "-[Base no-args Constructor!]" << std::endl; }
  Base(int val) : b{val}
  {
    std::cout << "-[Base int Constructor!]" << std::endl;
  }
  Base(const Base &lval) : b{lval.b}
  {
    std::cout << "-[Base copy Constructor!]" << std::endl;
  }
  // continue implementaiton of the =copy assignment lval
  Base &operator=(const Base &lval)
  {
    b = lval.b;
    std::cout << "-[Base copy assignment!]" << std::endl;

    return *this;
  }
  Base(const Base &&rval) : b{std::move(rval.b)}
  {
    std::cout << "-[Base move Constructor!]" << std::endl;
  }
  Base &operator=(const Base &&rval)
  {
    b = std::move(rval.b);
    std::cout << "-[Base move assignment!]" << std::endl;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &out, const Base &base)
  {
    out << "Base b: " << base.b;
    return out;
  }
  friend std::istream &operator>>(std::istream &input, Base &base)
  {
    // impelement a function that takes an input from the input cin stream and
    // puts it in base.b then returns the std::istream
    input >> base.b;
    return input;
  }
  virtual void test() const
  {
    std::cout << "hello from base ! | " << *this << std::endl;
  }
  // simple default destructor
  virtual ~Base() = default;
};
class Test : public I_printable
{
private:
  int data;

public:
  virtual void getClassName(std::ostream &out) const override
  {
    out << data << std::endl;
  };

  Test() : data{0}
  {
    std::cout << "\tTest constructor (" << data << ")" << std::endl;
  }

  Test(int data) : data(data)
  {
    std::cout << "\tTest constructor (" << data << ")" << std::endl;
  }

  int get_data() const
  {
    return data;
  }

  virtual ~Test()
  {
    std::cout << "\tTest destructor (" << data << ")" << std::endl;
  }
};
class Derived : public Base
{
public:
  int d;
  Derived() : Base{}, d{0}
  {
    std::cout << "-[Derived no-args Constructor!]" << std::endl;
  }
  Derived(int val, int twoval) : Base{val}, d{twoval}
  {
    std::cout << "-[Derived int Constructor!]" << std::endl;
  }
  Derived(const Derived &x) : Base(x), d{x.d}
  {
    std::cout << "-[Derived copy Constructor!]" << std::endl;
  }
  Derived &operator=(const Derived &x)
  {
    Base::operator=(x);
    d = x.d;
    std::cout << "-[Derived copy assignment!]" << std::endl;

    return *this;
  }
  virtual void test() const override
  {
    std::cout << "hello from derived" << std::endl;
  }
  virtual ~Derived() = default;
};