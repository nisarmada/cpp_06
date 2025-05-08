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
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	double d = static_cast<double>(i);
	std::cout << "double: " << d << std::endl;

	return ;
}

void printSpecialCases(const std::string& literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal[literal.length() - 1] == 'f') {
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
	else {
		std::cout << "float: " << literal + 'f' << std::endl;
		std::cout << "double: " << literal << std::endl;

	}
}

bool isInt(const std::string& literal) {
	std::stringstream ss(literal);
	int number;

	ss >> number;

	return ((!ss.fail() && ss.eof()));
}

void printInt(const std::string& literal) {
	int number;

	try {
		number = std::stoi(literal);
	}
	catch (const std::exception &e) {
		std::cout << "Not an int" << std::endl;
	}
	if (number >= 32 && number <= 126) {
		char c = static_cast<char>(number);
		std::cout << "char: " << c << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << number << std::endl;
	
	float f = static_cast<float>(number);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	double b = static_cast<double>(number);
	std::cout << "double: " << b << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Invalid: string is empty" << std::endl;
		return ;
	}
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		printConversionChar(literal[0]);
	}
	if (literal == "nan" || literal == "+inf" || literal == "-inff" || literal == "+inff" \
		|| literal == "-inf" || literal == "nanf") {
			printSpecialCases(literal);
	}
	if (isInt(literal)) {
		printInt(literal);
	}
	
}
