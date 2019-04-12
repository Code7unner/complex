#include <cmath>
#include <string>
#include "complex.h"

// CONSTRUCTOR
Complex::Complex(long double _re, long double _im) {
    real = _re;
    imag = _im;
}

Complex::Complex(long double _val) {
    real = _val;
    imag = 0;
}

Complex::Complex() {
    real = 0;
    imag = 0;
}

// GETTERS/SETTERS
long double Complex::re() const {
    return this->real;
}

long double Complex::im() const {
    return this->imag;
}

void Complex::re(long double _val) {
    real = _val;
}

void Complex::im(long double _val) {
    imag = _val;
}

// MY SQR FUNC FOR COMPLEX
long double Complex::my_sqr() const {
    return real * real + imag * imag;
}

// FIND CONJUGATE OF A COMPLEX
Complex Complex::conjugate() const {
    long double _complex_sqr = my_sqr();
    long double _re = real / _complex_sqr;
    long double _im = -imag / _complex_sqr;

    return Complex(_re, _im);
}

// OVERLOADING "="
Complex &Complex::operator=(long double _val) {
    real = _val;
    imag = 0;

    return *this;
}

// OVERLOADING "=="
bool Complex::operator==(const Complex &_c) const {
    return fabsl(real - _c.real) < EPS && fabsl(imag - _c.imag) < EPS;
}

// OVERLOADING "!="
bool Complex::operator!=(const Complex &_c) const {
    return !operator==(_c);
}

// OVERLOADING "+="
Complex &Complex::operator+=(const Complex &_c) {
    real += _c.real;
    imag += _c.imag;

    return *this;
}

Complex &Complex::operator+=(long double _val) {
    real += _val;

    return *this;
}

// OVERLOADING "-="
Complex &Complex::operator-=(const Complex &_c) {
    real -= _c.real;
    imag -= _c.imag;

    return *this;
}

Complex &Complex::operator-=(long double _val) {
    real -= _val;

    return *this;
}

// OVERLOADING "*="
Complex &Complex::operator*=(const Complex &_c) {
    long double _old_re = real;

    real = real * _c.real - imag * _c.imag;
    imag = _old_re * _c.imag + imag * _c.real;

    return *this;
}

Complex& Complex::operator*=(long double _val) {
    real *= _val;
    imag *= _val;

    return *this;
}

// OVERLOADING "/="
Complex &Complex::operator/=(const Complex &_c) {
    Complex _c_new = *this * _c.conjugate();
    real = _c_new.re();
    imag = _c_new.im();

    return *this;
}

Complex &Complex::operator/=(long double _val) {
    real /= _val;
    imag /= _val;

    return *this;
}

// OVERLOADING "+"
Complex operator+(Complex _cLeft, const Complex &_cRight) {
    _cLeft += _cRight;

    return _cLeft;
}

Complex operator+(Complex _cLeft, long double _valRight) {
    _cLeft += _valRight;

    return _cLeft;
}

Complex operator+(long double _valLeft, const Complex &_cRight) {
    Complex _cLeft(_valLeft, 0);
    _cLeft += _cRight;

    return _cLeft;
}

// OVERLOADING "-"
Complex operator-(Complex _cLeft, const Complex &_cRight) {
    _cLeft -= _cRight;

    return _cLeft;
}

Complex operator-(Complex _cLeft, long double _valRight) {
    _cLeft -= _valRight;

    return _cLeft;
}

Complex operator-(long double _valLeft, const Complex &_cRight) {
    Complex _cLeft(_valLeft, 0);
    _cLeft -= _cRight;

    return _cLeft;
}

// OVERLOADING "*"
Complex operator*(Complex _cLeft, const Complex &_cRight) {
    _cLeft *= _cRight;

    return _cLeft;
}

Complex operator*(Complex _cLeft, long double _valRight) {
    _cLeft *= _valRight;

    return _cLeft;
}

Complex operator*(long double _valLeft, const Complex &_cRight) {
    Complex _cLeft(_valLeft, 0);
    _cLeft *= _cRight;

    return _cLeft;
}

// OVERLOADING "/"
Complex operator/(Complex _cLeft, const Complex &_cRight) {
    _cLeft /= _cRight;

    return _cLeft;
}

Complex operator/(Complex _cLeft, long double _valRight) {
    _cLeft /= _valRight;

    return _cLeft;
}

Complex operator/(long double _valLeft, const Complex &_cRight) {
    Complex _cLeft(_valLeft, 0);
    _cLeft /= _cRight;

    return _cLeft;
}

// MY ABS FUNC FOR COMPLEX)
long double Complex::abs() const {
    return sqrtl(my_sqr());
}

// MY ARG FUNC FOR COMPLEX
long double Complex::arg() const {
    return atan2l(imag, real);
}