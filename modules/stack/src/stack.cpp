// Copyright 2021 Gruzdeva Diana

#include "../../modules/stack/include/stack.h"

template <typename T>
Stack<T>::Stack<T>(int _size = 0) {
  size = _size;
  top = size;

  data = new T[size];
  for (int i = 0; i < size; i++) {
    data[i] = T(0);
  }
}

template <typename T>
Stack<T>::Stack<T>(const Stack<T>& tmp) {
  size = tmp.size;
  top = tmp.top;

  data = new[size];
  for (int i = 0; i < size; i++) {
      data[i] = tmp.data[i];
  }
}

template <typename T>
Stack<T>::~Stack<T>() {
  delete [] data;
}

template <typename T>
int Stack<T>::size() {
  return size;
}

template <typename T>
void Stack<T>::push(T element) {
  T tmp*;
  tmp = new T[size];
  for (int i = 0; i < size; i++) {
    tmp[i] = data[i];
  }
  delete data;
  size++;
  data = new T[size];
  for (int i = 0; i < size - 1; i++) {
    tmp[i] = data[i];
  }
  data[size] = element;
}

template<typename T>
T Stack<T>::peek(int index) {
  return data[size - 1 - index];
}

template <typename T>
T Stack<T>::top() {
  return data[--top];
}

template <typename T>
bool Stack<T>::isEmpty() {
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}


template <typename T>
std::string Stack<T>::print() {
  std::string result = "";
  int realIndex = top;
  for (int i = top; i < 0; i--) {
    result = result + (top - realIndex) + ": " + data[i] + "\n";
    realIndex--;
  }

  return result;
}
