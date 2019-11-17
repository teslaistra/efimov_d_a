#include <stdio.h>
template<typename T>

class DynArrayT {
public:
	//! \brief ������������� �����������.
	//!
	//! ������� ������ ������ ��� ��������� ������.
	DynArrayT() = default;

	//! \brief ���������� �����������.
	DynArrayT(const DynArrayT& arr);

	//! \brief ����������� ��� �������� ������� ��������� ������� size.
	//! \pre ������ size ���������������
	//! \post �������� ��������������� 0.0f
	//! \throws std::logic_error - ��� ������� �������� ������� � ������������� ��������
	DynArrayT(const std::ptrdiff_t size);

	//! \brief �������� ������������.
	//!
	//! ������������ �������� �����������, �.�. ��� �������� ������� rhs ����������.
	//! ��� ����������� ������� ����������� ������ ����� ��������� ������ �� ����������,
	//! �������� ���������� � ��������� ���������� ������.
	DynArrayT& operator=(const DynArrayT& rhs);

	//! \brief ���������� ����������, ����������� ������.
	~DynArrayT() { delete[] data_; }

	//! \brief ��������� �������� ������� �������.
	//! \retval std::ptrdiff_t - ���������� ��������� � �������
	std::ptrdiff_t size() const { return size_; }

	//! \brief ������ � �������� ������� �� �������.
	//!
	//! \param[in] i - ������ �������� (���������� � 0) 
	//! \pre ������ �������������� �������� i ��������� � ���������� ��������� [0, size() - 1],
	//!      �.�. 0 <= i && i < size()
	//! \throws std::out_of_range - ��� ������� ��������� ��� �������
	//! \retval float& - ������ �� ������� �� �������
	T& operator[](const std::ptrdiff_t i);

	//! \brief ������ � �������� ������� ��� ������ �� �������.
	//!
	//! \param[in] i - ������ �������� (���������� � 0) 
	//! \pre ������ �������������� �������� i ��������� � ���������� ��������� [0, size() - 1],
	//!      �.�. 0 <= i && i < size()
	//! \throws std::out_of_range - ��� ������� ��������� ��� �������
	//! \retval const float& - ������ �� ������� �� �������
	const T& operator[](const std::ptrdiff_t i) const;

	//! \brief ��������� ������� �������.
	//!
	//! \pre ����� ������ size ���������������
	//! \post ��� ���������� ����� ��������� ����� �������� ���������������� 0.0f
	//! \throws std::logic_error - ��� ������� ��������� ������� �� �������������
	//! \param[in] size - ����� ������
	void resize(const std::ptrdiff_t size);

private:
	std::ptrdiff_t capacity_{ 0 };  //!< ������ ����������� ������
	std::ptrdiff_t size_{ 0 };      //!< ������ ������� (���-�� ���������)
	float* data_{ nullptr };        //!< ������
};


	template<typename T>
	DynArrayT<T>::dynArrayT()<t> = default;
	/*
	template<typename T>
	T& dynArrayT<T>::operator[](const ptrdiff_t i) {
		if (i < 0 || size_ < i) {
			throw;
		}
		return data_[i];
	}
	*/
	/*
	template<typename T>
	dynArrayT<T>::~dynArrayT() {
		delete[] data_;
	}
	*/
	/*
	template<typename T>
	dynArrayT<T> dynArrayT<T>::operator=(const dynArrayT rhs) {
		if (this != &rhs) {
			delete[] data_;
			capacity_ = rhs.capacity_;
			size_ = rhs.size_;
			data_ = new T[capacity_];

			for (size_t i = 0; i < int(capacity_); i++)
			{
				data_[i] = rhs.data_[i];
			}

		}
		return *this;
	}
	*/
	/*
	template<typename T>
	void dynArrayT<T>::resize(const ptrdiff_t size) {
		T* data = new T[size];

		for (size_t i = 0; i < int(capacity_); i++)
		{
			data[i] = data_[i];
		}

		delete[] data_;
		data_ = data;
	}
	
	template<typename T>

	ptrdiff_t dynArrayT<T>::size()const {
		return size_;
	}
*/
 dynArrayT<T>::dynArrayT<T>(const ptrdiff_t size) :
	capacity_(size),
	size_(size) {
	if (size < 0) {
		throw;
	}
	data_ = new T[capacity_];
	for (int i = 0; i < capacity_; i++) {
		data_[i] = NULL;
	}
}	
};
