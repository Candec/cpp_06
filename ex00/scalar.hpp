#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <string>
# include <limits>
# include <sstream>
# include <iostream>
# include <stdlib.h>

enum {NON, CHAR, INT, FLOAT, DOUBLE, ESP};

class Scalar
{
	public:

	// CONSTRUCTORS
	Scalar(char *src);
	Scalar(const Scalar &src);
	Scalar& operator=(const Scalar &src);
	~Scalar();

	// SETTER & GETTER
	void setString(const char* str);
	void setType(const std::string &str);
	void setNumber(const std::string &str);
	int getType() const;
	double getNumber() const;
	std::string getString() const;

	// TYPE DETECTION
	bool isChar(const std::string &src);
	bool isInt(const std::string &src);
	bool isFloat(const std::string &src);
	bool isDouble(const std::string &src);
	bool isSpecial(const std::string &src);

	// PRINT
	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDouble() const;
	void printSpecial() const;

	private:

	Scalar();

	int 	type;
	double	number;
	std::string str;

};

#endif