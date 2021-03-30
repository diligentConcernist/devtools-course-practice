// Copyright 2021 Diana Gruzdeva

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"

TEST(Gruzdeva_Diana_ComplexNumberTest, Long_equation) {
  double resultRe = 2.0;
  double resultIm = 19.0;
  double re1 = 5.0;
  double im1 = 4.0;
  double re2 = 25.0;
  double im2 = -3.0;
  double re3 = 12.0;
  double im3 = -7.0;
  double re4 = -6.0;
  double im4 = -9.0;

  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber z3(re3, im3);
  ComplexNumber z4(re4, im4);
  ComplexNumber zReal = z1 * z2 + z3 * z4;

  ASSERT_EQ(resultRe, zReal.getRe());
  ASSERT_EQ(resultIm, zReal.getIm());
}

TEST(Gruzdeva_Diana_ComplexNumberTest, Strings) {
  std::string result = "-5.584201 -2.654666i";
  double re = -5.584201;
  double im = -2.654666;

  ComplexNumber z(re, im);
  std::string parsed = std::to_string(z.getRe()) + " " +
                       std::to_string(z.getIm())+"i";

  ASSERT_EQ(result, parsed);
}

TEST(Gruzdeva_Diana_ComplexNumberTest, Reciprocal) {
  double re1 = 1.0;
  double im1 = -1.0;
  double re2 = re1 / (re1 * re1 + im1 * im1);
  double im2 = (-1) * im1 / (re1 * re1 + im1 * im1);

  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber z(0.0, 0.0);
  z = z1 * z2;

  ASSERT_EQ(1, z.getRe());
  ASSERT_EQ(0, z.getIm());
}
