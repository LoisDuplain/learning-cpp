#include <iostream>
#include <cmath>

void	convert(std::string arg)
{
	double	nb;

	if (arg.length() == 1 && !isdigit(static_cast<int>(arg[0])))
		nb = static_cast<double>(arg[0]);
	else
		nb = atof(arg.c_str());

	/* Print char value */
	if ((atoi(arg.c_str()) == 0 && arg.length() > 1 )
		|| nb > std::numeric_limits<int>::max()
		|| nb < std::numeric_limits<int>::min())
		std::cout << "char: not a character" << std::endl;
	else if (nb < 32 || nb > 126)
		std::cout << "char: non printable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(nb) << std::endl;

	/* Print int value */
	if (nb != nb
		|| nb < std::numeric_limits<int>::min()
		|| nb > std::numeric_limits<int>::max())
		std::cout << "int: not an int" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;

	/* Print float value */
	if (fmod(nb, 1) == 0)
		std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;

	/* Print double value */
	if (fmod(nb, 1) == 0)
		std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Usage: ./cast <litteral>" << std::endl;
	else
		convert(av[1]);
	return (0);
}