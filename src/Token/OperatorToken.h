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
	OperatorToken(OperatorType _operator_type);
	int apply(int first, int second);
	string toString();
	virtual ~OperatorToken();
private:
	OperatorType operator_type;
};

#endif /* OPERATIONTOKEN_H_ */
