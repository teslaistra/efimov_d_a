//
// Created by danye on 11.10.2019.
//

#include <iostream>
struct  Rational
{
    Rational& operator+=(const Rational& arg);

    Rational& operator/=(const Rational& first);

    Rational& operator*=(const Rational& first);

    Rational& operator-=(const Rational& first);

    Rational& operator=(const Rational& first);

    bool operator==(const Rational& first);

    bool operator!=(const Rational& first);

    bool operator<(const Rational& first);

    bool operator>(const Rational& first);

    bool operator>=(const Rational& first);

    bool operator<=(const Rational& first);

    int gcd(int a, int b);

    Rational();
    explicit Rational(const int chislit);
    Rational(const int chislitel, const int znamenatel);

    void check();

    std::ostream &WriteTo(std::ostream &ostrm) const;
    std::istream &ReadFrom(std::istream &istrm);

    int chis{ 0 };
    int znam{ 1 };

    static const char lb{ '{' };
    static const char sep{ '/' };
    static const char rb{ '}' };

    void simple();

    friend std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs);
    friend std::istream &operator>>(std::istream &istrm, Rational &rhs);
};

Rational operator+(const Rational& first, const Rational& second);
Rational operator*(const Rational& first, const Rational& second);
Rational operator-(const Rational& first, const Rational& second);
Rational operator/(const Rational& first, const Rational& second);

bool testParse(const std::string& str);
