#include <iostream>
#include "StackL.h"

int main() {

	
	StackL sta;
	std::cout << "Is StackL empty?\n";
	std::cout << sta.is_empty()<<"\n";
	std::cout << "push 4 to StackL\n";
	sta.push(4);
	std::cout << "top on StackL\n";
	std::cout << float(sta.top())<<"\n";
	std::cout << "push 5 to StackL\n";
	sta.push(5);
	std::cout << "top on StackL\n";
	std::cout << float(sta.top())<<"\n";
	std::cout << "pop"<<"\n";
	sta.pop();
	std::cout << "top on StackL\n";
	std::cout << float(sta.top()) << "\n";
	std::cout << "making copy of StackL\n";
	StackL sta1(sta);
	std::cout << "top on StackL1\n";
	std::cout << float(sta1.top()) << "\n";
	std::cout << " StackL2=StackL \n";
	StackL sta2 = sta; 
	std::cout << " top on StackL2 \n";
	std::cout << float(sta2.top()) << "\n";
	std::cout << "finish";


	return 0;
}