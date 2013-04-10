/*
 * Token.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Vidhur Vohra
 */

#include "./Token.h"

Token::Token(TokenType _type) :
  type(_type) {
}
Token::~Token() {
}

TokenType Token::getType() const {
 return type;
}

string Token::toString() {
 return "Just Normal Token";
}

bool Token::isOperator() {
 return (type == OPERATOR);
}

bool Token::isNumber() {
 return (type == NUMBER);
}

