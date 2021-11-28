#include <iostream>
#include <fstream>

std::string	replace(std::string str, std::string to_replace, std::string by)
{
	if (to_replace.empty())
		return str;

	std::string	result;
	size_t		found_index;

	while ((found_index = str.find(to_replace)) != std::string::npos)
	{
		result.append(str.substr(0, found_index)).append(by);
		str.erase(0, found_index + to_replace.size());
	}
	result.append(str);

	return result;
}

void	replace_file_content(std::string file_name, std::string to_replace, std::string by)
{
	std::ifstream	file(file_name);
	if (!file.is_open())
	{
		std::cerr << "Error: can't open input file (" << file_name << ")" << std::endl;
		return;
	}
	
	std::ofstream	replaced_file(file_name + ".replace");
	if (!replaced_file.is_open())
	{
		file.close();
		std::cerr << "Error: can't open output file (" << file_name << ".replace)" << std::endl;
		return;
	}

	std::string	line;
	while (std::getline(file, line))
	{
		replaced_file << replace(line, to_replace, by);
		if (!file.eof())
			replaced_file << std::endl;
	}

	file.close();
	replaced_file.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <file_name> <s1>(to_replace) <s2>(by)" << std::endl;
		return (1);
	}
	
	std::string	file_name(argv[1]);
	if (file_name.empty())
	{
		std::cerr << "file_name string cannot be empty" << std::endl;
		return (1);
	}

	std::string	to_replace(argv[2]);
	if (to_replace.empty())
	{
		std::cerr << "s1 (to_replace) string cannot be empty" << std::endl;
		return (1);
	}
	
	std::string	by(argv[3]);

	replace_file_content(file_name, to_replace, by);
	return (0);
}