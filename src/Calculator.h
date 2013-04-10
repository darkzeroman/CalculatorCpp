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
#include "Scanner.h"
#include "TokenFactory.h"

using namespace std;

const int DEBUG = 0; // 0 = none, 1 = verbose

class Calculator {
public:
	Calculator() :
			scan() {
	}

	virtual ~Calculator();
	void calculate();

private:
	queue<Token*> * buildExpression();
	void evaluateExpression(queue<Token*> * output);
	void applyOperator(stack<Token*> * thestack, OperatorToken * OP);
	int getPrecedence(OperatorToken * token);
	int getAssociativity(OperatorToken * token);
	bool isLeftAssoc(OperatorToken * token);
	bool isOperator(Token * token);
	bool lessThan(OperatorToken * first, OperatorToken * second);
	bool lessThanOrEqualTo(OperatorToken * first, OperatorToken * second);
	bool checkTwoCases(OperatorToken * o1, OperatorToken * o2);
	void printVectorTokens(queue<Token*> * tokens);
	int stringToInt(string str);
	string intToString(int value);

	Scanner scan;

};

#endif /* CALCULATOR_H_ */
