#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Adress of str  = " << &str << std::endl;
	std::cout << "Adress of stringPTR = " << stringPTR << std::endl;
	std::cout << "Adress of stringREF = " << &stringREF << std::endl;

	std::cout << "\nValues are:" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	std::cout << "\nChanging value of str by modifying str" << std::endl;
	str = "Normalement ca change de partout";
	std::cout << "str: " << str << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	std::cout << "\nChanging value of str by modifying *stringPTR" << std::endl;
	*stringPTR = "Avec le pointeur aussi";
	std::cout << "str: " << str << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	std::cout << "\nChanging value of str by modifying stringREF" << std::endl;
	stringREF = "Et avec la ref ca change aussi";
	std::cout << "str: " << str << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}