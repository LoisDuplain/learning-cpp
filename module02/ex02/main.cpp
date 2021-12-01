#include "Fixed.hpp"

int main(void) {
	Fixed		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << "a = " << a << std::endl;
	std::cout << "++a (a + 1/256)=(a + 1 / 2^8)" << ++a << std::endl;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl << std::endl;

	Fixed c = Fixed(10);
	
	std::cout << "c = " << c << std::endl << std::endl;
	
	std::cout << "b + c = " << b + c << std::endl;
	std::cout << "b - c = " << b - c << std::endl;
	std::cout << "c / 2 = " << c / 2 << std::endl;
	std::cout << "c = " << c << std::endl << std::endl;
	
	std::cout << "(c = c / 2) = " << (c = c / 2) << std::endl;
	std::cout << "c = " << c << std::endl << std::endl;
	
	std::cout << "--c = " << --c << std::endl;
	
	std::cout << "c-- = " << c-- << std::endl;
	std::cout << "c = " << c << std::endl << std::endl;
	
	std::cout << "min(c, b) = " << Fixed::min(c, b) << std::endl;
	std::cout << "max(c * b, b) = " << Fixed::max(c * b, b) << std::endl;
	
	std::cout << "c < b = " << (c < b) << std::endl;
	std::cout << "c > b = " << (c > b) << std::endl;
	std::cout << "c <= b = " << (c <= b) << std::endl;
	std::cout << "c >= b = " << (c >= b) << std::endl;
	std::cout << "c == b = " << (c == b) << std::endl;
	std::cout << "c != b = " << (c != b) << std::endl;
	
	return (0);
}
