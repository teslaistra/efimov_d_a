//
// Created by danye on 11.10.2019.
//
#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
#include "complex.h"

constexpr double eps = 2 * std::numeric_limits<double>::epsilon();

bool Complex::operator==(const Complex& rhs) const {
	return std::abs(re - rhs.re) < eps && std::abs(im - rhs.im) < eps;
}
bool Complex::operator!=(const Complex& com) const { return !operator==(com); }

Complex::Complex(const double real):Complex(real, 0.0) {}

Complex& Complex::operator+=(const double rhs) { return operator+=(Complex(rhs)); }

Complex& Complex::operator-=(const double rhs) { return operator-=(Complex(rhs)); }

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
	operator=(Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re));
	return *this;
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}




Complex operator+(const Complex& c1, const Complex& c2) {
    Complex sum;
    sum.re = c1.re + c2.re;
    sum.im = c1.im + c2.im;
    return sum;
}

Complex operator+(const Complex& lhs, const double rhs)
{
	return lhs+Complex(rhs,0);
}

Complex operator+(const double lhs, const Complex& rhs)
{
	return Complex(lhs,0)+rhs;
}

Complex operator-(const Complex& c1, const Complex& c2) {
    Complex sum;
    sum.re = c1.re - c2.re;
    sum.im = c1.im - c2.im;
    return sum;
}

Complex operator-(const Complex& lhs, const double rhs)
{
	return lhs-Complex(rhs,0);
}

Complex operator-(const double lhs, const Complex& rhs)
{
	return Complex(lhs,0)-rhs;
}


Complex operator/(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) /= rhs;
}


Complex operator/(const Complex& lhs, const double rhs) {
	return Complex(lhs.re / rhs, lhs.im / rhs);
}


Complex operator/(const double lhs, const Complex& rhs) {
	return Complex(lhs) /= rhs;
}

Complex& Complex::operator/=(const Complex& rhs) {
	if (rhs == Complex(0.0, 0.0)) {
		throw std::logic_error("Complex::operator/= - divizion to zero.");
	}
	const auto conj = Complex(rhs.re, -rhs.im);
	operator*=(conj);
	const double denum = (rhs * conj).re;
	re /= denum;
	im /= denum;
	return *this;
}

Complex& Complex::operator/=(const double rhs) {
	if (std::abs(rhs) < eps) {
		throw std::logic_error("Complex::operator/= - divizion by zero.");
	}
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) *= rhs;
}


Complex operator*(const Complex& lhs, const double rhs)
{
	return Complex(lhs.re*rhs, lhs.im*rhs);
}

Complex operator*(const double lhs, const Complex& rhs)
{
	return Complex(lhs*rhs.re,lhs*rhs.im);
}

std::istream &Complex::read_from(std::istream &istrm) {
    char left_brace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char right_brace(0);
    istrm >> left_brace >> real >> comma >> imaginary >> right_brace;

    if (istrm.good()) {
        if ((leftBrace == left_brace) && (separator == comma) &&
            (rightBrace == right_brace)) {
            re = real;
            im = imaginary;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}




std::ostream &Complex::write_to(std::ostream &ostrm) const {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

