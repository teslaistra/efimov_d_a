#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
using namespace std;

struct Complex {
	Complex() {}
	explicit Complex(const double real); //можно только так MyClass ob(110)
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& com) const
	{
		return (re == com.re) && (im == com.im);
	}
	bool operator!=(const Complex& com) const { return !operator==(com); }

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator+=(Complex(rhs)); }

	Complex& operator*=(const Complex& rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);


	double re{ 0.0 };
	double im{ 0.0 };

	static const char lb{ '{' };
	static const char sep{ ',' };
	static const char rb{ '}' };

};

Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);

Complex::Complex(const double real) :Complex(real, 0.0) {}

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
	if (c2.re == 0 || c2.im == 0) cout << "деление на ноль!" << endl;
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
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
	ostrm << lb << re << sep << im << rb;
	return ostrm;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(866);
	cout << "проверяю работу конструктора без параметров\n";
	Complex q = Complex();
	cout << q << endl;
	cout << "проверяю работу конструктора с одним параметром (1)\n";
	Complex a = Complex(1.0);
	cout << a << endl;

	cout << "проверяю работу конструктора с двумя параметрами (3 и 3)\n";
	Complex b = Complex(3.0, 3.0);
	cout << b << endl;

	cout << "тестируем сложение " << b << " + " << a << " = " << b + a << endl;
	cout << "тестируем вычитание " << b << " - " << a << " = " << b - a << endl;
	cout << "тестируем умножение " << b << " * " << a << " = " << b * a << endl;
	cout << "тестируем деление " << b << " / " << a << " = " << b / a << endl;

	cout << "Тестируем " << b << " += " << a << " = " << endl;
	b += a;
	cout << b << endl;
	cout << "Тестируем " << b << " -= " << a << " = " << endl;
	b -= a;
	cout << b << endl;

	Complex c = Complex(3, 4);
	cout << "Тестируем " << b << " *= " << c << " = " << endl;
	b *= c;
	cout << b << endl;

	return 0;
}

