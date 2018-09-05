#ifndef MYARRAY_HPP
#define MYARRAY_HPP

// Standard Library includes
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
