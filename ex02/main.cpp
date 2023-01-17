#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>

Base*	generate() {
	int		index;

	srand(time(NULL));
	index = rand() % 3;
	std::cout << "Index: " << index + 1 << std::endl;
	switch (index) {
		case (0):
			return (new A);
		case (1):
			return (new B);
		default:
			return (new C);
	}
}

void	identify(Base* p) {
	A*	a;
	B*	b;
	C*	c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "p* has type A.\n";
	else if (b)
		std::cout << "p* has type B.\n";
	else if (c)
		std::cout << "p* has type C.\n";
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "p has type A.\n";
	} catch (std::exception&){
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "p has type B.\n";
		} catch (std::exception&) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "p has type C.\n";
			} catch (std::exception&) {}
		}
	}
}

int main() {
	Base*	x_ptr = generate();

	identify(x_ptr);
	identify(*x_ptr);
	delete x_ptr;
	return (0);
}