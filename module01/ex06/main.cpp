#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./karen-filter <log_level>" << std::endl;
		return (1);
	}
	std::string log_level(argv[1]);
	
	Karen	karen;
	karen.complain(log_level);
	
	return (0);
}
