/*
 * NumberToken.cpp
 *
 *  Created on: Apr 3, 2013
 *      Author: Vidhur Vohra
 */

#include "NumberToken.h"

NumberToken::NumberToken(int _num) :
  Token(NUMBER), num(_num) {
}

NumberToken::~NumberToken() {
}

const int NumberToken::get_num() {
 return num;
}
void NumberToken::set_num(int _num) {
 this->num = _num;
}

string NumberToken::toString() {
 stringstream ss;
 ss << num;
 return ss.str();
}

