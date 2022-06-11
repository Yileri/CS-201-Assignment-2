#include "Calculator.h"
#include "Stack.h"
#include "StackItem.h"

// constructor
Calculator::Calculator(string infixExp) {

	// creates a stack for calculator
	Stack* stack = new Stack();
	this->stack = stack;
	this->postfixExpression = "";

	int i = 0;

	// checks the string elements one by one until it reaches a semi colon
	while (infixExp[i] != ';') {

		if (infixExp[i] != ' ') {

			// since the constructor of StackItem needs a string, create an empty string and add the char 
			// and then use it as the string parameter
			string element = "";
			element += infixExp[i];

			// keeps adding other digits if the number has multiple digits
			while (infixExp[i + 1] != ' ') {
				element += infixExp[i + 1];
				i++;
			}

			// creates a StackItem pointer using string element
			StackItem* item = new StackItem(element);

			// checks if the element is operator or not
			if (item->isOperator == false) {

				// outputs operands immediately
				postfixExpression += item->toString() + " ";

			}

			else {

				// checks for paranthesis
				if (infixExp[i] == '(') {
					stack->push(item);
				}

				else if (infixExp[i] == ')') {

					// if there is a right paranthesis, 
					// output every element until a left paranthesis
					while (!(stack->top()->toString().compare("(") == 0)) {
						postfixExpression += stack->pop()->toString() + " ";
					}

					// pop left paranthesis but do not output
					stack->pop();
				}

				else {

					// pop and output all elements with higher precedence and
					// push at the end

					if (!stack->isEmpty()) {

						if ((stack->top()->op) >= item->op) {


							while (!(stack->isEmpty()) && (stack->top()->op) >= item->op) {

								postfixExpression += stack->pop()->toString() + " ";

							}

						}
					}

					stack->push(item);
				}
			}

		}

		i++;
	}

	// empty the stack when the input is over
	while (stack->isEmpty() == false) {
		postfixExpression += stack->pop()->toString() + " ";
	}

	postfixExpression += ";";
}

// simply returns postfix expression that is created in constructor
string Calculator::getPostfix() {
	return this->postfixExpression;
}

int Calculator::calculate() {

	int i = 0;

	// check until reaching a semi colon
	while (postfixExpression[i] != ';') {

		// skip the spaces
		if (postfixExpression[i] != ' ') {

			// same principle in the constructor
			string element = "";
			element += postfixExpression[i];

			while (postfixExpression[i + 1] != ' ') {
				element += postfixExpression[i + 1];
				i++;
			}

			// in case of encountering an operator, do their respective calculation
			// and push the result to stack
			if (element.compare("+") == 0) {
				int n1 = stack->pop()->n;
				int n2 = stack->pop()->n;
				StackItem* item = new StackItem(false, n1 + n2);
				stack->push(item);
			}

			else if (element.compare("-") == 0) {
				int n1 = stack->pop()->n;
				int n2 = stack->pop()->n;
				StackItem* item = new StackItem(false, n2 - n1);
				stack->push(item);
			}

			else if (element.compare("*") == 0) {
				int n1 = stack->pop()->n;
				int n2 = stack->pop()->n;
				StackItem* item = new StackItem(false, n1 * n2);
				stack->push(item);
			}

			else if (element.compare("/") == 0) {
				int n1 = stack->pop()->n;
				int n2 = stack->pop()->n;
				StackItem* item = new StackItem(false, n2 / n1);
				stack->push(item);
			}

			// if the element is a number, push to the stack
			else {
				StackItem* item = new StackItem(element);
				stack->push(item);
			}

		}

		// increments the index
		i++;
	}

	// the last element of the stack will be our final result
	return stack->pop()->n;
}

Calculator::~Calculator() {
	delete stack;
}