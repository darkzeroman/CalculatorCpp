/*
 * Token.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Vidhur Vohra
 */

#include "Token.h"

Token::Token(Type _type) :
		type(_type) {
}
Token::~Token() {
}

Type Token::getType() const {
	return type;
}

string Token::toString() {
	return "Just Normal Token";
}

bool Token::isOperator() {
	return (type == OPERATOR);
}
