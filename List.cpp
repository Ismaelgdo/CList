// List.cpp
//Ismael Garrido
//CSI 33
//Project6
#include "List.h"


List::List(size_t capacity)
{
  data_ = new int[capacity];
  capacity_ = capacity;
  size_ = 0;
}

List::List(const List &list)
{
  copy(list);
}

List::~List()
{
  delete [] data_;
}

void List::copy(const List &list)
{
  size_t i;

  size_ = list.size_;
  capacity_ = list.capacity_;
  data_ = new int[list.capacity_];
  for (i=0; i<list.capacity_; ++i) {
    data_[i] = list.data_[i];
  }
}

List& List::operator=(const List &list)
{
  if (&list != this) {
    // deallocate existing dynamic array
    delete [] data_;
    // copy the data
    copy(list);
  }
  return *this;
}

List& List::extend(const List &list)
{
  size_t i;
  size_t pos = size_;
  
  if ((size_ + list.size_) > capacity_) {
    resize(size_ + list.size_);
  }

  for (i=0; i<list.size_; ++i) {
    data_[pos++] = list.data_[i];
  }
  size_ += list.size_;
  return *this;
}

void List::append(int item)
{
  if (size_ == capacity_) {
    resize(2 * capacity_);
  }
  data_[size_++] = item;
}

// should this method have a precondition? see end of chapter exercises
void List::resize(size_t new_size)
{
  int *temp;
  size_t i;

  capacity_ = new_size;
  temp = new int[capacity_];
  for (i=0; i<size_; ++i) {
    temp[i] = data_[i];
  }
  delete [] data_;
  data_ = temp;
}
//*

int List::index(int value)
{
	//returns the position(index) of the first occurance of <value>
	int i;
	for (i = 0; i < size_; ++i) {
		if (value == data_[i])
			return i;
	}
	return -1;
}

int List::pop(size_t i)
{
	int value;
	if (i == data_[size_ - 1]){
		value = data_[size_ - 1];
		remove(data_[size_ - 1]);
	}
	else if (i == data_[0]) {
		value = data_[0];
		remove(data_[0]);
	}
	else {
		
		value = data_[i];
		remove(data_[i]);
	}

	return value;
	
}

void List::insert(size_t i, int value)
// insert a value at position i
{
	//if (size_ == capacity_) {
	//resize(2 * capacity_);
	//}

	int pos;
	int temp = 0;
	for (pos = i; pos < size_; pos++) {
		temp = data_[pos];
		data_[pos] = value;
		value = temp;
	}
	data_[size_++] = temp;
}

void List::remove(int value)
{
	//remove the first ocurrence of the item on the array
	size_--;
	int i;
	int n;
	for (i = 0; i < size_; ++i) {
		if (data_[i] == value) {
			for (n = 1; n < size_ - 1; ++n) {
				data_[n] = data_[n + 1];
			}
		}
	}

}
/*
{
	//remove the first ocurrence of an item on a list
	size_--;
	int i;
	int k;
	for (i = 0; i < size_; ++i) {
		if (value == data_[i]) {
			for (k = 1; k < size_ - 1; ++k) {
				data_[k] = data_[k + 1];
}
		}
	}
	
}

*/
std::ostream& operator<<(std::ostream& os, List& l)
{
	size_t i;
	os << "[";
	for (i = 0; i<l.size_; ++i) {
		os << l[i];
		if (i < l.size_ - 1)
			os << ", ";
	}
	os << "]";
	os << " Capacity = " << l.capacity_;
	return os;
}

std::istream& operator >> (std::istream& is, List& l)
{
	char c;
	int n;

	//while (l.size_ > 0)
		//l.pop(0);
	is >> c;

	if ((is >> std::ws).peek() != ']')
		while (c != ']')
		{
			is >> std::ws >> n;
			//l.insert(l.size_, n);
			l.append(n);
			is >> std::ws >> c;
		}
	else
		is >> std::ws >> c;

	return is;
}

