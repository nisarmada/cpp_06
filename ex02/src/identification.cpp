#include "../include/identification.hpp"

Base* generate(void) {
	std::srand(std::time(0));

	int randomNumber = (std::rand() % 3) + 1;
	Base* base = nullptr;

	if (randomNumber == 1)
		base = new A;
	else if (randomNumber == 2)
		base = new B;
	else 
		base = new C;
	return (base);
}

void identify(Base* p) {
	A* checkA = dynamic_cast<A*>(p);
	B* checkB = dynamic_cast<B*>(p);
	C* checkC = dynamic_cast<C*>(p);

	if (checkA)
		std::cout << "A" << std::endl;
	if (checkB)
		std::cout << "B" << std::endl;
	if (checkC)
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& checkA = dynamic_cast<A&>(p);
		(void)checkA;
		std::cout << "A" << std::endl;
	}
	catch (const std::bad_cast& b) {
		try {
			B& checkB = dynamic_cast<B&>(p);
			(void)checkB;
			std::cout << "B" << std::endl;
		}
		catch (const std::bad_cast& b) {
				C& checkC = dynamic_cast<C&>(p);
				(void)checkC;
				std::cout << "C" << std::endl;
			}
	}
}