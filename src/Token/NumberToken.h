/*
 * NumberToken.h
 *
 *  Created on: Apr 3, 2013
 *      Author: Vidhur Vohra
 */

#ifndef NUMBERTOKEN_H_
#define NUMBERTOKEN_H_

#include <iostream>
#include <istream>

#include "Token.h"

class NumberToken: public Token {
 public:
  NumberToken(int _num);
  virtual ~NumberToken();
  const int get_num();
  void set_num(int _num);
  string toString();

 private:
  int num;
};

#endif /* NUMBERTOKEN_H_ */
