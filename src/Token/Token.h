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

enum TokenType {
  OPERATOR, NUMBER, EOL
};

const int ASTERISK_ASCII = 42;
const int PLUS_ASCII = 43;
const int MINUS_ASCII = 45;
const int FORWARD_SLASH_ASCII = 47;
const int NEW_LINE_ASCII = 10;
const int SPACE_ASCII = 32;
const int Q_ASCII = 113;
const int NUMBERS_ASCII_MIN = 48;
const int NUMBERS_ASCII_MAX = 57;

using namespace std;

class Token {
public:
  virtual ~Token();
  TokenType getType() const;
  virtual string toString();
  bool isOperator();
  bool isNumber();

protected:
  Token(TokenType _type);
private:
  TokenType type;
};

#endif /* TOKEN_H_ */
