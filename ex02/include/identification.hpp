#pragma once

#include <iostream>
#include <random>
#include <cstdlib> 
#include <ctime>

class Base {
	public:
		Base();
		virtual ~Base();
		Base(const Base& other);
		Base& operator=(const Base& other);
};

class A : public Base {
	public:
		A();
		~A();
		A(const A& other);
		A& operator=(const A& other);
};

class B : public Base {
	public:
		B();
		~B();
		B(const B& other);
		B& operator=(const B& other);
};

class C : public Base {
	public:
		C();
		~C();
		C(const C& other);
		C& operator=(const C& other);
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);