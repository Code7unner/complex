#ifndef COMPLEX_COMPLEXNUM_H
#define COMPLEX_COMPLEXNUM_H

#include <ostream>
#include <istream>

#define EPS 1e-9

class Polar;

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

    friend Complex polar2Complex(const Polar &);

    //TODO: pow() - func for Complex cords

private:
    long double real, imag;
};

class Polar {
public:
    Polar(long double, long double);
    explicit Polar(long double);
    Polar();

    long double r() const;
    long double p() const;
    void r(long double);
    void p(long double);

    ~Polar() = default;

    Polar &operator=(const Polar &) = default;
    Polar &operator=(long double);

    bool operator==(const Polar &) const;
    bool operator!=(const Polar &) const;

    Polar &operator+=(const Polar &);
    Polar &operator-=(const Polar &);
    Polar &operator*=(const Polar &);
    Polar &operator/=(const Polar &);

    friend Polar operator+(const Polar &, const Polar &);
    friend Polar operator-(const Polar &, const Polar &);
    friend Polar operator*(Polar, const Polar &);
    friend Polar operator/(Polar, const Polar &);

    friend Polar complex2Polar(const Complex &);

    //TODO: pow() - func for Polar cords

private:
    long double rho, phi;
};

#endif