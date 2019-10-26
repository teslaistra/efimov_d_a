#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "DynArray.h"

using namespace std;

int main()
{
	
	dynArray a(9);
	a[1] = 9; 
	dynArray b(10);
	b = a; 
	cout << a[1];
	cout << b[1];
	return 0;
}