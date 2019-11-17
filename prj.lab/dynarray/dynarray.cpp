#include "dynarray.h"
#include <iostream>
#include <iostream>
#include <sstream>
using namespace std;

	DynArray::DynArray(const DynArray& arr):capacity_(arr.capacity_),size_(arr.size_)
	{
		data_ = new float[arr.capacity_];
		for (size_t i = 0; i < arr.capacity_; i++)
		{
			data_[i] = arr.data_[i];
		}
	}


	DynArray::DynArray(const std::ptrdiff_t size)
		: capacity_(size)
		, size_(size) {
		if (capacity_ < 0) {
			throw std::logic_error("DynArray ctor - negative size");
		}
		data_ = new float[capacity_] {0.0f};
	}



		DynArray& DynArray::operator=(const DynArray& rhs) {
			if (this != &rhs) {
				delete[] data_;
				capacity_ = rhs.capacity_;
				size_ = rhs.size_;
				data_ = new float[capacity_];

				for (size_t i = 0; i < int(capacity_); i++)
				{
					data_[i] = rhs.data_[i];
				}

			}
			return *this;
		}
		
		
		float& DynArray::operator[](const ptrdiff_t i) {
			if (i < 0 || size_ <= i) {
				throw out_of_range("error");
			}
			return data_[i];
		}



		const float& DynArray::operator[](const std::ptrdiff_t i) const
		{
			if (i < 0 || size_ <= i) {
				throw out_of_range("error");
			}
			return data_[i];
		}
	

		
		void DynArray::resize(const ptrdiff_t size) {
			if (size < 0) throw logic_error("less ");
			float* data = new float[size];
			if (size > capacity_) {
				capacity_ = size; 
				float* data = new float[capacity_];
				for (size_t i = 0; i < size; i++)
				{
					data[i] = data_[i];
				}
				delete[] data_;
				data_ = data; 	
			}	

			if (size > size_) {
				for (size_t i = 0; i <= size; i++)
				{
					data[i] = 0.0;
				}
			}
			size_ = size;

		}
		
	
		//void DynArray::resize(const std::ptrdiff_t size) {
		//	if (size < 0) {
		//		throw std::logic_error("DynArray::resize - negative size");
		//	}
		//	if (capacity_ < size) {
		//		capacity_ = size;
		//		float* new_data = new float[capacity_];
		//		std::copy(data_, data_ + size_, new_data);
		//		delete[] data_;
		//		data_ = new_data;
		//	}
		//	if (size_ < size) {
		//		std::fill(data_ + size_, data_ + size, 0.0f);
		//	}
		//	size_ = size;
		//}
		//
		//