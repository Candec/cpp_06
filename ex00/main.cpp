#include "scalar.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		Scalar::Scalar(argv[1]);
		
	}
	else
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}

	return (0);
}