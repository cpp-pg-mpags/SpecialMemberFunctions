// Standard Library includes
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

// Project includes
#include "MyArray.hpp"

MyArray createArray()
{
	MyArray anArray;
	return anArray;
}

int main()
{
	MyArray myFirstArray;
	std::cout << "Array has " << myFirstArray.size() << " elements:" << std::endl;
	for ( const auto& elem : myFirstArray ) {
		std::cout << elem << std::endl;
	}

	std::cout << "Setting elements:" << std::endl;
	int counter{0};
	for ( auto& elem : myFirstArray ) {
		elem = counter++;
		std::cout << elem << std::endl;
	}

	std::cout << "Attempt to access invalid elements" << std::endl;
	try {
		std::cout << myFirstArray[10] << std::endl;
		std::cout << myFirstArray.at(10) << std::endl;
	} catch ( std::out_of_range& e ) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Copying array:" << std::endl;
	MyArray mySecondArray{ myFirstArray };
	for ( const auto& elem : mySecondArray ) {
		std::cout << elem << std::endl;
	}

	std::cout << "Modify second array:" << std::endl;
	counter = 9;
	for ( auto& elem : mySecondArray ) {
		elem = counter--;
		std::cout << elem << std::endl;
	}

	std::cout << "Assign to first array:" << std::endl;
	myFirstArray = mySecondArray;
	for ( const auto& elem : myFirstArray ) {
		std::cout << elem << std::endl;
	}

	std::cout << "Make another array from a function return:" << std::endl;
	MyArray myThirdArray { createArray() };
	for ( const auto& elem : myThirdArray ) {
		std::cout << elem << std::endl;
	}

	std::cout << "Assign to the first array from a function return:" << std::endl;
	myFirstArray = createArray();
	for ( const auto& elem : myFirstArray ) {
		std::cout << elem << std::endl;
	}

	return 0;
}

