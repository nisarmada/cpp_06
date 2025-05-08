#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>
#include <iomanip>

class ScalarConverter {
	public:
		static void convert(const std::string& literal);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
};