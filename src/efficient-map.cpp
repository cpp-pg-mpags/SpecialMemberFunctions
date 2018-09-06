// Standard Library includes
#include <iostream>
#include <map>

// Project includes
#include "MyClassB.hpp"

void whatOperationsHappenDuringSubscriptInsertion()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "WHAT OPERATIONS HAPPEN DURING MAP GROWTH WITH SUBSCRIPT OPERATOR" << std::endl;
	std::cout << "================================================================\n" << std::endl;

	std::cout << "Create an empty map" << std::endl;
	std::map<int,MyClassB> mymap;

	int i{0};

	std::cout << "Add an element from an already constructed object" << std::endl;
	MyClassB a{i,i};
	mymap[i] = a;

	++i;

	std::cout << "Add an element from a temporary object" << std::endl;
	mymap[i] = MyClassB{i,i};

	++i;

	std::cout << "Add an element by explicitly moving an aleady constructed object" << std::endl;
	MyClassB b{i,i};
	mymap[i] = std::move(b);

	std::cout << "Finished" << std::endl;
}

void whatOperationsHappenDuringInsert()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << "WHAT OPERATIONS HAPPEN DURING MAP GROWTH WITH INSERT" << std::endl;
	std::cout << "====================================================\n" << std::endl;

	std::cout << "Create an empty map" << std::endl;
	std::map<int,MyClassB> mymap;

	int i{0};

	std::cout << "Add an element from an already constructed object" << std::endl;
	MyClassB a{i,i};
	mymap.insert( std::make_pair(i,a) );

	++i;

	std::cout << "Add an element from a temporary object" << std::endl;
	mymap.insert( std::make_pair(i,MyClassB{i,i}) );

	++i;

	std::cout << "Add an element by explicitly moving an aleady constructed object" << std::endl;
	MyClassB b{i,i};
	mymap.insert( std::make_pair(i,std::move(b)) );

	std::cout << "Finished" << std::endl;
}

void whatOperationsHappenDuringEmplace()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "WHAT OPERATIONS HAPPEN DURING MAP GROWTH WITH EMPLACE" << std::endl;
	std::cout << "=====================================================\n" << std::endl;

	std::cout << "Create an empty map" << std::endl;
	std::map<int,MyClassB> mymap;

	int i{0};

	std::cout << "Add an element from an already constructed object" << std::endl;
	MyClassB a{i,i};
	mymap.emplace( i, a );

	++i;

	std::cout << "Add an element from a temporary object" << std::endl;
	mymap.emplace( i, MyClassB{i,i} );

	++i;

	std::cout << "Add an element by explicitly moving an aleady constructed object" << std::endl;
	MyClassB b{i,i};
	mymap.emplace( i, std::move(b) );

	++i;

	std::cout << "Add an element by using piecewise construction" << std::endl;
	mymap.emplace( std::piecewise_construct, std::forward_as_tuple(i), std::forward_as_tuple(i,i) );

	std::cout << "Finished" << std::endl;
}


int main()
{
	whatOperationsHappenDuringSubscriptInsertion();
	whatOperationsHappenDuringInsert();
	whatOperationsHappenDuringEmplace();

	return 0;
}

