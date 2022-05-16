#include <iostream>
#include "incVector.h"



int main() {
	Vector first(5);
	std::cout << "Enter the first vector" << std::endl;
	std::cin >> first;//не добавлял проверку на числа, поэтому буквы и прочие символы сломают программу
	std::cout << "first = " << first << std::endl;
	std::cout << "first * 5 = " << first * 5 << std::endl;

	Vector second(5);
	second[0] = 5;
	second[1] = 4;
	second[2] = 3;
	second[3] = 2;
	second[4] = 1;
	std::cout << "second = " << second << std::endl;

	std::cout << "first + second = " << first + second << std::endl;
	std::cout << "first - second = " << first - second << std::endl;

	Vector third(3);
	std::cout << "third = " << third << std::endl;

	std::cout << "first * 3 = " << first * 3 << std::endl;
	std::cout << "3 * second = " << 3 * second << std::endl;

	return 0;
}
