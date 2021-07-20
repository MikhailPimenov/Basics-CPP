#include <iostream>

#include "Repository.h"



int main() {
	
	Repository<int> myint(6);
	myint.print();


	int x = 8;
	Repository<int*> myintptr(&x);


	x = 10;
	myintptr.print();
	

	char* name = new char[40]{ "Anton" }; 



	Repository<char*> myname(name);


	delete[] name;

	myname.print();

	return 0;
}