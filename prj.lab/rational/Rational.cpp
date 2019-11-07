#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
#include "rational.h"

Rational::Rational(const int chislit) {
    chis = chislit;
    znam = 1;
}
Rational::Rational(const int chislitel, const int znamenatel) {
    chis = chislitel;
    znam = znamenatel;
    check();
}

void Rational::check() {
    using namespace std;
    if (znam == 0) { cout << "You are trying divide on zero"; znam = 1; }
}

int Rational::gcd(int a, int b) {
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return(a);
}

Rational& Rational::operator+=(const Rational& arg) { //всегда возвращать ссылку на себя
    chis = chis * arg.znam + arg.chis * znam;
    znam = znam * arg.znam;
    return (*this);
}
Rational& Rational::operator/=(const Rational& first) {
    chis *= first.znam;
    znam *= first.chis;
    return (*this);
};

Rational& Rational::operator*=(const Rational& first) {
    chis *= first.chis;
    znam *= first.znam;
    return *this;
};

Rational& Rational::operator-=(const Rational& first) {
    chis = chis * first.znam - first.chis * znam;
    znam = znam * first.znam;
    return *this;
};

Rational& Rational::operator=(const Rational& first) = default;

bool Rational::operator==(const Rational& first) {
    return (first.znam == znam && chis == first.chis);
}

bool Rational::operator!=(const Rational& first) {
    return !operator==(first);
}

bool Rational::operator<(const Rational& first)
{
    return chis * first.znam < first.znam * znam;
}

bool Rational::operator>(const Rational& first)
{
    return !operator<(first);
}

bool Rational::operator>=(const Rational& first)
{
    return(operator==(first) || operator>(first));
}

bool Rational::operator<=(const Rational& first)
{
    return(operator==(first) || !operator>(first));
}

Rational operator+(const Rational& first, const Rational& second) {
    Rational sum;
    sum.chis = first.chis * second.znam + second.chis * first.znam;
    sum.znam = first.znam * second.znam;
    return sum;
};

Rational operator-(const Rational& first, const Rational& second) {
    Rational res;
    res.chis = first.chis * second.znam - second.chis * first.znam;
    res.znam = first.znam * second.znam;
    return res;
};

Rational operator*(const Rational& first, const Rational& second) {
    Rational mul;
    mul.chis = first.chis * second.chis;
    mul.znam = first.znam * second.znam;
    return mul;
}

Rational operator/(const Rational& first, const Rational& second) {
    Rational div;
    div.chis = first.chis * second.znam;
    div.znam = first.znam * second.chis;
    return div;
};

bool testParse(const std::string& str) {
    using namespace std;
    istringstream istrm(str);
    Rational z;
    istrm >> z;

    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else {
        cout << "Read error : " << str << " -> " << z << endl;
    }
    return istrm.good();
}

void Rational::simple() {
    int i = gcd(chis, znam);
    chis /= i;
    znam /= i;
}

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) {
    return rhs.WriteTo(ostrm);
}

std::istream &operator>>(std::istream &istrm, Rational &rhs) {

    return rhs.ReadFrom(istrm);

}

std::ostream &Rational::WriteTo(std::ostream &ostrm) const {
    ostrm << lb << chis << sep << znam << rb;
    return ostrm;
}

std::istream &Rational::ReadFrom(std::istream &istrm) {
    char lb{ '{' };
    char sep{ '/' };
    char rb{ '}' };

    istrm >> lb >>  chis >> sep >> znam >> rb;

    if (istrm.good()) {

        if ((Rational::lb == lb) && (Rational::sep == sep) &&
            (Rational::rb == rb)) {

            Rational::chis = chis;
            Rational::znam =znam;

            Rational::check();
            Rational::simple();
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

Rational::Rational() {chis=1; znam=1;

}
