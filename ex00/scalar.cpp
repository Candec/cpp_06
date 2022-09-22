#include "scalar.hpp"

	// CONSTRUCTORS
	Scalar::Scalar()
	{
		//std::cout << "[Scalar] default constructor" << std::endl;
	}

	Scalar::Scalar(const std::string &src)
	{
		setType(src);
		setString(src);
		setNumber(src);
		printChar();
		printInt();
		printFloat();
		printDouble();
		//std::cout << "[Scalar] char* constructor" << std::endl;
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
		//std::cout << "[Scalar] default destructor" << std::endl;
	}

	// SETTER & GETTER
	void Scalar::setString(const std::string &_str)
	{
		str = _str;
	}

	void Scalar::setType(const std::string &str)
	{
		type = NON;

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

	void Scalar::setNumber(const std::string &_str)
	{
		if (getType() == ESP)
		{
			str = _str;
			if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
				str = _str.substr(0, _str.length() - 1);
		}
		else if (getType() == INT || getType() == DOUBLE)
		{
			std::istringstream ss(str);
			ss >> number;
		}
		else if (getType() == FLOAT)
		{
			std::string temp = _str.substr(0, _str.length() - 1);
			std::istringstream temp_str(temp);

			temp_str >> number;
		}
		else if (getType() == CHAR)
		{
			std::istringstream ss(str);
			char c;

			ss >> c;
			number = c;
		}
		else
			number = 0;
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
	bool Scalar::isChar(const std::string &src)
	{
		return (src.length() == 1 && std::isprint(src[0]));
	}

	bool Scalar::isInt(const std::string &src)
	{
		std::istringstream ss(src);
		int i;

		ss >> i;
		return (ss.eof() && !ss.fail());
	}

	bool Scalar::isFloat(const std::string &src)
	{
		std::string number;
		std::string letter;
		int point = 0;
		float f;

		//checks the number, intiger and decimal
		number = src.substr(0, src.length() - 1);
		//chacks the final 'f'
		letter = src.substr(src.length() - 1, 1);

		//looks for the decimal dot
		for (size_t i = 0; i < src.length(); i++)
		{
			if (number[i] == '.')
				point++; 
		}

		//transforms the steam to the float
		std::istringstream ss(number);
		ss >> f;

		//checks stream reaches the end, if it fails,
		//a single point and the letter f
		return (ss.eof() && !ss.fail() && point == 1 && letter == "f");
	}

	bool Scalar::isDouble(const std::string &src)
	{
		std::istringstream ss(src);
		double d;

		ss >> d;
		return (ss.eof() && !ss.fail());
	}

	bool Scalar::isSpecial(const std::string &src)
	{
		return (!src.compare("-inf") || !src.compare("+inf") || !src.compare("nan")
			|| !src.compare("-inff") || !src.compare("+inff") || !src.compare("nanf"));
	}

	// PRINT
	void Scalar::printChar() const
	{
		std::cout << "Char:			";
		if (getType() == NON || getType() == ESP)
			std::cout << "Impossible" << std::endl;
		else if (std::isprint(static_cast<int>(getNumber())))
			std::cout << '\'' << static_cast<char>(getNumber()) << '\'' << std::endl;
		else
			std::cout << "Non dispalyable" << std::endl;
	}

	void Scalar::printInt() const
	{
		std::cout << "Intiger:		";
		if (getType() == NON || getType() == ESP)
			std::cout << "Impossible" << std::endl;
		else if (getNumber() > 2147483647 || getNumber() < -2147483648)
			std::cout << "Impossible" << std::endl;
		else
			std::cout << static_cast<int>(getNumber()) << std::endl;
	}

	void Scalar::printFloat() const
	{
		std::cout << "Float:			";
		if (getType() == NON)
			std::cout << "Impossible" << std::endl;
		else if (getType() == ESP)
			std::cout << getString() << 'f' << std::endl;
		else
		{
			std::cout.precision(1);
			std::cout << std::fixed << static_cast<float>(getNumber()) << 'f' << std::endl;
		}
	}
	void Scalar::printDouble() const
	{
		std::cout << "Double:			";
		if (getType() == NON)
			std::cout << "Impossible" << std::endl;
		else if (getType() == ESP)
			std::cout << getString() << std::endl;
		else
		{
			std::cout.precision(1);
			std::cout << std::fixed << static_cast<double>(getNumber()) << std::endl;
		}
	}
