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

Calculator::Calculator() :
		scan() {
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

	// Shunting-yard algorithm, http://bit.ly/NDNpU
	unsigned int i = 0;

	while (i < tokens.size()) {
		if (tokens[i]->getType() == NUMBER) {
			output->push(tokens[i]);
		} else if (tokens[i]->getType() != EOL) { // leaving only OPERATORS
			Token* o1 = tokens[i];
			while (thestack.size() > 0 && thestack.top()->isOperator()
					&& checkTwoCases((OperatorToken*) o1,
							(OperatorToken*) thestack.top())) {
				output->push(thestack.top());
				thestack.pop();
			}
			thestack.push(o1);

		} else { //moving the last remaining OPERATORS from queue to stack
			while (thestack.size() > 0 && thestack.top()->isOperator()) {
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

		if (output->front()->isOperator()) {
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

void Calculator::applyOperator(stack<Token*> * the_stack, OperatorToken * OP) {
	Token * first_token = the_stack->top();
	the_stack->pop();
	Token * second_token = the_stack->top();
	the_stack->pop();

	int first_number = ((NumberToken*) first_token)->get_num();
	int second_number = ((NumberToken*) second_token)->get_num();

	int result_number = ((OperatorToken*) OP)->apply(first_number, second_number);

	NumberToken * result_number_token = new NumberToken(result_number);
	the_stack->push(result_number_token);
}

void Calculator::printVectorTokens(queue<Token*> * output) {
	cout << "Vector size: " << output->size() << endl;
	while (output->size() > 0) {
		Token * token = output->front();
		cout << "Type: " << token->getType() << " , " << token << endl;
		output->pop();
	}
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

