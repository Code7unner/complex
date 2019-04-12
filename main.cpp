#include <gtest/gtest.h>
#include <tgmath.h>
#include "complex.h"

//Complex numbers test
TEST(ComplexNumbersTests, isEmptyTest) {
    Complex x1(1.1, 2.2), x2(1.1, 2.2);
    EXPECT_EQ(x1, x2);
    EXPECT_EQ(x1, x1);
    EXPECT_EQ(x1, Complex(1.1, 2.2));
    x1 = Complex(2.28, 14.88);
    EXPECT_EQ(x1, Complex(2.28, 14.88));
}

TEST(ComplexNumbersTests, sumTest) {
    Complex x1(1.1, 2.2), x2(3.3, 4.4), x3(-5.5, -6.6);
    EXPECT_EQ(x1 + x2, Complex(4.4, 6.6));
    EXPECT_EQ(x1 + x3, Complex(-4.4, -4.4));
    x1 += x1;
    EXPECT_EQ(x1, Complex(2.2, 4.4));
}

TEST(ComplexNumbersTests, minusTest) {
    Complex x1(7.0, 3.0), x2(5.0, -8.0), x3(-10.1, -4.2);
    EXPECT_EQ(x1 - x2, Complex(2.0, 11.0));
    EXPECT_EQ(x2 - x1, Complex(-2.0, -11.0));
    EXPECT_EQ(x2 - x3, Complex(15.1, -3.8));
}

TEST(ComplexNumbersTests, divTest) {
    Complex x1(2.0, 4.0), x2(3.3, -6.6);
    EXPECT_EQ(x1 / x2, Complex(-0.99, 1.32));
}


TEST(ComplexNumbersTests, getSetTest) {
    Complex x1(2.0, 5.0);
    x1.im(9.0);
    EXPECT_EQ(x1, Complex(2.0, 9.0));
    x1.re(-9.0);
    EXPECT_EQ(x1, Complex(-9.0, 9.0));
    EXPECT_EQ(x1.im(), 9.0);
    EXPECT_EQ(x1.re(), -9.0);
}

TEST(ComplexNumbersTests, absTest) {
    Complex x1(4.0, 3.0);
    EXPECT_EQ(x1.abs(), 5.0);
}

TEST(ComplexNumbersTests, argTest) {
    Complex x1(3.0, 1.0), x2(9.0, 3.0);
    EXPECT_EQ(x1.arg(), x2.arg());
}
