#include "../include/conversion.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

void printConversionChar(char c) {
	int i = c;

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(i);
	std::cout << "float: " << f << std::endl;

	double d = static_cast<double>(i);
	std::cout << "double: " << d << std::endl;

	return ;
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Invalid: string is empty" << std::endl;
		return ;
	}
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		printConversionChar(literal[0]);
	}


}

//fix char it should be 1 char long and we dont need to check for '