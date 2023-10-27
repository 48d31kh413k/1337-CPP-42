#include "Serializer.hpp"

Serializer::Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t ptr) {
	return reinterpret_cast<Data*>(ptr);
}