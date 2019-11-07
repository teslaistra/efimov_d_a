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
    cout << "проверяю работу конструктора без параметров\n";
    Rational a;
    cout << a << endl;

    cout << "проверяю работу конструктора c одним параметром(числитель = 5)\n";
    Rational b(5);
    cout << b << endl;

    cout << "проверяю работу конструктора с двумя параметрам(10 и 3)\n";
    Rational c(10, 3);
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
    // cout << (x == x1) << endl;

    cout << "проверяю " << x << " != " << x1 << endl;
    //cout << (x != x1) << endl;

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