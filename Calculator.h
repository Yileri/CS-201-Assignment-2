#ifndef __CALCULATOR__
#define __CALCULATOR__

#include "Stack.h"
#include <string>

class Calculator {

	Stack* stack;
	string postfixExpression;

public:
	Calculator(string infixExp);
	~Calculator();
	string getPostfix();
	int calculate();
};

#endif 

