// List.h
#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cstdlib>

class List {
  friend std::ostream& operator<<(std::ostream& os, List& l);
  friend std::istream& operator >> (std::istream& is, List& l);

public:
  List(size_t capacity=10); // constructor - allocates dynamic array
  List(const List &a); // copy constructor
  ~List(); // destructor

  int& operator[](size_t pos); // bracket operator
  List& operator=(const List &a); // assignment operator
  List& extend(const List &a); // += operator
  int pop(size_t i);
  void remove(int value);
  void insert(size_t i, int value);
  int index(int value);
  void resize(size_t new_size); // allocate new larger array
  void append(int item);
  size_t size() const { return size_; }
  
private:
  void copy(const List &a);
  
  int *data_; // dynamic array
  size_t size_; // size of dynamic array
  size_t capacity_; // capacity of dynamic array
};

inline int& List::operator[](size_t pos)
{
  return data_[pos];
}

#endif // _LIST_H_
