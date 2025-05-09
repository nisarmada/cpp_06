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

	if (literal == "+inf" || literal == "-inf") {
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	else {
			if (literal[literal.length() - 1] == 'f') {
				std::cout << "float: " << literal << std::endl;
				std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
			}
			else {
				std::cout << "float: " << literal + 'f' << std::endl;
				std::cout << "double: " << literal << std::endl;
		
			}

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

	number = std::stoi(literal);
	if (number >= 0 && number < 127) {
		char c = static_cast<char>(number);
		std::cout << "char: " << c << std::endl;
	}
	else if (number > 126 && number <= 132)
		std::cout << "char: non displayable" << std::endl;
	else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << number << std::endl;
	
	float f = static_cast<float>(number);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	double b = static_cast<double>(number);
	std::cout << "double: " << b << std::endl;
}

bool isFloat(const std::string& literal) {
	if (literal.back() != 'f')
		return false;
	try {
		std::stof(literal);
		return true;
	}
	catch (std::exception& e) {
		return false;
	}
}

bool isDouble(const std::string& literal) {
	if (literal.back() == 'f')
		return false;
	try {
		size_t pos = 0;
		std::stod(literal, &pos);
		if (pos != literal.length())
			return false;
		return (true);
	}
	catch (std::exception& e) {
		return false;
	}
}

void printFloat(const std::string& literal) {

	float f = std::stof(literal);
	if (f >= 0 && f <= 127) {
		char c = static_cast<char>(f);
		std::cout << "char: " << c << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}
	if (f > static_cast<float>(INT_MIN) && f < static_cast<float>(INT_MAX))
	{
		int number = static_cast<int>(f);
		std::cout << "int: " << number << std::endl;
	}
	else {
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	double d = static_cast<double>(f);
	std::cout << "double: " << d << std::endl;
}

void printDouble(const std::string& literal) {
	double d = std::stod(literal);

	if (d >= 0 && d <= 127) {
		char c = static_cast<char>(d);
		std::cout << "char: " << c << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}
	if (d > INT_MIN && d < INT_MAX) {
		int number = static_cast<int>(d);
		std::cout << "int: " << number << std::endl;
	}
	else {
		std::cout << "int: impossible" << std::endl;
	}
	float f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Invalid: string is empty" << std::endl;
		return ;
	}
	else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		printConversionChar(literal[0]);
	}
	else if (literal == "nan" || literal == "+inf" || literal == "-inff" || literal == "+inff" \
		|| literal == "-inf" || literal == "nanf") {
			printSpecialCases(literal);
	}
	else if (isInt(literal)) {
		printInt(literal);
	}
	else if (isFloat(literal)) {
		printFloat(literal);
	}
	else if (isDouble(literal)) {
		printDouble(literal);
	}
	else {
		std::cout << "Conversion is impossible for argument " << literal << std::endl;
	}
}


//can add extra checks if char is possible but not printable : fixed
//for test double ./conversion 1e308 we get float: inff, might need to look at that
//also ask ellen about special cases cause I'm not casting at all
//./conversion 23231323332132123123g : fixed
//split it in normal sized files this is ridiculous