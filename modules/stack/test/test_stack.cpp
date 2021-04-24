// Copyright 2021 Gruzdeva Diana

#include <gtest/gtest.h>

#include "include/stack.h"

TEST(Gruzdeva_Diana_Stack, Constructor) {
  int size = 3;

  Stack stack(size);

  ASSERT_EQ(true, stack.isEmpty());
  ASSERT_EQ(3, stack.size());
}

TEST(Gruzdeva_Diana_Stack, Copy) {
  Stack stack(5);
  for (int i = 0; i < 5; i++) {
    stack.push(static_cast<double>(i * 10));
  }

  Stack copiedStack(stack);


  ASSERT_EQ(stack, copiedStack);
}

TEST(Gruzdeva_Diana_Stack, Assignment) {
  Stack stack(5);
  for (int i = 0; i < 5; i++) {
    stack.push(static_cast<double>(i * 10));
  }
  Stack newStack(1);

  newStack = stack;

  ASSERT_EQ(stack, newStack);
}

TEST(Gruzdeva_Diana_Stack, Equality) {
  Stack stack(5);
  Stack anotherStack(5);

  for (int i = 0; i < 5; i++) {
    stack.push(static_cast<double>(i * 10));
    anotherStack.push(static_cast<double>(i * 10));
  }

  ASSERT_EQ(true, stack == anotherStack);
}

TEST(Gruzdeva_Diana_Stack, Unequality) {
  Stack stack(5);
  Stack anotherStack(5);

  for (int i = 0; i < 5; i++) {
    stack.push(static_cast<double>(i * 10));
    anotherStack.push(static_cast<double>(i * 10));
  }
  anotherStack.top();
  anotherStack.push(-10.0);

  ASSERT_EQ(true, stack != anotherStack);
}

TEST(Gruzdeva_Diana_Stack, Push_And_Peek) {
  Stack stack(5);
  double pushable = 10.0;

  stack.push(pushable);

  ASSERT_EQ(pushable, stack.peek());
}

TEST(Gruzdeva_Diana_Stack, Size) {
  Stack stack(5);
  int check = -1;

  check = stack.size();

  ASSERT_EQ(5, check);
}

TEST(Gruzdeva_Diana_Stack, Empty) {
  Stack stack(5);
  bool check = false;

  check = stack.isEmpty();

  ASSERT_EQ(true, check);
}

TEST(Gruzdeva_Diana_Stack, Full) {
  Stack stack(5);
  bool check = false;

  for (int i = 0; i < 5; i++) {
    stack.push(static_cast<double>(i * 10));
  }
  check = stack.isFull();

  ASSERT_EQ(true, check);
}

TEST(Gruzdeva_Diana_Stack, Wrong_Size) {
  int size;

  size = -1;

  ASSERT_ANY_THROW(Stack stack(-1));
}

TEST(Gruzdeva_Diana_Stack, Too_Much_Data) {
  Stack stack(5);

  for (int i = 0; i < 5; i++) {
    stack.push(static_cast<double>(i * 10));
  }

  ASSERT_ANY_THROW(stack.push(10.0));
}

TEST(Gruzdeva_Diana_Stack, Top_Is_Missing) {
  Stack stack(5);

  for (int i = 0; i < 5; i++) {
    stack.push(static_cast<double>(i * 10));
  }
  for (int i = 0; i < 5; i++) {
    stack.top();
  }

  ASSERT_ANY_THROW(stack.top());
}
