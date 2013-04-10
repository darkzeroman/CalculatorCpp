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

using namespace std;

class NumberToken: public Token {
public:
	NumberToken(int _num) :
			Token(NUMBER), num(_num) {
	}

	virtual ~NumberToken() {
	}

	const int get_num() {
		return num;
	}
	void set_num(int _num) {
		this->num = _num;
	}

	string toString() {
		stringstream ss;
		ss << num;
		return ss.str();
	}

private:
	int num;
};

#endif /* NUMBERTOKEN_H_ */
