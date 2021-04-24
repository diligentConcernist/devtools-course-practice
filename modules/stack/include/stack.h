//  Copyright 2021 Gruzdeva Diana

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

class Stack {
 private:
    double *data;
    int size_;
    int top_;

 public:
    explicit Stack(int size = 10);
    Stack(const Stack& stack);
    ~Stack();
    int size() const;
    double peek() const;
    double top();
    bool isEmpty() const;
    bool isFull() const;
    void push(const double value);

    void operator = (const Stack& stack);
    bool operator == (const Stack& stack) const;
    bool operator != (const Stack& stack) const;
};

#endif  // MODULES_STACK_INCLUDE_STACK_H_
