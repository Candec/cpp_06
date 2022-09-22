#include "scalar.hpp"

	// CONSTRUCTORS
	Scalar::Scalar()
	{
		std::cout << "[Scalar] default constructor" << std::endl;
	}

	Scalar::Scalar(char *src)
	{
		setString(src);
		setNumber(getString());
		setType(getString());
		std::cout << "[Scalar] char* constructor" << std::endl;
	}

	Scalar::Scalar(const Scalar &src)
	{
		*this = src;
		std::cout << "[Scalar] copy constructor" << std::endl;
	}

	Scalar& Scalar::operator=(const Scalar &src)
	{
		if (this != &src)
		{
			str = src.getString();
			number = src.getNumber();
			type = src.getType();
		}
		std::cout << "[Scalar] assign operator" << std::endl;
		return (*this);
	}

	Scalar::~Scalar()
	{
		std::cout << "[Scalar] default destructor" << std::endl;
	}

	// SETTER & GETTER
	void Scalar::setString(const char* _str)
	{
		str = _str;
	}

	void Scalar::setType(const std::string &str)
	{
		if (isChar(str))
			type = CHAR;
		else if (isInt(str))
			type = INT;
		else if (isFloat(str))
			type = FLOAT;
		else if (isDouble(str))
			type = DOUBLE;
		else if (isSpecial(str))
			type = ESP;
	}

	void Scalar::setNumber(const std::string &str)
	{

	}

	int Scalar::getType() const
	{
		return (type);
	}

	double Scalar::getNumber() const
	{
		return (number);
	}

	std::string Scalar::getString() const
	{
		return (str);
	}

	// TYPE DETECTION
	bool isChar(const std::string &src)
	{
		src.length() == 1 ? return true : return false;
	}

	bool isInt(const std::string &src)
	{

	}

	bool isFloat(const std::string &src)
	{

	}

	bool isDouble(const std::string &src)
	{

	}

	bool isSpecial(const std::string &src)
	{

	}