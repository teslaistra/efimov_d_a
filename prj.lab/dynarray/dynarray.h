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

	//! \brief �������� ������������.
	//!
	//! ������������ �������� �����������, �.�. ��� �������� ������� rhs ����������.
	//! ��� ����������� ������� ����������� ������ ����� ��������� ������ �� ����������,
	//! �������� ���������� � ��������� ���������� ������.
	DynArray& operator=(const DynArray& rhs);

	//! \brief ���������� ����������, ����������� ������.
	~DynArray() { delete[] data_; }

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
	float& operator[](const std::ptrdiff_t i);

	//! \brief ������ � �������� ������� ��� ������ �� �������.
	//!
	//! \param[in] i - ������ �������� (���������� � 0) 
	//! \pre ������ �������������� �������� i ��������� � ���������� ��������� [0, size() - 1],
	//!      �.�. 0 <= i && i < size()
	//! \throws std::out_of_range - ��� ������� ��������� ��� �������
	//! \retval const float& - ������ �� ������� �� �������
	const float& operator[](const std::ptrdiff_t i) const;

	//! \brief ��������� ������� �������.
	//!
	//! \pre ����� ������ size ���������������
	//! \post ��� ���������� ����� ��������� ����� �������� ���������������� 0.0f
	//! \throws std::logic_error - ��� ������� ��������� ������� �� �������������
	//! \param[in] size - ����� ������
	void resize(const std::ptrdiff_t size);

	std::ptrdiff_t capacity_{ 0 };  //!< ������ ����������� ������
	std::ptrdiff_t size_{ 0 };      //!< ������ ������� (���-�� ���������)
	float* data_{ nullptr };        //!< ������
};
