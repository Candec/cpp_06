#include "serialization.hpp"

#include <iostream>
#include <stdint.h>
#include <cstring>

typedef struct s_Data
{
	std::string	name;
	int		age;
	bool	job;
} Data;


uintptr_t serialize(Data* ptr)
{
	uintptr_t raw  = (uintptr_t)ptr;

	return (raw);
}

Data* deserialize(uintptr_t raw)
{
	Data* ptr  = (Data*)raw;

	return (ptr);
}

int main()
{
	Data person = {"John", 30, true};
	uintptr_t raw;
	Data *IveSeenThings;


	std::cout << "Name:		" << person.name << std::endl
			<< "Age:		" << person.age << std::endl
			<< "Job:		" << person.job << std::endl;
	
	
	raw = serialize(&person);


	person.age += 5;
	person.job = false;


	IveSeenThings = deserialize(raw);


	std::cout << "Name:		" << IveSeenThings->name << std::endl
			<< "Age:		" << IveSeenThings->age << std::endl
			<< "Job:		" << IveSeenThings->job << std::endl;

	std::cout << &person << std::endl << IveSeenThings << std::endl;
	
	return (0);
}