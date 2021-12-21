#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base() {}
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate()
{
	switch (rand() % 3)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	default:
		return new C;
		break;
	}
}

void	identify(Base *p)
{
	A *a = NULL;
	B *b = NULL;
	C *c = NULL;
	if ((a = dynamic_cast<A *>(p)) != NULL)
		std::cout << "A" << std::endl;
	else if ((b = dynamic_cast<B *>(p)) != NULL)
		std::cout << "B" << std::endl;
	else if ((c = dynamic_cast<C *>(p)) != NULL)
		std::cout << "C" << std::endl;
}
void	identify(Base &p)
{
	Base	*tmp;

	try {
		tmp = &dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::bad_cast &e) {}
	try {
		tmp = &dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &e) {}
	try {
		tmp = &dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &e) {}
}

int main()
{
	srand(time(NULL));
	
	Base	*base1 = NULL;
	Base	*base2 = NULL;
	Base	*base3 = NULL;

	base1 = generate();
	base2 = generate();
	base3 = generate();

	std::cout << "By pointer:" << std::endl;
	identify(base1);
	identify(base2);
	identify(base3);
	
	std::cout << std::endl;

	std::cout << "By reference:" << std::endl;
	identify(*base1);
	identify(*base2);
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;
}