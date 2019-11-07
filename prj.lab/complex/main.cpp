#include "complex.h"
#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
using namespace std;
int main() {
    //setlocale(LC_ALL, "rus");
    //SetConsoleCP(866);
    cout << "�������� ������ ������������ ��� ����������\n";
    Complex q = Complex();
    cout << q << endl;
    cout << "�������� ������ ������������ � ����� ���������� (1)\n";
    Complex a = Complex(1.0);
    cout << a << endl;

    cout << "�������� ������ ������������ � ����� ����������� (3 � 3)\n";
    Complex b = Complex(3.0, 3.0);
    cout << b << endl;

    cout << "��������� �������� "<<b<<" + "<<a<<" = "<< b + a << endl;
    cout << "��������� ��������� " << b << " - " << a << " = " << b - a << endl;
    cout << "��������� ��������� " << b << " * " << a << " = " << b * a << endl;
    cout << "��������� ������� " << b << " / " << a << " = " << b / a << endl;

    cout << "��������� " << b << " += " << a << " = " << endl;
    b += a;
    cout << b << endl;
    cout << "��������� " << b << " -= " << a << " = " << endl;
    b -= a;
    cout << b << endl;

    Complex c = Complex(3, 4);
    cout << "��������� " << b << " *= " << c <<" = "<< endl;
    b *= c;
    cout << b << endl;

    return 0;
}