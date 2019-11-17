#include <stdio.h>
template<typename T>

class DynArrayT {
public:
	//! \brief Умолчательный конструктор.
	//!
	//! Создает пустой массив без выделения памяти.
	DynArrayT() = default;

	//! \brief Копирующий конструктор.
	DynArrayT(const DynArrayT& arr);

	//! \brief Конструктор для создания массива заданного размера size.
	//! \pre размер size неотрицательный
	//! \post элементы иницализируются 0.0f
	//! \throws std::logic_error - при попытке создания массива с отрицательным размером
	DynArrayT(const std::ptrdiff_t size);

	//! \brief Оператор присваивания.
	//!
	//! Осуществляет глубокое копирование, т.е. все значения массива rhs копируются.
	//! При достаточном размере внутреннего буфера новых выделений памяти не происходит,
	//! элементы копируются в доступную экземпляру память.
	DynArrayT& operator=(const DynArrayT& rhs);

	//! \brief Деструктор экземпляра, освобождает память.
	~DynArrayT() { delete[] data_; }

	//! \brief Получение текущего размера массива.
	//! \retval std::ptrdiff_t - количество элементов в массиве
	std::ptrdiff_t size() const { return size_; }

	//! \brief Доступ к элементу массива по индексу.
	//!
	//! \param[in] i - индекс элемента (индексация с 0) 
	//! \pre индекс запрашиваемого элемента i находится в допустимом диапазоне [0, size() - 1],
	//!      т.е. 0 <= i && i < size()
	//! \throws std::out_of_range - при попытке обращения вне массива
	//! \retval float& - ссылка на элемент по индексу
	T& operator[](const std::ptrdiff_t i);

	//! \brief Доступ к элементу массива для чтения по индексу.
	//!
	//! \param[in] i - индекс элемента (индексация с 0) 
	//! \pre индекс запрашиваемого элемента i находится в допустимом диапазоне [0, size() - 1],
	//!      т.е. 0 <= i && i < size()
	//! \throws std::out_of_range - при попытке обращения вне массива
	//! \retval const float& - ссылка на элемент по индексу
	const T& operator[](const std::ptrdiff_t i) const;

	//! \brief Изменение размера массива.
	//!
	//! \pre новый размер size неотрицательный
	//! \post при увеличении числа элементов новые элементы инициализируются 0.0f
	//! \throws std::logic_error - при попытке изменения размера на отрицательный
	//! \param[in] size - новый размер
	void resize(const std::ptrdiff_t size);

private:
	std::ptrdiff_t capacity_{ 0 };  //!< размер внутреннего буфера
	std::ptrdiff_t size_{ 0 };      //!< размер массива (кол-во элементов)
	float* data_{ nullptr };        //!< данные
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
