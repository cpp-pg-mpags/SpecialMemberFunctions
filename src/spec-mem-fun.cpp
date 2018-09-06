// Standard Library includes
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

// Project includes
#include "MyArray.hpp"

MyArray createArrayOfOnes()
{
	MyArray anArray{5};
	for ( auto& elem : anArray ) {
		elem = 1;
	}
	return anArray;
}

int main()
{
	MyArray myFirstArray{10};
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

	std::cout << "Make a third array from a function return:" << std::endl;
	MyArray myThirdArray { createArrayOfOnes() };
	for ( const auto& elem : myThirdArray ) {
		std::cout << elem << std::endl;
	}

	std::cout << "Assign to the first array from a function return:" << std::endl;
	myFirstArray = createArrayOfOnes();
	for ( const auto& elem : myFirstArray ) {
		std::cout << elem << std::endl;
	}

	std::cout << "Make a fourth array by explicit move of the second:" << std::endl;
	MyArray myFourthArray { std::move(mySecondArray) };
	for ( const auto& elem : myFourthArray ) {
		std::cout << elem << std::endl;
	}

	std::cout << "Assign to the fourth array by explicit move of the third:" << std::endl;
	myFourthArray = std::move(myThirdArray);
	for ( const auto& elem : myFourthArray ) {
		std::cout << elem << std::endl;
	}

	return 0;
}

