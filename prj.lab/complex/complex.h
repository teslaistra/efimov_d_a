//
// Created by danye on 11.10.2019.
//
#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
struct Complex {
    Complex() {}
    explicit Complex(const double real); //можно только так MyClass ob(110)
    Complex(const double real, const double imaginary);
    bool operator==(const Complex& com) const;
    bool operator!=(const Complex& com) const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);

    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);

    Complex& operator*=(const Complex& rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };

    static const char lb{ '{' };
    static const char sep{ ',' };
    static const char rb{ '}' };

    friend std::ostream &operator<<(std::ostream &ostrm, const Complex &rhs);
    friend std::istream &operator>>(std::istream &istrm, Complex &rhs);
    };

Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);

Complex operator*(const Complex& c1, const Complex& c2) ;
Complex operator/(const Complex& c1, const Complex& c2) ;

