#ifndef MYCLASSA_HPP
#define MYCLASSA_HPP

// Standard Library includes
#include <iostream>

/**
 * \class MyClassA
 * \brief A dummy class
 */
class MyClassA {
	public:
		/// default constructor
		MyClassA()
		{
			std::cout << "MyClassA default constructor" << std::endl;
		}

		/// constructor
		explicit MyClassA( const int a )
			: a_{a}
		{
			std::cout << "MyClassA constructor" << std::endl;
		}

		/// destructor
		~MyClassA()
		{
			std::cout << "MyClassA destructor" << std::endl;
		}

		/// copy constructor
		MyClassA(const MyClassA& rhs)
			: a_{rhs.a_}
		{
			std::cout << "MyClassA copy constructor" << std::endl;
		}

		/// move constructor
		MyClassA(MyClassA&& rhs) noexcept
			: a_{rhs.a_}
		{
			std::cout << "MyClassA move constructor" << std::endl;
		}

		/// copy assignment operator
		MyClassA& operator=(const MyClassA& rhs)
		{
			std::cout << "MyClassA copy assignment operator" << std::endl;
			a_ = rhs.a_;
			return *this;
		}

		/// move assignment operator
		MyClassA& operator=(MyClassA&& rhs)
		{
			std::cout << "MyClassA move assignment operator" << std::endl;
			a_ = rhs.a_;
			return *this;
		}

	private:
		int a_ = 0;
};

#endif
