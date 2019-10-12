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
    cout << "проверяю работу конструктора без параметров\n";
    Complex q = Complex();
    cout << q << endl;
    cout << "проверяю работу конструктора с одним параметром (1)\n";
    Complex a = Complex(1.0);
    cout << a << endl;

    cout << "проверяю работу конструктора с двумя параметрами (3 и 3)\n";
    Complex b = Complex(3.0, 3.0);
    cout << b << endl;

    cout << "тестируем сложение "<<b<<" + "<<a<<" = "<< b + a << endl;
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
    cout << "Тестируем " << b << " *= " << c <<" = "<< endl;
    b *= c;
    cout << b << endl;

    return 0;
}