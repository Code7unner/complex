#ifndef COMPLEX_COMPLEXNUM_H
#define COMPLEX_COMPLEXNUM_H

#include <ostream>
#include <istream>

#define EPS 1e-9

class Complex {
public:
    Complex(long double, long double);
    explicit Complex(long double);
    Complex();

    long double re() const;
    long double im() const;
    void re(long double);
    void im(long double);

    ~Complex() = default;

    Complex conjugate() const;
    long double my_sqr() const;

    Complex &operator=(const Complex &) = default;
    Complex &operator=(long double);

    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;

    Complex &operator+=(const Complex &);
    Complex &operator+=(long double);

    Complex &operator-=(const Complex &);
    Complex &operator-=(long double);

    Complex &operator*=(const Complex &);
    Complex &operator*=(long double);

    Complex &operator/=(const Complex &);
    Complex &operator/=(long double);

    friend Complex operator+(Complex, const Complex &);
    friend Complex operator+(Complex, long double);
    friend Complex operator+(long double, const Complex &);

    friend Complex operator-(Complex, const Complex &);
    friend Complex operator-(Complex, long double);
    friend Complex operator-(long double, const Complex &);

    friend Complex operator*(Complex, const Complex &);
    friend Complex operator*(Complex, long double);
    friend Complex operator*(long double, const Complex &);

    friend Complex operator/(Complex, const Complex &);
    friend Complex operator/(Complex, long double);
    friend Complex operator/(long double, const Complex &);

    long double abs() const;
    long double arg() const;

private:
    long double real, imag;
};

#endif