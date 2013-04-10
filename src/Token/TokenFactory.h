/*
 * TokenFactory.h
 *
 *  Created on: Apr 8, 2013
 *      Author: Vidhur Vohra
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
   if (input_char == ASTERISK_ASCII) {
    return new OperatorToken(MULTOP);
   } else if (input_char == FORWARD_SLASH_ASCII) {
    return new OperatorToken(DIVIDEOP);
   } else if (input_char == PLUS_ASCII) {
    return new OperatorToken(ADDOP);
   } else if (input_char == MINUS_ASCII) {
    return new OperatorToken(SUBTRACTOP);
   } else if (input_char == NEW_LINE_ASCII || input_char == Q_ASCII) {
    return new EOLToken();
   } else {
    throw "Invalid Character";
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
