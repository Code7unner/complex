#include <gtest/gtest.h>
#include "complex.h"
#include <math.h>

// Complex numbers test
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
    Complex x1(6, 12), x2(3, 6);
    auto b = 2;
    EXPECT_EQ(x1 / b, Complex(3, 6));
    x1 /= b;
    EXPECT_EQ(x1, Complex(3, 6));
}

TEST(ComplexNumbersTests, multiplicationTest) {
    Complex x1(2, 3), x2(4, 6);
    EXPECT_EQ(x1 * x2, Complex(-10, 24));
    EXPECT_EQ(x2 * x1, Complex(-10, 24));
    x1 *= x2;
    EXPECT_EQ(x1, Complex(-10, 24));
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

TEST(ComplexNumbersTests, powTest) {
    Complex x1(0, 1);
    EXPECT_EQ(pow(x1, 2), Complex(-1, 5.01655761266833202345e-20));
}

// Polar cords test
TEST(PolarNumbersTests, isEmptyTest) {
    Polar x1(1.1, 2.2), x2(1.1, 2.2);
    EXPECT_EQ(x1, x2);
    EXPECT_EQ(x1, x1);
    EXPECT_EQ(x1, Polar(1.1, 2.2));
    x1 = Polar(2.28, 14.88);
    EXPECT_EQ(x1, Polar(2.28, 14.88));
}

TEST(PolarNumbersTests, getSetTest) {
    Polar x1(2.0, 5.0);
    x1.p(9.0);
    EXPECT_EQ(x1, Polar(2.0, 9.0));
    x1.r(-9.0);
    EXPECT_EQ(x1, Polar(-9.0, 9.0));
    EXPECT_EQ(x1.p(), 9.0);
    EXPECT_EQ(x1.r(), -9.0);
}

TEST(PolarNumbersTests, sumTest) {
    Polar x1(2.0, 3.0), x2(4.0, 5.0);
    Polar x3 = x1 + x2;
    EXPECT_EQ(x3, Polar(3.65262242987770661918, -1.80434642873943556335));
}

TEST(PolarNumbersTests, minusTest) {
    Polar x1(2.0, 3.0), x2(4.0, 6.0);
    Polar x3 = x2 - x1;
    EXPECT_EQ(x3, Polar(5.98664179199049183589, -0.236022860519899068296));
}

TEST(PolarNumbersTests, divTest) {
    Polar x1(2.0, 4.0), x2(3.3, -6.6);
    Polar x3 = x2 / x1;
    EXPECT_EQ(x3, Polar(1.64999999999999991118, -10.5999999999999996447));
}

TEST(PolarNumbersTests, multiplicationTest) {
    Polar x1(2.0, 4.0), x2(3.3, -6.6);
    Polar x3 = x2 * x1;
    EXPECT_EQ(x3, Polar(6.59999999999999964473, -2.59999999999999964473));
}

TEST(PolarNumbersTests, powTest) {
    Polar x1(4, M_PI_4);
    EXPECT_EQ(pow(x1, 2), Polar(16, M_PI_2));
}
