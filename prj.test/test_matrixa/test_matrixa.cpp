#include "matrixa.h"
#include <iostream>
int main() {
	MatrixA a(10,10);
	a.at(0, 0) = 10;
	std::cout << a.at(0, 0);
	return 0;
}