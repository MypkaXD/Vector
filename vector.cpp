#include <iostream>

class Vector {
	double* m_data{ nullptr };
	int m_n{ 0 };
public:
	Vector() {};
	Vector(int n) {
		m_n = n;
		m_data = new double[m_n];
		for (int count = 0; count < m_n; count++)
			m_data[count] = 0.;
	}
	~Vector() {
		delete[] m_data;
		m_data = nullptr;
		m_n = 0;
	}
	void resize(int newSize) {
		double* newArr = new double[newSize];
		int minLenght = std::min(m_n, newSize);
		for (int count = 0; count < minLenght; count++) {
			newArr[count] = m_data[count];
		}

		delete[] m_data;
		m_data = newArr;

		for (int count = 0; count < newSize; count++) {
			m_data[count] = 0.;
		}

		m_n = newSize;
	}
	Vector& operator=(const Vector& v) {
		resize(v.m_n);
		for (int count = 0; count < m_n; count++)
			m_data[count] = v.m_data[count];
		return *this;
	}
	Vector operator+(const Vector& v) {
		if (m_n != v.m_n) {
			std::cout << "ERROR" << std::endl;
			exit(0);
		}
		Vector other(v.m_n);
		for (int count = 0; count < m_n; count++) {
			other.m_data[count] = m_data[count] + v.m_data[count];
		}
		return other;
	}
	Vector operator-(const Vector& v) {
		if (m_n != v.m_n) {
			std::cout << "ERROR" << std::endl;
			exit(0);
		}
		Vector other(v.m_n);
		for (int count = 0; count < m_n; count++) {
			other.m_data[count] = m_data[count] - v.m_data[count];
		}
		return other;
	}
	Vector& operator+=(const Vector& v) {
		if (m_n != v.m_n) {
			std::cout << "ERROR" << std::endl;
			exit(0);
		}
		for (int count = 0; count < m_n; count++) {
			m_data[count] += v.m_data[count];
		}
		return *this;
	}
	Vector& operator-=(const Vector& v) {
		if (m_n != v.m_n) {
			std::cout << "ERROR" << std::endl;
			exit(0);
		}
		for (int count = 0; count < m_n; count++) {
			m_data[count] -= v.m_data[count];
		}
		return *this;
	}
	Vector operator*(double x) {
		Vector other(m_n);
		for (int count = 0; count < m_n; count++)
			other.m_data[count] = m_data[count] * x;
		return other;
	}
	Vector& operator*=(double x) {
		for (int count = 0; count < m_n; count++)
			m_data[count] *= x;
		return *this;
	}
	double dot(const Vector& v)
	{
		double other = .0;
		for (int count = 0; count < m_n; count++)
		{
			other += v.m_data[count] * m_data[count];
		}
		return other;
	}
	void print() {
		for (int count = 0; count < m_n; count++) {
			std::cout << m_data[count] << " ";
		}
	}
	void setValueVector() {
		for (int count = 0; count < m_n; count++) {
			int x;
			std::cout << "Введите " << count << " элемент: " << std::endl;
			std::cin >> x;
			m_data[count] = x;
		}
	}
};

int main()
{

	setlocale(LC_ALL, "Russian");
	Vector a(5);
	a.setValueVector();
	a.print();
	a *= 5;
	std::cout << std::endl;
	a.print();
	std::cout << std::endl;
	a.resize(10);
	a.setValueVector();
	a.print();

	return 0;
}
