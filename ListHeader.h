// LINE REACHED : 118
#pragma once
// #include <algorithm>

// Templated doubly-linked list class
template <typename Object>
class List
{
private:
  // Node structure for doubly linked list
  struct Node
  {
    Object data;
    Node *prev;
    Node *next;

    // Constructor: copy data
    Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr)
        : data{d}, prev{p}, next{n} {}

    // Constructor: move data
    Node(Object &&d, Node *p = nullptr, Node *n = nullptr)
        : data{std::move(d)}, prev{p}, next{n} {}
  };

public:
  // Constant iterator class for the List
  class const_iterator
  {
  public:
    // Default constructor
    const_iterator() : current{nullptr} {}

    // Dereference to access data
    // const returns the object in const and the function doesn't change 'const'
    const Object &operator*() const { return retrieve(); }

    // Increment operators (pre and post)
    const_iterator &operator++()
    {
      current = current->next;
      return *this;
    }
    const_iterator operator++(int)
    {
      const_iterator old = *this;
      ++(*this);
      return old;
    }

    // Decrement operators (pre and post)
    const_iterator &operator--()
    {
      current = current->prev;
      return *this;
    }
    const_iterator operator--(int)
    {
      const_iterator old = *this;
      --(*this);
      return old;
    }

    // Equality and inequality comparisons
    bool operator==(const const_iterator &rhs) const
    {
      return current == rhs.current;
    }
    // this is kinda not very understandable
    // rhs is a const_iterator object, *this = a const iterator obj they will go
    // to == and compare currents return the ngation we got it

    bool operator!=(const const_iterator &rhs) const { return !(*this == rhs); }

  protected:
    Node *current; // Current node in the list

    // Retrieve current node's data
    Object &retrieve() const { return current->data; }

    // Protected constructor with Node pointer
    const_iterator(Node *p) : current{p} {}

    // Allow List to access protected members
    friend class List<Object>;
  };

  // Iterator class for List, inherits const_iterator
  class iterator : public const_iterator
  {
  public:
    iterator() {} // Default constructor

    // Dereference operators for access and modification
    Object &operator*() { return const_iterator::retrieve(); }
    const Object &operator*() const { return const_iterator::operator*(); }

    // Increment operators (pre and post)
    iterator &operator++()
    {
      this->current = this->current->next;
      return *this;
    }
    iterator operator++(int)
    {
      iterator old = *this;
      ++(*this);
      return old;
    }

    // Decrement operators (pre and post)
    iterator &operator--()
    {
      this->current = this->current->prev;
      return *this;
    }
    iterator operator--(int)
    {
      iterator old = *this;
      --(*this);
      return old;
    }

  protected:
    // Constructor with Node pointer
    iterator(Node *p) : const_iterator{p} {}

    friend class List<Object>;
  };

public:
  // Constructors and destructors
  List() { init(); }
  ~List()
  {
    clear();
    delete head;
    delete tail;
  }

  // Copy constructor
  List(const List &rhs)
  {
    init();
    for (auto &x : rhs)
      push_back(x);
  }

  // Copy assignment
  List &operator=(const List &rhs)
  {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  // Move constructor
  List(List &&rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
  {
    rhs.theSize = 0;
    rhs.head = rhs.tail = nullptr;
  }

  // Move assignment
  List &operator=(List &&rhs)
  {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return *this;
  }

  // Iterator functions for begin and end
  iterator begin() { return iterator(head->next); }
  const_iterator begin() const { return const_iterator(head->next); }
  iterator end() { return iterator(tail); }
  const_iterator end() const { return const_iterator(tail); }

  // Accessors
  int size() const { return theSize; }
  bool empty() const { return size() == 0; }

  // Clear the list
  void clear()
  {
    while (!empty())
      pop_front();
  }

  // Front and back element access
  Object &front() { return *begin(); }
  const Object &front() const { return *begin(); }
  Object &back() { return *--end(); }
  const Object &back() const { return *--end(); }

  // Push and pop operations for front and back
  void push_front(const Object &x) { insert(begin(), x); }
  void push_back(const Object &x) { insert(end(), x); }
  void push_front(Object &&x) { insert(begin(), std::move(x)); }
  void push_back(Object &&x) { insert(end(), std::move(x)); }
  void pop_front() { erase(begin()); }
  void pop_back() { erase(--end()); }

  // Insert an element before itr
  iterator insert(iterator itr, const Object &x)
  {
    Node *p = itr.current;
    ++theSize;
    return iterator(p->prev = p->prev->next = new Node{x, p->prev, p});
  }

  iterator insert(iterator itr, Object &&x)
  {
    Node *p = itr.current;
    ++theSize;
    return iterator(p->prev = p->prev->next =
                        new Node{std::move(x), p->prev, p});
  }

  // Erase element at itr

  iterator erase(iterator itr)
  {
    Node *p = itr.current;    // Get the pointer to the node at itr.
    iterator retVal(p->next); // Create an iterator to the node after p.
    p->prev->next = p->next;  // Link p's previous node to p's next node.
    p->next->prev = p->prev;  // Link p's next node to p's previous node.
    delete p;                 // Deallocate the memory for node p.
    --theSize;                // Decrement the list size.
    return retVal;            // Return iterator to the next element.
  }

  // Erase elements from `from` to `to`
  iterator erase(iterator from, iterator to)
  {
    for (iterator itr = from; itr != to;)
      itr = erase(itr);
    return to;
  }

private:
  int theSize; // List size
  Node *head;  // Head node (sentinel)
  Node *tail;  // Tail node (sentinel)

  // Initialize empty list with head and tail sentinels
  void init()
  {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
  }
};
