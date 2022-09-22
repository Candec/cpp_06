#include "scalar.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::string str(argv[1]);
		Scalar convert(str);
	}
	else
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}

	return (0);
}