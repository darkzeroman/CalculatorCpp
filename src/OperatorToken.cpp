/*
 * OperationToken.cpp
 *
 *  Created on: Apr 3, 2013
 *      Author: Vidhur Vohra
 */

#include "OperatorToken.h"

OperatorToken::OperatorToken(OperatorType _operator_type) :
		Token(OPERATOR), operator_type(_operator_type) {
}

OperatorToken::~OperatorToken() {
}

int OperatorToken::apply(int first, int second) {
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

string OperatorToken::toString() {
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
