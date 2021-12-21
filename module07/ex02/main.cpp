#include <sys/_types/_uintptr_t.h>

#include "Array.hpp"

int	main()
{
	std::cout << "Empty arrays tests" << std::endl;
	Array<int> arrayInt;
	Array<float> arrayFloat;
	Array<std::string> arrayString;
	std::cout << "Array int size = " << arrayInt.size() << std::endl;
	std::cout << "Array float size = " << arrayFloat.size() << std::endl;
	std::cout << "Array string size = " << arrayString.size() << std::endl;
	Array<int> arrayIntEmpty(0);
	Array<float> arrayFloatEmpty(0);
	Array<std::string> arrayStringEmpty(0);
	std::cout << "arrayIntEmpty size = " << arrayIntEmpty.size() << std::endl;
	std::cout << "arrayFloatEmpty size = " << arrayFloatEmpty.size() << std::endl;
	std::cout << "arrayStringEmpty size = " << arrayStringEmpty.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Size tests" << std::endl;
	Array<int> arrayInt2(10);
	Array<float> arrayFloat2(10);
	Array<std::string> arrayString2(10);
	std::cout << "arrayInt2 size = " << arrayInt2.size() << std::endl;
	std::cout << "arrayFloat2 size = " << arrayFloat2.size() << std::endl;
	std::cout << "arrayString2 size = " << arrayString2.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Printing tests" << std::endl;
	for (unsigned int i = 0; i < arrayInt2.size(); i++)
	{
		arrayInt2[i] = i + 1;
		arrayFloat2[i] = i + 1;
		arrayString2[i] = i + 97;
		std::cout << "arrayInt2 = " << arrayInt2[i] << std::endl;
		std::cout << "arrayFloat2 = " << arrayFloat2[i] << std::endl;
		std::cout << "arrayString2 = " << arrayString2[i] << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Copy by = tests" << std::endl;
	std::cout << "Copying arrayFloat2 in arrayFloat3" << std::endl;
	Array<float> arrayFloat3 = arrayFloat2;
	std::cout << "arrayFloat3[0] = " << arrayFloat3[0] << std::endl;
	std::cout << "arrayFloat3[1] = " << arrayFloat3[1] << std::endl;
	std::cout << "arrayFloat3[2] = " << arrayFloat3[2] << std::endl;
	std::cout << std::endl;

	std::cout << "Modify tests" << std::endl;
	arrayFloat3[2] = 777.777;
	std::cout << "arrayFloat3[2] = " << arrayFloat3[2] << std::endl;
	std::cout << "arrayFloat2[2] = " << arrayFloat2[2] << std::endl;
	std::cout << std::endl;

	std::cout << "Copy by constructor tests" << std::endl;
	std::cout << "Copying arrayFloat3 in arrayFloat4" << std::endl;
	Array<float> arrayFloat4(arrayFloat3);
	std::cout << "arrayFloat4[0] = " << arrayFloat4[0] << std::endl;
	std::cout << "arrayFloat4[1] = " << arrayFloat4[1] << std::endl;
	std::cout << "arrayFloat4[2] = " << arrayFloat4[2] << std::endl;
	std::cout << std::endl;

	std::cout << "Modify tests" << std::endl;
	arrayFloat4[2] = 888.777;
	std::cout << "arrayFloat4[2] = " << arrayFloat4[2] << std::endl;
	std::cout << "arrayFloat3[2] = " << arrayFloat3[2] << std::endl;

	std::cout << "Out of range tests" << std::endl;
	std::cout << "Trying to access arrayFloat3[11]" << std::endl;
	try
	{
		arrayFloat3[11];
	}
	catch (Array<float>::IndexOutOfBoundsException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}