// Copyright 2021 Gruzdeva Diana

#include "include/stack.h"

Stack::Stack(int size) {
    if (size <= 0) {
        throw "The size must be greater than zero";
    } else {
        this->size_ = size;
    }
    data = new double[this->size_];
    for (int i = 0; i < size; i++) {
      data[i] = 0.0;
    }
    top_ = -1;
}

Stack::Stack(const Stack& stack) {
    size_ = stack.size_;
    data = new double[size_];
    top_ = stack.top_;
    for (int i = 0; i < top_ + 1; i++)
        data[i] = stack.data[i];
}

Stack::~Stack() {
    delete [] data;
}

int Stack::size() const {
    return size_;
}

double Stack::peek() const {
    return data[top_];
}

bool Stack::isEmpty() const {
    return (top_ == -1);
}

bool Stack::isFull() const {
    return (top_ + 1 == size_);
}

void Stack::push(const double value) {
  if (this->isFull()) {
    throw "Stack is full";
  }
  data[++top_] = value;
}

double Stack::top() {
  if (this->isEmpty()) {
    throw "Stack is empty";
  }
  return data[top_--];
}

void Stack::operator = (const Stack& stack) {
    size_ = stack.size_;
    data = new double[size_];
    top_ = stack.top_;
    for (int i = 0; i < top_ + 1; i++) {
        data[i] = stack.data[i];
    }
}

bool Stack::operator == (const Stack& stack) const {
    bool check = false;
    if (size_ == stack.size_) {
        if (top_ == stack.top_) {
            check = true;
            for (int i = 0; i < size_; i++) {
                if (data[i] != stack.data[i]) {
                    check = false;
                    break;
                }
            }
        }
    }
    return check;
}

bool Stack::operator != (const Stack& stack) const {
    return !(*this == stack);
}
