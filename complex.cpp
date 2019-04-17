#include <cmath>
#include <string>
#include "complex.h"

//======================COMPLEX_CLASS======================

// CONSTRUCTOR
Complex::Complex(long double _re, long double _im) : real(_re), imag(_im) {}

Complex::Complex(long double _val) {
    real = _val;
    imag = 0;
}

Complex::Complex() {
    real = 0;
    imag = 0;
}

Complex::Complex(Polar n) {
    real = n.r() * cosl(n.p());
    imag = n.r() * sinl(n.p());
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

// MY POW() FUNCTION
Complex pow(const Complex &x, uint32_t y) {
    return Complex(pow(Polar(x), y));
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
Polar::Polar(long double _rho, long double _phi) : rho(_rho), phi(_phi) {}

Polar::Polar(long double _val) {
    rho = _val;
    phi = 0;
}

Polar::Polar() {
    rho = 0;
    phi = 0;
}

Polar::Polar(Complex n) {
    rho = n.abs();
    phi = n.arg();
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
    return Complex(*this) == Complex(_val);
}

bool Polar::operator==(const Complex &_val) const {
    return Complex(*this) == _val;
}

// OVERLOADING "!="
bool Polar::operator!=(const Polar &_val) const {
    return !operator==(_val);
}

bool Polar::operator!=(const Complex &_val) const {
    return !operator==(_val);
}

// OVERLOADING "+="
Polar& Polar::operator+=(const Polar &_val) {
    auto t = *this + _val;
    rho = t.r();
    phi = t.p();

    return *this;
}

Polar &Polar::operator+=(long double _val) {
    auto t = *this + _val;
    rho = t.r();
    phi = t.p();

    return *this;
}

// OVERLOADING "-="
Polar& Polar::operator-=(const Polar &_val) {
    auto t = *this - _val;
    rho = t.r();
    phi = t.p();

    return *this;
}

Polar &Polar::operator-=(long double _val) {
    auto t = *this - _val;
    rho = t.r();
    phi = t.p();

    return *this;
}

// OVERLOADING "*="
Polar& Polar::operator*=(const Polar &_val) {
    rho *= _val.r();
    phi += _val.p();

    return *this;
}

Polar &Polar::operator*=(long double val) {
    rho *= val;
    return *this;
}

// OVERLOADING "/="
Polar& Polar::operator/=(const Polar &_val) {
    rho /= _val.r();
    phi -= _val.p();

    return *this;
}

Polar &Polar::operator/=(long double val) {
    rho /= val;
    return *this;
}

// OVERLOADING "+"
Polar operator+(const Polar &_pLeft, const Polar &_pRight) {
    return Polar(Complex(_pLeft) + Complex(_pRight));
}

Polar operator+(const Polar &_pLeft, long double _pRight) {
    return Polar(Complex(_pLeft) + _pRight);
}

Polar operator+(long double _pLeft, const Polar &_pRight) {
    return _pRight + _pLeft;
}

// OVERLOADING "-"
Polar operator-(const Polar &_pLeft, const Polar &_pRight) {
    return Polar(Complex(_pLeft) - Complex(_pRight));
}

Polar operator-(const Polar &_pLeft, long double _pRight) {
    return Polar(Complex(_pLeft) - _pRight);
}

Polar operator-(long double _pLeft, const Polar &_pRight) {
    return -_pRight + _pLeft;
}

Polar operator-(Polar val) {
    return val * -1;
}

// OVERLOADING "*"
Polar operator*(Polar _pLeft, const Polar &_pRight) {
    _pLeft *= _pRight;

    return _pLeft;
}

Polar operator*(Polar _pLeft, long double _pRight) {
    _pLeft *= _pRight;
    return _pLeft;
}

Polar operator*(long double _pLeft, Polar _pRight) {
    _pRight *= _pLeft;
    return _pRight;
}

// OVERLOADING "/"
Polar operator/(Polar _pLeft, const Polar &_pRight) {
    _pLeft /= _pRight;

    return _pLeft;
}

Polar operator/(Polar _pLeft, long double _pRight) {
    _pLeft /= _pRight;
    return _pLeft;
}

Polar operator/(long double _pLeft, const Polar &_pRight) {
    return Polar(Complex(_pLeft, 0)) / _pRight;
}

// MY POW() FUNCTION
Polar pow(Polar x, uint32_t y) {
    x.r(powl(x.r(), y));
    x.p(x.p() * y);

    return Polar(Complex(x));
}