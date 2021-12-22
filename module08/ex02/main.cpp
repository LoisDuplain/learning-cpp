#include <iterator>
#include <vector>
#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << "Top value in mutant stack: " << mstack.top() << std::endl;
		std::cout << std::endl;

		mstack.pop();
		std::cout << "Top value popped. New top value: " << mstack.top() << std::endl;
		std::cout << std::endl;
		
		std::cout << "Stack size: " << mstack.size() << std::endl;
		std::cout << std::endl;

		std::cout << "Adding 4 values in mstack..." << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "4 values in mstack added..." << std::endl;
		std::cout << std::endl;
		
		std::cout << "Print mstack:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " - " << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);
	}
	std::cout << "-----------------------------------------" << std::endl;
	{
		std::cout << "My tests" << std::endl;
		MutantStack<int> original;
		original.push(42);
		original.push(43);
		original.push(44);

		std::cout << "original size = " << original.size() << std::endl;
		std::cout << "original begin = " << *original.begin() << std::endl;
		std::cout << "original end = " << *(original.end() - 1) << std::endl;
		std::cout << std::endl;

		std::cout << "Copy tests" << std::endl;
		MutantStack<int> copy = original;
		std::cout << "copy begin = " << (*copy.begin() = 10) << std::endl;
		std::cout << "original begin = " << *original.begin() << std::endl;
	}
	return 0;
}