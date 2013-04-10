/*
 * Token.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Vidhur Vohra
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>
#include <istream>
#include <string>
#include <sstream>

using std::string;

enum Type {
	OPERATOR, NUMBER, EOL
};

const int ASTERISK_ASCII = 42;
const int PLUS_ASCII = 43;
const int SUBTRACT = 45;
const int DIVIDE = 47;
const int EOLMARKER = 10;
const int SPACE = 32;
const int EOL2 = 113;
const int NUMBERS_ASCII = 48;
//const int NUMBERS_ASCII_MAX = 57;

using namespace std;

class NumberToken;
class OperatorToken;

class Token {
public:
	virtual string toString();
	virtual ~Token();
	Type getType() const;
	bool isOperator();
protected:
	Token(Type _type);
private:
	Type type;

};

#endif /* TOKEN_H_ */
