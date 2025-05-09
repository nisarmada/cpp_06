#include "../include/serialization.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t codedMessage = reinterpret_cast<uintptr_t>(ptr);

	return codedMessage;
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* decodedMessage = reinterpret_cast<Data*>(raw);

	return (decodedMessage);
}