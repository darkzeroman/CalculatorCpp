/*
 * TokenFactory.h
 *
 *  Created on: Apr 8, 2013
 *      Author: darkzeroman
 */

#ifndef TOKENFACTORY_H_
#define TOKENFACTORY_H_

#include "Token.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "EOLToken.h"

class TokenFactory {
public:
	static Token * makeToken(char input_char) {
		if (input_char == MULT) {
			return new OperatorToken(MULTOP);
		} else if (input_char == DIVIDE) {
			return new OperatorToken(DIVIDEOP);
		} else if (input_char == ADD) {
			return new OperatorToken(ADDOP);
		} else if (input_char == SUBTRACT) {
			return new OperatorToken(SUBTRACTOP);
		} else if (input_char == EOLMARKER || input_char == EOL2) {
			return new EOLToken();
		} else {
			return new EOLToken();
		}
	}
	static Token * makeNumberToken(int num) {
		return new NumberToken(num);
	}

private:
	TokenFactory();
	virtual ~TokenFactory();
};

#endif /* TOKENFACTORY_H_ */
