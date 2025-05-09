#include "../include/conversion.hpp"

int main(int ac, char *av[]) {
	
	if (ac != 2) {
		std::cout << "invalid amount of arguments" << std::endl;
		return 1;
	}
	std::string literal = av[1];
	ScalarConverter::convert(av[1]);
	return 0;
}