#ifndef MYARRAY_HPP
#define MYARRAY_HPP

// Standard Library includes
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

/**
 * \class MyArray
 * \brief An array of integers - currently of a fixed, hardcoded size (10)
 */
class MyArray {
	public:
		/// constructor
		MyArray()
		{
			std::cout << "MyArray default contructor" << std::endl;

			// set all elements to zero
			for (size_t i{0}; i < size_; ++i) {
				elems_[i] = 0;
			}
		}

		/// destructor
		~MyArray()
		{
			std::cout << "MyArray destructor" << std::endl;
		}

		/// copy constructor
		MyArray(const MyArray& rhs)
		{
			std::cout << "MyArray copy contructor" << std::endl;

			// set all elements to those of rhs
			for (size_t i{0}; i < size_; ++i) {
				elems_[i] = rhs.elems_[i];
			}
		}

		/// move constructor
		MyArray(MyArray&& rhs)
		{
			std::cout << "MyArray move contructor" << std::endl;

			// set all elements to those of rhs
			for (size_t i{0}; i < size_; ++i) {
				elems_[i] = std::move(rhs.elems_[i]);
			}
		}

		/// copy assignment operator
		MyArray& operator=(const MyArray& rhs)
		{
			std::cout << "MyArray copy assignment operator" << std::endl;

			// check for self-assignment
			if ( &rhs != this ) {
				// set all elements to those of rhs
				for (size_t i{0}; i < size_; ++i) {
					elems_[i] = rhs.elems_[i];
				}
			}

			return *this;
		}

		/// move assignment operator
		MyArray& operator=(MyArray&& rhs)
		{
			std::cout << "MyArray move assignment operator" << std::endl;

			// check for self-assignment
			if ( &rhs != this ) {
				// set all elements to those of rhs
				for (size_t i{0}; i < size_; ++i) {
					elems_[i] = std::move(rhs.elems_[i]);
				}
			}

			return *this;
		}


		/// get the size
		size_t size() const { return size_; }

		/// access elements (not bounds checked)
		int& operator[](size_t elem) { return elems_[elem]; }

		/// const access to elements (not bounds checked)
		const int& operator[](size_t elem) const { return elems_[elem]; }

		/// access elements (bounds checked)
		int& at(size_t elem)
		{
			if ( elem >= size_ ) {
				std::ostringstream tmp;
				tmp << "element " << elem << " is out of bounds: 0 - " << size_-1;
				throw std::out_of_range{tmp.str()};
			}
			return elems_[elem];
		}

		/// const access to elements (bounds checked)
		const int& at(size_t elem) const
		{
			if ( elem >= size_ ) {
				std::ostringstream tmp;
				tmp << "element " << elem << " is out of bounds: 0 - " << size_-1;
				throw std::out_of_range{tmp.str()};
			}
			return elems_[elem];
		}

		/// iterator typedef
		typedef int* Iterator;

		/// const iterator typedef
		typedef const int* ConstIterator;

		/// obtain iterator to first element
		Iterator begin() { return elems_; }

		/// obtain const iterator to first element
		ConstIterator begin() const { return elems_; }

		/// obtain const iterator to first element
		ConstIterator cbegin() const { return elems_; }

		/// obtain iterator to the one-past-the-end element
		Iterator end() { return elems_+size_; }

		/// obtain const iterator to the one-past-the-end element
		ConstIterator end() const { return elems_+size_; }

		/// obtain const iterator to the one-past-the-end element
		ConstIterator cend() const { return elems_+size_; }


	private:
		static const size_t size_ = 10;
		int elems_[size_];
};

#endif
