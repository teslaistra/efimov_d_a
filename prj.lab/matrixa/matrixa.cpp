// matrixa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "matrixa.h"

MatrixA::MatrixA(const MatrixA& matrix)
{
	n_row_ = matrix.n_row_;
	n_col_ = matrix.n_col_;

	data_ = std::make_unique<float[]>(n_row_ * n_col_);
	for (size_t i = 0; i < n_col_*n_row_; i++)
	{
		data_[i] = matrix.data_[i];
	}
}

MatrixA::MatrixA(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count){

	if ((row_count < 0) || (col_count < 0)) {
		throw std::invalid_argument("column or row number is less than zero");
	}

	n_col_ = col_count;
	n_row_ = row_count;

	data_ = std::make_unique<float[]>(n_row_ * n_col_);
	for (size_t i = 0; i < n_row_*n_col_; i++)
	{
		data_[i] = NULL;
	}
}

MatrixA& MatrixA::operator=(const MatrixA& matrix)
{
	//[] data_; - нужно ли вообще? 
	n_row_ = matrix.n_row_;
	n_col_ = matrix.n_col_;
	data_ = std::make_unique<float[]>(n_col_ * n_row_);
	for (size_t i = 0; i < n_col_*n_row_; i++)
	{
		data_[i] = matrix.data_[i];
	}
	return *this;

}

float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i)
{
	if ((row_i >= n_row_) || (col_i >= n_col_))throw std::invalid_argument("you are out of range");
	return data_[col_i + (col_i * n_row_)];

}

const float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const
{
	if ((row_i >= n_row_) || (col_i >= n_col_))throw std::invalid_argument("you are out of range");
	return data_[col_i + (col_i * n_row_)];

}
