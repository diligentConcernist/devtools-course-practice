//  Copyright 2021 Gruzdeva Diana

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

#include <string>

template <class T> class Stack {
 private:
  int size;
  T* data;
  int top;

 public:
  Stack<T>(int _size = 0);

  Stack<T>(const Stack<T> &tmp);

  Stack<T> &operator=(const Stack<T> &tmp);

  ~Stack<T>();

  int size();

  void push(T element);
  T pop();
  T peek(int index);
  T top();

  bool isEmpty();

  std::string print();
};

#endif  // MODULES_STACK_INCLUDE_STACK_H_
