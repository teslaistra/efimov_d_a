#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
using namespace std;


struct  Rational
{
	int gcd(int a, int b) {
		while (a != b) {
			if (a > b) a = a - b;
			else b = b - a;
		}
		return(a);
	}
	Rational& operator+=(const Rational& arg) { //всегда возвращать ссылку на себя
		chis = chis * arg.znam + arg.chis * znam;
		znam = znam * arg.znam;
		return (*this);
	}

	Rational& operator/=(const Rational& first) {
		chis *= first.znam;
		znam *= first.chis;
		return (*this);
	};

	Rational& operator*=(const Rational& first) {
		chis *= first.chis;
		znam *= first.znam;
		return *this;
	};

	Rational& operator-=(const Rational& first) {
		chis = chis*first.znam - first.chis * znam;
		znam = znam * first.znam;
		return *this;
	};

	Rational& operator=(const Rational& first) {
		chis = first.chis;
		znam = znam;
		return *this;
	};

	bool operator==(const Rational& first) {
		if (first.znam == znam && chis == first.chis)
			return true;
		return false;
	}

	bool operator!=(const Rational& first) {
		return !operator==(first);
	}

	bool operator<(const Rational& first)
	{
		if (chis * first.znam < first.znam * znam) return true;
		return false;
	}

	bool operator>(const Rational& first)
	{
		return !operator<(first);
	}

	bool operator>=(const Rational& first)
	{
		return(operator==(first) || operator>(first));
	}

	bool operator<=(const Rational& first)
	{
		return(operator==(first) || !operator>(first));
	}

	void simple() {
		int i = gcd(chis, znam);
		chis /= i;
		znam /= i;
	}

	Rational() {
		znam = 1;
		chis = 1;
	}
	Rational(const int chislit) {
		chis = chislit;
		znam = 1;
	}
	Rational(const int chislitel, const int znamenatel) {
		chis = chislitel;
		znam = znamenatel;
		check();
	}

	void check() {
		using namespace std;
		if (znam == 0){ cout << "You are trying divide on zero"; znam = 1;}

	}

	int chis{ 0 };
	int znam{ 1 };

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	static const char lb{ '{' };
	static const char sep{ '/' };
	static const char rb{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.readFrom(istrm);
}

std::istream& Rational::readFrom(std::istream& istrm) {
	char leftBrace(0);
	int chislit(0);
	char separator(0);
	int znamental(1);
	char rightBrace(0);
	istrm >> leftBrace >> chislit >> separator >> znamental >> rightBrace;
	if (istrm.good()) {
		if ((Rational::lb == leftBrace) && (Rational::sep == separator) &&
			(Rational::rb == rightBrace)) {
			chis = chislit;
			znam = znamental;
			check();
			
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

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

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << lb << chis << sep << znam << rb;
	return ostrm;
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
};

Rational operator/(const Rational& first, const Rational& second) {
	Rational div;
	div.chis = first.chis * second.znam;
	div.znam = first.znam * second.chis;
	return div;
};

int main() {
	using namespace std;
	setlocale(LC_ALL, "rus");
	SetConsoleCP(866);
	cout << "проверяю работу конструктора без параметров\n";
	Rational a;
	cout << a << endl;

	cout << "проверяю работу конструктора c одним параметром(числитель = 5)\n";
	Rational b(5); 
	cout << b << endl;

	cout << "проверяю работу конструктора с двумя параметрам(10 и 3)\n";
	Rational c(10,3);
	cout << c << endl;

	cout << "проверяю работу конструктора с двумя параметрами(10 и 2), и сразу сокращу дробь\n";
	Rational d(10, 2);
	d.simple();
	cout << d << endl;
	
	Rational z(5, 2);
	Rational x(2, 3);
	cout << "тестирую умножение на " << z << " и " << x << endl;
	cout << z * x << endl;
	
	cout << "тестирую сложение на " << z << " и " << x << endl;
	cout << z + x << endl;

	cout << "тестирую деление на " << z << " и " << x << endl;
	cout << z / x << endl;

	cout << "тестирую вычитание на " << z << " и " << x << endl;
	cout << z - x << endl;

	cout << "сравниваю " << z << " > " << x << endl;
	cout << (z > x) << endl;

	cout << "сравниваю " << z << " < " << x << endl;
	cout << (z < x) << endl;

	Rational x1(2, 3);
	cout << "сравниваю " << x << " <= " << x1 << endl;
	cout << (x <= x1) << endl;

	cout << "сравниваю " << x << " <= " << z << endl;
	cout << (x <= z) << endl;

	cout << "сравниваю " << x << " >= " << x1 << endl;
	cout << (x >= x1) << endl;

	cout << "сравниваю " << x << " >= " << z << endl;
	cout << (x >= z) << endl;

	cout << "проверяю " << x << " == " << x1 << endl;
	cout << (x == x1) << endl;

	cout << "проверяю " << x << " != " << x1 << endl;
	cout << (x != x1) << endl;

	cout << "проверяю " << x << " == " << z << endl;
	cout << (x == z) << endl;

	cout << "проверяю " << x << " != " << z << endl;
	cout << (x != z) << endl;

	cout << "проверяю " << x << " += " << z << endl;
	cout << (x += z) << endl; 

	cout << "проверяю " << x << " -= " << z << endl;
	cout << (x -= z) << endl;
	x.simple();
	cout << "упростим и получим:" << x << endl;

	cout << "проверяю" << x << " *= " << z << endl;
	cout << (x *= z) << endl;

	cout << "проверяю" << x << " /= " << z << endl;
	cout << (x /= z) << endl;
	x.simple();
	cout << "упростим и получим: " << x << endl;

	cout << "протестируем =" << endl;
	Rational t = x;
	cout << t;
	testParse("{8/9}");

	testParse("{8/9");
	
	return 0;

}