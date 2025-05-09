#include "../include/serialization.hpp"

int main () {
	Data* object = new Data;

	object->c = 'a';
	object->number = 42;

	std::cout << "address before: " << object << std::endl;

	uintptr_t seriliazedAddress = Serializer::serialize(object);
	std::cout << "address after: " << seriliazedAddress << std::endl;

	Data* object2 = Serializer::deserialize(seriliazedAddress);
	std::cout << "result: " << object2 << std::endl;

	if (object == object2) {
        std::cout << "Serialization and deserialization were successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed." << std::endl;
    }
    delete object; //remember to delete
    return 0;
}