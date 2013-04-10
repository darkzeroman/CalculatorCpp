/*
 * OperationToken.h
 *
 *  Created on: Apr 3, 2013
 *      Author: Vidhur Vohra
 */

#ifndef OPERATIONTOKEN_H_
#define OPERATIONTOKEN_H_

#include "Token.h"

enum OperatorType {
	ADDOP, SUBTRACTOP, DIVIDEOP, MULTOP
};

class OperatorToken: public Token {
public:
	OperatorToken(OperatorType _operator_type) :
			Token(OPERATOR), operator_type(_operator_type) {
	}
	int applyOperator(int first, int second) {
		if (operator_type == ADDOP) {
			return first + second;
		} else if (operator_type == SUBTRACTOP) {
			return second - first;
		} else if (operator_type == DIVIDEOP) {
			return second / first;
		} else if (operator_type == MULTOP) {
			return first * second;
		}
		return 0;
	}
	OperatorType operator_type;

	string toString() {
		switch (this->operator_type) {
		case ADDOP:
			return "Addition";
			break;
		case SUBTRACTOP:
			return "Subtraction";
			break;
		case DIVIDEOP:
			return "Division";
			break;
		case MULTOP:
			return "Multiplication";
			break;
		}
		return "none";
	}
	virtual ~OperatorToken() {
	}
};

#endif /* OPERATIONTOKEN_H_ */
