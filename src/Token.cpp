/*
 * Token.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Vidhur Vohra
 */

#include "Token.h"

Token::~Token() {
}

string Token::toString() {
	return "Token";
}

Type Token::getType() const {
	return type;
}

Token::Token(Type _type) :
		type(_type) {
}

