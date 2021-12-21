#include "Iter.hpp"

template <typename T>
void	print(T const &src)
{
	std::cout << src << std::endl;
}

int	main()
{
	int			numbers[5] = { 42, 43, 44, 45, 46 };
	std::string	strings[3] = { "Coucou", "Maman", "Bobo" };

	std::cout << "Print numbers:" << std::endl;
	iter(numbers, 5, &print);
	std::cout << std::endl;

	std::cout << "Print first 3 numbers:" << std::endl;
	iter(numbers, 3, &print);
	std::cout << std::endl;
	
	std::cout << "Print strings:" << std::endl;
	iter(strings, 3, &print);
	std::cout << std::endl;

	std::cout << "Print first string:" << std::endl;
	iter(strings, 1, &print);
	
	return 0;
}