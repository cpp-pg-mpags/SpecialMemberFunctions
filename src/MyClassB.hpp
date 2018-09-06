#ifndef MYCLASSB_HPP
#define MYCLASSB_HPP

// Standard Library includes
#include <iostream>

/**
 * \class MyClassB
 * \brief A dummy class
 */
class MyClassB {
	public:
		/// default constructor
		MyClassB()
		{
			std::cout << "MyClassB default constructor" << std::endl;
		}

		/// constructor
		MyClassB( const int a, const int b )
			: a_{a}
		        , b_{b}
		{
			std::cout << "MyClassB constructor" << std::endl;
		}

		/// destructor
		~MyClassB()
		{
			std::cout << "MyClassB destructor" << std::endl;
		}

		/// copy constructor
		MyClassB(const MyClassB& rhs)
			: a_{rhs.a_}
			, b_{rhs.b_}
		{
			std::cout << "MyClassB copy constructor" << std::endl;
		}

		/// move constructor
		MyClassB(MyClassB&& rhs) noexcept
			: a_{rhs.a_}
			, b_{rhs.b_}
		{
			std::cout << "MyClassB move constructor" << std::endl;
		}

		/// copy assignment operator
		MyClassB& operator=(const MyClassB& rhs)
		{
			std::cout << "MyClassB copy assignment operator" << std::endl;
			a_ = rhs.a_;
			b_ = rhs.b_;
			return *this;
		}

		/// move assignment operator
		MyClassB& operator=(MyClassB&& rhs)
		{
			std::cout << "MyClassB move assignment operator" << std::endl;
			a_ = rhs.a_;
			b_ = rhs.b_;
			return *this;
		}

	private:
		int a_ = 0;
		int b_ = 0;
};

#endif
