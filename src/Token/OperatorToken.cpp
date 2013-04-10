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
	switch (operator_type) {
	case ADDOP:
		return first + second;
		break;
	case SUBTRACTOP:
		return second - first;
		break;
	case DIVIDEOP:
		return second / first;
		break;
	case MULTOP:
		return first * second;
		break;
	}
	return 0;
}

string OperatorToken::toString() {
	switch (operator_type) {
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
