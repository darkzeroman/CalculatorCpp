/*
 * Calculator.cpp
 *
 *  Created on: Jan 24, 2013
 *      Author: Vidhur Vohra
 */

#include "Calculator.h"

int main() {
	Calculator calculator;
	calculator.calculate();
}

Calculator::~Calculator() {
}

queue<Token*> * Calculator::buildExpression() {
	vector<Token*> tokens = scan.getTokens();

	if (DEBUG) {
		cout << "printing vector tokens" << endl;
		for (unsigned int i = 0; i < tokens.size(); i++) {
			cout << tokens[i]->toString() << endl;
		}
		cout << tokens.size() << endl;
	}

	if (tokens.size() == 1 && tokens[0]->getType() == EOL)
		return new queue<Token*>(); // got q command, so exit

	queue<Token*> * output = new queue<Token*>();
	stack<Token*> thestack;

	// Shunting algorithm
	unsigned int i = 0;

	while (i < tokens.size()) {
		if (tokens[i]->getType() == NUMBER) {
			output->push(tokens[i]);
		} else if (tokens[i]->getType() != EOL) { // leaving only OPERATORS
			Token* o1 = tokens[i];
			while (thestack.size() > 0 && isOperator(thestack.top())
					&& checkTwoCases((OperatorToken*) o1,
							(OperatorToken*) thestack.top())) {
				output->push(thestack.top());
				thestack.pop();
			}
			thestack.push(o1);

		} else { //moving the last remaining OPERATORS from queue to stack
			while (thestack.size() > 0 && isOperator(thestack.top())) {
				output->push(thestack.top());
				thestack.pop();
			}
		}
		i++;
	}

	return output;
}

void Calculator::calculate() {
	cout << "Welcome to the High Order Calculator (q to quit) " << endl;

	while (true) {
		queue<Token*> * expression = buildExpression();

		if ((expression->size() && expression->front()->getType() == EOL)
				|| (expression->size() == 0)) {
			break;
		}
		evaluateExpression(expression);
	}

	cout << "Quitting" << endl;
}
void Calculator::evaluateExpression(queue<Token*> * output) {
	stack<Token*> thestack;

	while (output->size() > 0) {
		if (DEBUG) {
			cout << "output next: " << output->front()->toString() << endl;
		}

		if (isOperator(output->front())) {
			applyOperator(&thestack, (OperatorToken*) output->front());
		} else {
			thestack.push(output->front());
		}
		output->pop();
	}

	if (DEBUG)
		cout << "stack size: " << thestack.size() << endl;

	cout << "Result: " << thestack.top()->toString() << endl;
}

void Calculator::applyOperator(stack<Token*> * thestack, OperatorToken * OP) {
	Token * firstToken = thestack->top();
	thestack->pop();
	Token * secondToken = thestack->top();
	thestack->pop();

	int firstNumber = ((NumberToken*) firstToken)->get_num();
	int secondNumber = ((NumberToken*) secondToken)->get_num();

	int resultNumber = ((OperatorToken*) OP)->applyOperator(firstNumber,
			secondNumber);

	NumberToken * new_number_token = new NumberToken(resultNumber);
	thestack->push(new_number_token);
}

void Calculator::printVectorTokens(queue<Token*> * output) {
	cout << "Vector size: " << output->size() << endl;
	while (output->size() > 0) {
		Token * token = output->front();
		cout << "Type: " << token->getType() << " , " << token << endl;
		output->pop();
	}
}

bool Calculator::isOperator(Token * token) {
	return (token->getType() == OPERATOR);
}

int Calculator::getPrecedence(OperatorToken * token) {
	if (token->getType() == OPERATOR)
		return 3;
	else
		return 2;
}

int Calculator::getAssociativity(OperatorToken * token) {
	return -1; // for now, ADDOP and MULTOP have the same associativity, so return -1
}

bool Calculator::isLeftAssoc(OperatorToken * token) {
	return (getAssociativity(token) == -1);
}

bool Calculator::lessThanOrEqualTo(OperatorToken * first,
		OperatorToken * second) {
	return getPrecedence(first) <= getPrecedence(second);
}

bool Calculator::lessThan(OperatorToken * first, OperatorToken * second) {
	return getPrecedence(first) < getPrecedence(second);
}

bool Calculator::checkTwoCases(OperatorToken * o1, OperatorToken * o2) {
	return ((isLeftAssoc(o1) && lessThanOrEqualTo(o1, o2)) || (lessThan(o1, o2)));
}

