#include "pch.h"
template <typename Object>
class Vector {
 public:
  // explicit one arg constuctor
  explicit Vector(int initSize = 0)
      : theSize{initSize}, theCapacity{initSize + SPARSE_CAPACITY} {
    objects = new Object[theCapacity];
  }
  // copy constructor and copy assignment
  // instance.operator=(anotherInstance) = copy from 2 to 1
  // instance{another one}; by lvalue
  Vector(const Vector &rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr} {
    objects = new Object[theCapacity];
    for (int k = 0; k < theSize; ++k) {
      objects[k] = rhs.objects[k];
    }
  }
  Vector &operator=(const Vector &rhs) {
    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  ~Vector() { delete[] objects; }
  // move semantics
  // move constructor

  Vector(Vector &&rhs)
      : theSize{rhs.theSize},
        theCapacity{rhs.theCapacity},
        objects{rhs.objects} {
    rhs.objects = nullptr;
    rhs.theSize = 0;
    rhs.theCapacity = 0;
  }
  // move assignment= operator
  Vector &operator=(Vector &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);
    return *this;
  }

  void resize(int newSize) {
    if (newSize > theSize) {
      reserve(newSize * 2);
      theSize = newSize;
    }
  }
  void reserve(int newCapacity) {
    if (newCapacity < theSize) return;
    Object *newArray = new Object[newCapacity];
    for (int k = 0; k < theSize; ++k) {
      newArray[k] = std::move(objects[k]);
    }
    theCapacity = newCapacity;
    std::swap(objects, newArray);
    delete[] newArray;
  }

  // resize
  // reserve
  //
  Object &operator[](int index) { return objects[index]; }
  const Object &operator[](int index) const { return objects[index]; }
  int size() const { return theSize; };
  int capacity() const { return theCapacity; };
  bool empty() { return size() == 0; }
  void push_back(Object &x) {
    if (theSize == theCapacity) {
      reserve(2 * theCapacity + 1);
    }
    objects[++theSize] = x;
  }
  void push_back(Object &&x) {
    if (theSize == theCapacity) {
      reserve(2 * theCapacity + 1);
    }
    objects[theSize++] = std::move(x);
  }
  void pop() { theSize--; }
  const Object &back() const { return objects[theSize - 1]; }
  using iterator = Object *;
  using const_interator = const Object *;
  iterator begin() { return &objects[0]; }
  const_interator begin() const { return &Object[0]; }
  iterator end() { return &objects[size()]; }
  const_interator end() const { return &objects[size()]; }
  static const int SPARSE_CAPACITY = 16;

 private:
  int theSize;
  int theCapacity;
  Object *objects;
};
int main(int argc, char const *argv[]) {
  Vector<int> a{0};
  std::cout << a.size() << std::endl;
  std::cout << a.capacity() << std::endl;
  std::cout << a.SPARSE_CAPACITY << std::endl;
  a.push_back(10);
  a.push_back(20);
  for (int i = 0; i < a.size(); i++) std::cout << a[i] << " ";
  std::cout << std::endl;
  for (auto it = a.begin(); it != a.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;
  std::cout << a.empty() << std::endl;
  std::cout << a.size() << std::endl;
  std::cout << a.capacity() << std::endl;

  return 0;
}
