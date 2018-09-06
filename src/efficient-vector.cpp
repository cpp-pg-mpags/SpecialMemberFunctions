// Standard Library includes
#include <iostream>
#include <vector>

// Project includes
#include "MyClassA.hpp"

template <typename T>
void printVecSizeInfo( const std::vector<T>& vec )
{
	std::cout << "Vector has capacity for " << vec.capacity() << " elements, with " << vec.size() << " currently in use" << std::endl;
}

void howDoesAVectorGrow()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "HOW DOES A VECTOR GROW" << std::endl;
	std::cout << "======================\n" << std::endl;

	std::cout << "Create an empty vector" << std::endl;
	std::vector<int> vec;
	printVecSizeInfo(vec);

	for ( int i{0}; i < 10; ++i ) {
		std::cout << "Add an element" << std::endl;
		vec.push_back(i);
		printVecSizeInfo(vec);
	}
}

void whatOperationsHappenDuringDefaultGrowth()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "==========================================================" << std::endl;
	std::cout << "WHAT OPERATIONS HAPPEN DURING VECTOR GROWTH WITH PUSH_BACK" << std::endl;
	std::cout << "==========================================================\n" << std::endl;

	std::cout << "Create an empty vector" << std::endl;
	std::vector<MyClassA> vec;
	printVecSizeInfo(vec);

	for ( int i{0}; i < 10; ++i ) {
		std::cout << "Add an element" << std::endl;
		MyClassA a{i};
		vec.push_back(a);
		printVecSizeInfo(vec);
	}
}

void whatOperationsHappenDuringGrowthWithReserve()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "============================================================================" << std::endl;
	std::cout << "WHAT OPERATIONS HAPPEN DURING VECTOR GROWTH WITH PUSH_BACK AND PRIOR RESERVE" << std::endl;
	std::cout << "============================================================================\n" << std::endl;

	std::cout << "Create an empty vector" << std::endl;
	std::vector<MyClassA> vec;
	printVecSizeInfo(vec);

	std::cout << "Reserve space for 10 elements" << std::endl;
	vec.reserve(10);
	printVecSizeInfo(vec);

	for ( int i{0}; i < 10; ++i ) {
		std::cout << "Add an element" << std::endl;
		MyClassA a{i};
		vec.push_back(a);
		printVecSizeInfo(vec);
	}
}

void whatOperationsHappenDuringGrowthWithReserveAndEmplaceBack()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "===============================================================================" << std::endl;
	std::cout << "WHAT OPERATIONS HAPPEN DURING VECTOR GROWTH WITH EMPLACE_BACK AND PRIOR RESERVE" << std::endl;
	std::cout << "===============================================================================\n" << std::endl;

	std::cout << "Create an empty vector" << std::endl;
	std::vector<MyClassA> vec;
	printVecSizeInfo(vec);

	std::cout << "Reserve space for 10 elements" << std::endl;
	vec.reserve(10);
	printVecSizeInfo(vec);

	for ( int i{0}; i < 10; ++i ) {
		std::cout << "Add an element" << std::endl;
		vec.emplace_back(i);
		printVecSizeInfo(vec);
	}
}


int main()
{
	howDoesAVectorGrow();
	//whatOperationsHappenDuringDefaultGrowth();
	//whatOperationsHappenDuringGrowthWithReserve();
	//whatOperationsHappenDuringGrowthWithReserveAndEmplaceBack();

	return 0;
}

