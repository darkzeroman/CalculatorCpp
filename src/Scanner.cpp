/*
 * Scanner.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Vidhur Vohra
 */

#include "Scanner.h"

Scanner::~Scanner() {

}

Token * Scanner::getNextToken() {
	string str = "";

	while (cin.peek() == SPACE) // disregarding spaces
		cin.get();
	if (cin.peek() >= NUMBERS_ASCII) {
		int num;
		cin >> num;
		stringstream ss;
		ss << num;
		return TokenFactory::makeNumberToken(num);
	} else {
		return TokenFactory::makeToken(cin.get());
	}

}

vector<Token*> Scanner::getTokens() {
	vector<Token*> tokens;

	while (true) {
		Token * token = getNextToken();
		tokens.push_back(token);
		if (token->getType() == EOL)
			break;
	}
	return tokens;

}

