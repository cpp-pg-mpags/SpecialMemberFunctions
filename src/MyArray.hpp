#ifndef MYARRAY_HPP
#define MYARRAY_HPP

// Standard Library includes
#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <string>

/**
 * \class MyArray
 * \brief An array of integers - currently of a fixed but user-specified size
 */
class MyArray {
	public:
		/// constructor
		MyArray(const size_t size) :
			size_{size},
			elems_{ std::make_unique<int[]>(size) }
		{
			std::cout << "MyArray contructor" << std::endl;
		}

		/// destructor
		~MyArray()
		{
			std::cout << "MyArray destructor" << std::endl;
		}

		/// copy constructor
		MyArray(const MyArray& rhs) :
			size_{rhs.size_},
			elems_{ std::make_unique<int[]>(size_) }
		{
			std::cout << "MyArray copy contructor" << std::endl;

			// set all elements to those of rhs
			for (size_t i{0}; i < size_; ++i) {
				elems_[i] = rhs.elems_[i];
			}
		}

		/// move constructor
		MyArray(MyArray&& rhs) :
			size_{ rhs.size_ },
			elems_{ std::move(rhs.elems_) }
		{
			std::cout << "MyArray move contructor" << std::endl;
		}

		/// copy assignment operator
		MyArray& operator=(const MyArray& rhs)
		{
			std::cout << "MyArray copy assignment operator" << std::endl;

			// check for self-assignment
			if ( &rhs != this ) {
				if ( size_ < rhs.size_ ) {
					elems_ = std::make_unique<int[]>(rhs.size_);
				}
				size_ = rhs.size_;

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
				size_ = rhs.size_;
				elems_ = std::move(rhs.elems_);
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
		Iterator begin() { return elems_.get(); }

		/// obtain const iterator to first element
		ConstIterator begin() const { return elems_.get(); }

		/// obtain const iterator to first element
		ConstIterator cbegin() const { return elems_.get(); }

		/// obtain iterator to the one-past-the-end element
		Iterator end() { return elems_.get()+size_; }

		/// obtain const iterator to the one-past-the-end element
		ConstIterator end() const { return elems_.get()+size_; }

		/// obtain const iterator to the one-past-the-end element
		ConstIterator cend() const { return elems_.get()+size_; }


	private:
		size_t size_;
		std::unique_ptr<int[]> elems_;
};

#endif
