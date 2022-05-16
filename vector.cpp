#include <iostream>

class Vector {
	int m_n{ 0 };														//длина массива
	double* m_data{ nullptr }; 
public:
	Vector(int n) :														//конструктор с параметром длины массива m_data
		m_n(n)
	{
		m_data = new double[m_n];
		for (int count = 0; count < m_n; count++) {
			m_data[count] = 0.0;
		}
	}
	~Vector() {
		delete[] m_data;
		m_data = nullptr;
		m_n = 0;
	}

	double& operator[](int count) {
		return (m_data[count]);
	}

	double operator[](int count) const {
		return (m_data[count]);
	}

	void resize(int newSize) {
		double* newM_Data = new double[newSize];
		int minLenght = std::min(newSize, m_n);
		for (int count = 0; count < minLenght; count++) {
			newM_Data[count] = m_data[count];
		}
		
		delete[] m_data;
		m_data = newM_Data;

		for (int count = 0; count < newSize; count++) {
			newM_Data[count] = 0.0;
		}

		m_n = newSize;
	}

	Vector& operator=(const Vector& other) {
		resize(other.m_n);
		for (int count = 0; count < other.m_n; count++) {
			m_data[count] = other.m_data[count];
		}
		return *this;
	}

	Vector operator + (const Vector& other) const{
		if (other.m_n != m_n) {
			throw "ERROR";
		}
		Vector newVector(m_n);
		for (int count = 0; count < m_n; count++) {
			newVector[count] = m_data[count] + other[count];
		}
		return newVector;
	}

	Vector operator-(const Vector& other) const{
		if (other.m_n != m_n) {
			throw "ERROR";
		}
		Vector newVector(m_n);
		for (int count = 0; count < m_n; count++) {
			newVector[count] = m_data[count] - other[count];
		}
		return newVector;
	}

	Vector& operator+=(const Vector& other) {
		if (other.m_n != m_n) {
			throw "ERROR";
		}
		for (int count = 0; count < m_n; count++) {
			m_data[count] += other.m_data[count];
		}
		return *this;
	}

	Vector& operator-=(const Vector& other) {
		if (other.m_n != m_n) {
			throw "ERROR";
		}
		for (int count = 0; count < m_n; count++) {
			m_data[count] -= other.m_data[count];
		}
		return *this;
	}

	Vector& operator*=(double value) {
		for (int count = 0; count < m_n; count++) {
			m_data[count] *= value;
		}
		return *this;
	}

	Vector operator*(double value) const{
		Vector other(m_n);
		for (int count = 0; count < other.m_n; count++) {
			other.m_data[count] = m_data[count] + value;
		}
		return other;
	}

	double dot(const Vector& other) {
		double lenght = 0;
		for (int count = 0; count < m_n; count++)
		{
			lenght += other.m_data[count] * m_data[count];
		}
		return lenght;
	}

	void prin() {
		std::cout << "{";
		for (int count = 0; count < m_n; count++) {
			std::cout << m_data[count] << ", ";
		}
		std::cout << "}" << std::endl;
	}
	void setValueVector() {
		for (int count = 0; count < m_n; count++) {
			int value;
			std::cout << "Введите " << count << " элемент: " << std::endl;
			std::cin >> value;
			m_data[count] = value;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector& other) {
		out << "{";
		for (int count = 0; count < other.m_n; count++) {
			out << other.m_data[count] << ", ";
		}
		out << "}";
		return out;
	}
};

int main() {
	Vector first(5);
	first[0] = 1;
	first[1] = 2;
	first[2] = 3;
	first[3] = 4;
	first[4] = 5;
	std::cout << first << std::endl;
	std::cout << first * 5 << std::endl;

	Vector second(5);
	first[0] = 5;
	first[1] = 4;
	first[2] = 3;
	first[3] = 2;
	first[4] = 1;
	std::cout << second << std::endl;

	std::cout << "first + second = " << first + second << std::endl;
	std::cout << "first - second = " << first - second << std::endl;

	Vector third(3);
	std::cout << third << std::endl;

	std::cout << "first * 3" << first * 3 << std::endl;

	return 0;
}
