#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
using namespace std;
#include "rational.h"

Rational::Rational(const int numerator, const int denominator)
	: num_(numerator), denum_(denominator) {
	if (0 == denum_) {
		throw std::invalid_argument("Деление на ноль в конструкторе");
	}
	normalize();

}

int gcd(int a, int b)
{
	while ((a != b) && (a != 0))
	{
		if (a > b) a -= b;
		else b -= a;
	}
	return(b);
}

Rational Rational::operator-() const {
	return Rational(-num_, denum_);
}

Rational& Rational::operator+=(const Rational& arg) { //всегда возвращать ссылку на себя
	num_ = num_ * arg.denum_ + arg.num_ * denum_;
	denum_ = denum_ * arg.denum_;
	normalize();
	return (*this);
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num_ = num_ * rhs.denum_ - denum_ * rhs.num_;
	denum_ = denum_ * rhs.denum_;
	normalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& first) {
	num_ *= first.denum_;
	denum_ *= first.num_;
	normalize();
	return (*this);
}
bool Rational::operator==(const Rational& rhs) const {
	return num_ == rhs.num_ && denum_ == rhs.denum_;
}
void Rational::normalize()
{
	if (denum_ == 0) throw std::invalid_argument("zero in denumenator");
	int i = gcd(abs(num_), abs(denum_));
	num_ /= i;
	denum_ /= i;
	if (denum_ < 0) {
		num_ *= -1;
		denum_ *= -1;
	}
	/*
	int a = abs(num_);
	int b = abs(denum_);
	while ((a != b) && (a != 0))
	{
		if (a > b) a -= b;
		else b -= a;
	}
	num_ /= b;
	denum_ /= b;
	if (denum_ < 0) {
		num_ *= -1;
		denum_ *= -1;
	};
	*/
}

Rational& Rational::operator*=(const Rational& first) {
	num_ *= first.num_;
	denum_ *= first.denum_;
	normalize();
	return *this;
};


bool Rational::operator!=(const Rational& first) const {
	return !operator==(first);
}

bool Rational::operator<(const Rational& first)
{
	if (num_ * first.denum_ < first.denum_ * denum_) return true;
	return false;
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

Rational::Rational(const int num_lit) {
	num_ = num_lit;
	denum_ = 1;
}


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.write_to(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.read_from(istrm);
}
/*
std::istream& Rational::read_from(std::istream& istrm) {
	char leftBrace(0);
	int num_lit(0);
	char separator(0);
	int denum_ental(1);
	char rightBrace(0);
	istrm >> num_lit >> separator >> denum_ental;
	if (istrm.good()) {
		if (sep == separator) {
			num_ = num_lit;
			denum_ = denum_ental;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
*/
std::istream& Rational::read_from(std::istream& istrm) {
	// TODO:
	istrm >> num_;
	char c(0);
	istrm.get(c);
	if ('/' != c) {
		istrm.setstate(std::ios_base::failbit);
	}
	istrm.get(c);
	if (c < '0' || '9' < c) {
		istrm.setstate(std::ios_base::failbit);
	}
	istrm.putback(c);
	istrm >> denum_;
	normalize();
	return istrm;
}

std::ostream& Rational::write_to(std::ostream& ostrm)  const
{
	ostrm << num_ << sep << denum_;
	return ostrm;
}
Rational operator+(const Rational& first, const Rational& second) {
	Rational sum;
	sum.num_ = first.num_ * second.denum_ + second.num_ * first.denum_;
	sum.denum_ = first.denum_ * second.denum_;
	sum.normalize();
	return sum;
};

Rational operator-(const Rational& first, const Rational& second) {
	Rational res;
	res.num_ = first.num_ * second.denum_ - second.num_ * first.denum_;
	res.denum_ = first.denum_ * second.denum_;
	res.normalize();
	return res;
};

Rational operator*(const Rational& first, const Rational& second) {
	Rational mul;
	mul.num_ = first.num_ * second.num_;
	mul.denum_ = first.denum_ * second.denum_;
	mul.normalize();

	return mul;
}


Rational operator/(const Rational& first, const Rational& second) {
	Rational div;
	div.num_ = first.num_ * second.denum_;
	div.denum_ = first.denum_ * second.num_;
	div.normalize();
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