#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*pstr = &str;
	std::string &rstr = str;

	std::cout << "Adress in memory of str  = " << &str << std::endl;
	std::cout << "Adress in memory of pstr = " << pstr << std::endl;
	std::cout << "Adress in memory of rstr = " << &rstr << std::endl;

	std::cout << "\nValues are:" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "*pstr: " << *pstr << std::endl;
	std::cout << "rstr: " << rstr << std::endl;

	std::cout << "\nChanging value of str by modifying str" << std::endl;
	str = "Normalement ca change de partout";
	std::cout << "str: " << str << std::endl;
	std::cout << "*pstr: " << *pstr << std::endl;
	std::cout << "rstr: " << rstr << std::endl;

	std::cout << "\nChanging value of str by modifying *pstr" << std::endl;
	*pstr = "Avec le pointeur aussi";
	std::cout << "str: " << str << std::endl;
	std::cout << "*pstr: " << *pstr << std::endl;
	std::cout << "rstr: " << rstr << std::endl;

	std::cout << "\nChanging value of str by modifying rstr" << std::endl;
	rstr = "Et avec la ref ca change aussi";
	std::cout << "str: " << str << std::endl;
	std::cout << "*pstr: " << *pstr << std::endl;
	std::cout << "rstr: " << rstr << std::endl;
}