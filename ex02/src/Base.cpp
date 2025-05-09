#include "../include/identification.hpp"

Base::Base() {}

Base::~Base () {}

Base::Base(const Base& other) {
	(void)other;
}

Base& Base::operator=(const Base& other) {
	(void)other;
	return (*this);
}

A::A() {}

A::~A() {}

A::A(const A& other) :Base(other) {}

A& A::operator=(const A& other) {
	if (this != &other) {
		Base::operator=(other);
	}
	return *this;
}

B::B() {}

B::~B() {}

B::B(const B& other) : Base(other) {}

B& B::operator=(const B& other) {
	if (this != &other) {
		Base::operator=(other);
	}
	return *this;
}

C::C() {}

C::~C() {}

C::C(const C& other) : Base(other) {}

C& C::operator=(const C& other) {
	if (this != &other) {
		Base::operator=(other);
	}
	return *this;
}