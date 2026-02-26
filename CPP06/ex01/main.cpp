#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "ex01";

	uintptr_t raw = Serializer::serialize(&data);
	Data *copy = Serializer::deserialize(raw);

	std::cout << "### Original ###" << std::endl;
	std::cout << "ID: " << data.id << std::endl;
	std::cout << "Name: " << data.name << std::endl;
	std::cout << std::endl;
	std::cout << "### Copy ###" << std::endl;
	std::cout << "ID: " << copy->id << std::endl;
	std::cout << "Name: " << copy->name << std::endl;

	return 0;
}