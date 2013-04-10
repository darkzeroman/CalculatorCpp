/*
 * EOLToken.h
 *
 *  Created on: Apr 3, 2013
 *      Author: darkzeroman
 */

#ifndef EOLTOKEN_H_
#define EOLTOKEN_H_

#include "Token.h"

class EOLToken: public Token {
public:
	EOLToken();
	virtual ~EOLToken();
	string toString();
};

#endif /* EOLTOKEN_H_ */
