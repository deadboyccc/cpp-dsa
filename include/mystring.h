#pragma once
#include <cstring>
#include <iostream>
using namespace std;
class mbstring {
  friend std::ostream &operator<<(std::ostream &os, const mbstring &s) {
    os << s.str;
    return os;
  }
  friend std::istream &operator>>(std::istream &in, mbstring &s) {
    char *buff = new char[1000];
    in.getline(buff, 1000);
    s = mbstring(buff);
    delete[] buff;
    return in;
  }
  friend bool operator==(const mbstring &lhs, const mbstring &rhs) {
    return strcmp(lhs.str, rhs.str) == 0;
  }
  friend mbstring operator-(const mbstring &lhs) {
    char *ptr = new char[strlen(lhs.str) + 1];
    for (size_t i = 0; i < strlen(lhs.str); i++) {
      ptr[i] = std::tolower(lhs.str[i]);
    }
    mbstring temp{ptr};
    delete[] ptr;
    return temp;
  }

 private:
  char *str;

 public:
  mbstring() : str{nullptr} {
    str = new char[1];
    str[0] = '\0';
  };
  mbstring &operator*(int n) {
    size_t len = strlen(this->str);
    char *ptr = new char[len * n + 1]('\0');
    for (size_t i = 0; i < n; i++) {
      strcat(ptr, this->str);
    }
    delete[] this->str;
    this->str = ptr;
    ptr = nullptr;
    return *this;
  }
  mbstring &operator*=(int n) { return *this = *this * n; }
  int operator>(const mbstring &rhs) { return strcmp(this->str, rhs.str); }

  mbstring(const char *ptr) : str{nullptr} {
    str = new char[strlen(ptr) + 1];
    strcpy(str, ptr);
    cout << "creating " << this << endl;
  };
  mbstring(const mbstring &source) : str{nullptr} {
    cout << "copying" << endl;

    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
  };
  mbstring &operator=(const mbstring &lhs) {
    if (this == &lhs) {
      return *this;
    }
    cout << " overladed assignment" << endl;
    delete[] str;
    str = new char[strlen(lhs.str) + 1];
    strcpy(str, lhs.str);
    return *this;
  }
  mbstring(mbstring &&l_reference) {
    cout << "moving" << endl;
    str = l_reference.str;
    l_reference.str = nullptr;
  }
  mbstring &operator=(mbstring &&rhs) {
    if (this == &rhs) {
      return *this;
    }
    cout << "overladed assignment[move]" << endl;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
  }
  mbstring operator+(const mbstring &rhs) const {
    mbstring temp;
    temp.str = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(temp.str, str);
    strcat(temp.str, rhs.str);
    return temp;
  }
  void display() const { cout << str << endl; };
  char *get_str() const { return str; };
  ~mbstring() {
    if (!(this->str == nullptr)) {
      cout << "deleting " << this << endl;
    } else {
      cout << "deleting null " << this << endl;
    }

    delete[] str;
  };
};