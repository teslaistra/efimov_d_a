#include <iostream>

#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
using namespace std;
#include <rational.h>

int main() {
    using namespace std;
    cout << "�������� ������ ������������ ��� ����������\n";
    Rational a;
    cout << a << endl;

    cout << "�������� ������ ������������ c ����� ����������(��������� = 5)\n";
    Rational b(5);
    cout << b << endl;

    cout << "�������� ������ ������������ � ����� ����������(10 � 3)\n";
    Rational c(10, 3);
    cout << c << endl;

    cout << "�������� ������ ������������ � ����� �����������(10 � 2), � ����� ������� �����\n";
    Rational d(10, 2);
    d.simple();
    cout << d << endl;

    Rational z(5, 2);
    Rational x(2, 3);
    cout << "�������� ��������� �� " << z << " � " << x << endl;
    cout << z * x << endl;

    cout << "�������� �������� �� " << z << " � " << x << endl;
    cout << z + x << endl;

    cout << "�������� ������� �� " << z << " � " << x << endl;
    cout << z / x << endl;

    cout << "�������� ��������� �� " << z << " � " << x << endl;
    cout << z - x << endl;

    cout << "��������� " << z << " > " << x << endl;
    cout << (z > x) << endl;

    cout << "��������� " << z << " < " << x << endl;
    cout << (z < x) << endl;

    Rational x1(2, 3);
    cout << "��������� " << x << " <= " << x1 << endl;
    cout << (x <= x1) << endl;

    cout << "��������� " << x << " <= " << z << endl;
    cout << (x <= z) << endl;

    cout << "��������� " << x << " >= " << x1 << endl;
    cout << (x >= x1) << endl;

    cout << "��������� " << x << " >= " << z << endl;
    cout << (x >= z) << endl;

    cout << "�������� " << x << " == " << x1 << endl;
    // cout << (x == x1) << endl;

    cout << "�������� " << x << " != " << x1 << endl;
    //cout << (x != x1) << endl;

    cout << "�������� " << x << " == " << z << endl;
    cout << (x == z) << endl;

    cout << "�������� " << x << " != " << z << endl;
    cout << (x != z) << endl;

    cout << "�������� " << x << " += " << z << endl;
    cout << (x += z) << endl;

    cout << "�������� " << x << " -= " << z << endl;
    cout << (x -= z) << endl;
    x.simple();
    cout << "�������� � �������:" << x << endl;

    cout << "��������" << x << " *= " << z << endl;
    cout << (x *= z) << endl;

    cout << "��������" << x << " /= " << z << endl;
    cout << (x /= z) << endl;
    x.simple();
    cout << "�������� � �������: " << x << endl;

    cout << "������������ =" << endl;
    Rational t = x;
    cout << t;
    testParse("{8/9}");

    testParse("{8/9");

    return 0;

}