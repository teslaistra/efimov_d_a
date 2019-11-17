#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <iostream>
#include <sstream>

#include <locale>
#include <string>
#include <Windows.h>
class DynArray {
public:
	DynArray() = default;

	DynArray(const DynArray& arr);
	DynArray(const std::ptrdiff_t size);

	//! \brief Оператор присваивания.
	//!
	//! Осуществляет глубокое копирование, т.е. все значения массива rhs копируются.
	//! При достаточном размере внутреннего буфера новых выделений памяти не происходит,
	//! элементы копируются в доступную экземпляру память.
	DynArray& operator=(const DynArray& rhs);

	//! \brief Деструктор экземпляра, освобождает память.
	~DynArray() { delete[] data_; }

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
	float& operator[](const std::ptrdiff_t i);

	//! \brief Доступ к элементу массива для чтения по индексу.
	//!
	//! \param[in] i - индекс элемента (индексация с 0) 
	//! \pre индекс запрашиваемого элемента i находится в допустимом диапазоне [0, size() - 1],
	//!      т.е. 0 <= i && i < size()
	//! \throws std::out_of_range - при попытке обращения вне массива
	//! \retval const float& - ссылка на элемент по индексу
	const float& operator[](const std::ptrdiff_t i) const;

	//! \brief Изменение размера массива.
	//!
	//! \pre новый размер size неотрицательный
	//! \post при увеличении числа элементов новые элементы инициализируются 0.0f
	//! \throws std::logic_error - при попытке изменения размера на отрицательный
	//! \param[in] size - новый размер
	void resize(const std::ptrdiff_t size);

	std::ptrdiff_t capacity_{ 0 };  //!< размер внутреннего буфера
	std::ptrdiff_t size_{ 0 };      //!< размер массива (кол-во элементов)
	float* data_{ nullptr };        //!< данные
};
