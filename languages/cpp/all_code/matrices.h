#include <iostream>
#include <vector>

class Matrix
{
	std::vector<int> data_;
	int rows_, cols_;
public:

	Matrix(std::vector<int> &rhs, int rows, int cols)
	{
		rows_ = rows;
		cols_ = cols;
		data_.insert(data_.end(), rhs.begin(), rhs.end());

	}

	int rows() const { return rows_; };
	int cols()  const { return cols_; }


	Matrix(const Matrix &rhs)
	{
		this->data_ = rhs.data_;
		this->rows_ = rhs.rows_;
		this->cols_ = rhs.cols_;
	}

	Matrix & operator = (const Matrix &rhs)
	{
		if (&rhs != this)
		{
			this->data_ = rhs.data_;
			this->rows_ = rhs.rows_;
			this->cols_ = rhs.cols_;
		}
		return *this;
	}

	Matrix operator +(const Matrix &rhs)
	{
		std::vector<int> d(rhs.cols_ * rhs.rows_, 0);
		Matrix  res(d, rhs.rows_, rhs.cols_);

		for (int i = 0; i < rows_; i++)
		{
			for (int j = 0; j < cols_; j++)
			{
				res.data_[i*res.cols_ + j] = this->data_[i*res.cols_ + j] + rhs.data_[i*res.cols_ + j];
			}
		}
		return std::move(res);
	}



	Matrix operator -(const Matrix &rhs)
	{
		std::vector<int> d(rhs.cols_ * rhs.rows_, 0);
		Matrix  res(d, rhs.rows_, rhs.cols_);

		for (int i = 0; i < rows_; i++)
		{
			for (int j = 0; j < cols_; j++)
			{
				res.data_[i*res.cols_ + j] = this->data_[i*res.cols_ + j] - rhs.data_[i*res.cols_ + j];
			}
		}
		return std::move(res);
	}


	Matrix operator *(const Matrix &rhs)
	{

		return *this;
	}


	Matrix & add(const Matrix &rhs)
	{

		this->operator+(rhs);
		return *this;
	}


	Matrix & sub(const Matrix &rhs)
	{
		this->operator-(rhs);
		return *this;
	}

	Matrix & mul(const Matrix &rhs)
	{
		this->operator*(rhs);
		return *this;
	}

	friend std::ostream & operator << (std::ostream &con, Matrix m1)
	{
		con << "\n";
		int rows = m1.rows();
		int cols = m1.cols();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				auto num = m1.data_.at(i*cols + j);
				con << num << " ";
			}
			std::cout << "\n";
		}
		return con;
	}
};

