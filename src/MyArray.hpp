#ifndef MYARRAY_HPP
#define MYARRAY_HPP

// Standard Library includes
#include <algorithm>
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
		MyArray(const size_t size)
			: size_{size}
			, elems_{ std::make_unique<int[]>(size_) }
		{
			std::cout << "MyArray constructor" << std::endl;
		}

		/// destructor
		~MyArray()
		{
			std::cout << "MyArray destructor" << std::endl;
		}

		/// copy constructor
		MyArray(const MyArray& rhs)
			: size_{rhs.size_}
			, elems_{ std::make_unique<int[]>(size_) }
		{
			std::cout << "MyArray copy constructor" << std::endl;

			// set all elements to those of rhs
			std::copy( rhs.begin(), rhs.end(), this->begin() );
		}

		/// move constructor
		MyArray(MyArray&& rhs) noexcept
			: size_{ rhs.size_ }
			, elems_{ std::move(rhs.elems_) }
		{
			std::cout << "MyArray move constructor" << std::endl;

			// set the size of the rhs to be consistent with it no longer having assigned storage
			rhs.size_ = 0;
		}

		/// copy assignment operator
		MyArray& operator=(const MyArray& rhs)
		{
			std::cout << "MyArray copy assignment operator" << std::endl;

			MyArray tmp{ rhs };
			tmp.swap(*this);

			return *this;
		}

		/// move assignment operator
		MyArray& operator=(MyArray&& rhs) noexcept
		{
			std::cout << "MyArray move assignment operator" << std::endl;

			MyArray tmp{ std::move(rhs) };
			tmp.swap(*this);

			return *this;
		}

		/*
		Note how the two assignment operators are implemented in terms
		of their corresponding constructors and a swap function.

		If you've seen copy assignment operators before, you may have
		seen them contain checks for self-assignment.  What has been
		done here, however, is to implement the operations in such a
		way that they are safe (albeit slower than checking and doing
		nothing) in such a scenario, i.e. the object ends up
		maintaining the same state.  This allows us to avoid the check
		entirely, which makes the operations faster in the far more
		probable situation where the objects involved are different.

		Note also how the code above for the copy and move assignment
		operators are essentially the same.
		We could even replace them with a single function, which is
		easier to maintain and can even be more efficient in certain
		situations - see the commented-out function below.
		The only caveat to that is the noexcept specification, which
		cannot be applied to this joint function since the copy
		constructor can throw (in this case in make_unique).
		The noexcept specification for move operations is important if,
		for example, you are going to place your type in standard
		library containers since they can only use move operations when
		performing internal reorganisations if those operations are
		declared noexcept.
		*/

		/*
		/// copy/move assignment operator
		MyArray& operator=(MyArray rhs)
		{
			std::cout << "MyArray copy/move assignment operator" << std::endl;

			rhs.swap(*this);

			return *this;
		}
		*/

		/// swap contents of two arrays
		void swap(MyArray& rhs) noexcept
		{
			std::swap(elems_, rhs.elems_);
			std::swap(size_, rhs.size_);
		}

		/// get the size of the array
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
