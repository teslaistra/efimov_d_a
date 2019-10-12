//
// Created by danye on 11.10.2019.
//
#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
#include "complex.h"

bool Complex::operator==(const Complex& com) const
{
    return (re == com.re) && (im == com.im);
}
bool Complex::operator!=(const Complex& com) const { return !operator==(com); }

Complex::Complex(const double real):Complex(real, 0.0) {}

Complex& Complex::operator+=(const double rhs) { return operator+=(Complex(rhs)); }

Complex& Complex::operator-=(const double rhs) { return operator+=(Complex(rhs)); }

Complex::Complex(const double real, const double img) {
    re = real;
    im = img;
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    re *= rhs.re;
    im *= rhs.im;
    return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    Complex sum;
    sum.re = c1.re + c2.re;
    sum.im = c1.im + c2.im;
    return sum;
}

Complex operator-(const Complex& c1, const Complex& c2) {
    Complex sum;
    sum.re = c1.re - c2.re;
    sum.im = c1.im - c2.im;
    return sum;
}

Complex operator/(const Complex& c1, const Complex& c2) {
    Complex de;
    if (c2.re == 0 || c2.im == 0) std::cout << "деление на ноль!" << std::endl;
    de.re = c1.re / c2.re;
    de.im = c1.im / c2.im;
    return de;
}

Complex operator*(const Complex& c1, const Complex& c2) {
    Complex mul;
    mul.re = c1.re * c2.re;
    mul.im = c1.im * c2.im;
    return mul;
}



std::istream &Complex::readFrom(std::istream &istrm) {
    char left_brace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char right_brace(0);
    istrm >> left_brace >> real >> comma >> imaginary >> right_brace;

    if (istrm.good()) {
        if ((Complex::lb == left_brace) && (Complex::sep == comma) &&
            (Complex::rb == right_brace)) {
            re = real;
            im = imaginary;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}



std::istream &operator>>(std::istream &istrm, Complex &rhs) {
    return rhs.readFrom(istrm);
}

std::ostream &operator<<(std::ostream &ostrm, const Complex &rhs) {
    return rhs.writeTo(ostrm);
}


std::ostream &Complex::writeTo(std::ostream &ostrm) const {
    ostrm << lb << re << sep << im << rb;
    return ostrm;
}