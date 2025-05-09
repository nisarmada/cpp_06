#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>

class ScalarConverter {
	public:
		static void convert(const std::string& literal);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
};