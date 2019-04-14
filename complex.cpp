#include <cmath>
#include <string>
#include "complex.h"

//======================COMPLEX_CLASS======================

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

// CONVERTING POLAR CORDS TO COMPLEX
Complex polar2Complex(const Polar &_val) {
    long double _x = _val.r() * cosl(_val.p());
    long double _y = _val.r() * sinl(_val.p());

    return Complex(_x, _y);
}

//======================POLAR_CLASS======================

// CONVERTING COMPLEX CORDS TO POLAR
Polar complex2Polar(const Complex &_val) {
    return Polar(_val.abs(), _val.arg());
}

// CONSTRUCTOR
Polar::Polar(long double _rho, long double _phi) {
    rho = _rho;
    phi = _phi;
}

Polar::Polar(long double _val) {
    rho = _val;
    phi = 0;
}

Polar::Polar() {
    rho = 0;
    phi = 0;
}

// GETTERS/SETTERS
long double Polar::r() const {
    return rho;
}

long double Polar::p() const {
    return phi;
}

void Polar::r(long double _val) {
    rho = _val;
}

void Polar::p(long double _val) {
    phi = _val;
}

// OVERLOADING "="
Polar& Polar::operator=(long double _val) {
    rho = _val;
    phi = atan2l(0, _val);

    return *this;
}

// OVERLOADING "=="
bool Polar::operator==(const Polar &_val) const {
    return polar2Complex(*this) == polar2Complex(_val);
}

// OVERLOADING "!="
bool Polar::operator!=(const Polar &_val) const {
    return !operator==(_val);
}

// OVERLOADING "+="
Polar& Polar::operator+=(const Polar &_val) {
    Complex _buff = polar2Complex(*this) + polar2Complex(_val);
    rho = complex2Polar(_buff).r();
    phi = complex2Polar(_buff).p();

    return *this;
}

// OVERLOADING "-="
Polar& Polar::operator-=(const Polar &_val) {
    Complex _buff = polar2Complex(*this) - polar2Complex(_val);
    rho = complex2Polar(_buff).r();
    phi = complex2Polar(_buff).p();

    return *this;
}

// OVERLOADING "*="
Polar& Polar::operator*=(const Polar &_val) {
    rho *= _val.r();
    phi += _val.p();

    return *this;
}

// OVERLOADING "/="
Polar& Polar::operator/=(const Polar &_val) {
    rho /= _val.r();
    phi -= _val.p();

    return *this;
}

// OVERLOADING "+"
Polar operator+(const Polar &_pLeft, const Polar &_pRight) {
    return complex2Polar(polar2Complex(_pLeft) + polar2Complex(_pRight));
}

// OVERLOADING "-"
Polar operator-(const Polar &_pLeft, const Polar &_pRight) {
    return complex2Polar(polar2Complex(_pLeft) - polar2Complex(_pRight));
}

// OVERLOADING "*"
Polar operator*(Polar _pLeft, const Polar &_pRight) {
    _pLeft *= _pRight;

    return _pLeft;
}

// OVERLOADING "/"
Polar operator/(Polar _pLeft, const Polar &_pRight) {
    _pLeft /= _pRight;

    return _pLeft;
}
