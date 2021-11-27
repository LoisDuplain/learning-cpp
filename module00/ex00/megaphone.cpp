#include <iostream>

int	main(int argc, char **argv)
{
	int		arg_index;
	int		char_index;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	arg_index = 0;
	while (argv[++arg_index])
	{
		char_index = -1;
		while (argv[arg_index][++char_index])
			std::cout << (char)toupper(argv[arg_index][char_index]);
	}
	std::cout << std::endl;
	return (0);
}