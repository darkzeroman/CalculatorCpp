/*
 * Calculator.h
 *
 *  Created on: Jan 24, 2013
 *      Author: Vidhur Vohra
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <exception>

#include "Scanner.h"
#include "TokenFactory.h"

const int DEBUG = 0; // 0 = none, 1 = verbose

using namespace std;

class Calculator {
public:
	Calculator();
	virtual ~Calculator();
	void calculate();

private:
	queue<Token*> buildExpression();
	void evaluateExpression(queue<Token*> output);
	void applyOperator(stack<Token*> * thestack, OperatorToken * OP);
	int getPrecedence(OperatorToken * token);
	int getAssociativity(OperatorToken * token);
	bool isLeftAssociative(OperatorToken * token);
	bool lessThan(OperatorToken * first, OperatorToken * second);
	bool lessThanOrEqualTo(OperatorToken * first, OperatorToken * second);
	bool checkTwoCases(OperatorToken * o1, OperatorToken * o2);
	void printQueueTokens(queue<Token*> tokens);
	Scanner scan;
};

#endif /* CALCULATOR_H_ */
