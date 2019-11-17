#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

class Rational {
public:
	Rational() = default;
	Rational(const Rational&) = default;
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denominator);
	Rational& operator=(const Rational&) = default;

	Rational operator-() const;
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }

	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	bool operator>(const Rational& rhs);
	bool operator<(const Rational& rhs);
	bool operator>=(const Rational& rhs);
	bool operator<=(const Rational& rhs);

	std::ostream& write_to(std::ostream& ostrm) const;
	std::istream& read_from(std::istream& istrn);

	void normalize();

public:
	int num_{ 0 };
	int denum_{ 1 };
	static const char lb{ '{' };
	static const char sep{ '/' };
	static const char rb{ '}' };
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif