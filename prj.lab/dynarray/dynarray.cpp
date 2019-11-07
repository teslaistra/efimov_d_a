#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "DynArray.h"
#include <iostream>

	dynArray::dynArray() = default;

	dynArray::dynArray(const ptrdiff_t size) :
	capacity_(size),
	size_(size) {
	if (size < 0) {
		throw;
	}
	data_ = new float[capacity_];
	for (int i = 0; i < capacity_; i++) {
		data_[i] = NULL;
	}
}

	float& dynArray::operator[](const ptrdiff_t i) {
			if (i < 0 || size_ < i) {
				throw;
			}
			return data_[i];
		}

		dynArray::~dynArray() {
			delete[] data_;
		}

		dynArray dynArray::operator=(const dynArray rhs) {
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

		void dynArray::resize(const ptrdiff_t size) {
			float* data = new float[size];

			for (size_t i = 0; i < int(capacity_); i++)
			{
				data[i] = data_[i];
			}

			delete[] data_;
			data_ = data; 
		}

		ptrdiff_t dynArray::size()const {
			return size_;
		}

