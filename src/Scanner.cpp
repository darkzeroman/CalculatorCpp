/*
 * Scanner.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Vidhur Vohra
 */

#include "Scanner.h"

Scanner::Scanner() {

}
Scanner::~Scanner() {

}

Token * Scanner::getNextToken() {
	while (cin.peek() == SPACE_ASCII) // disregarding spaces
		cin.get();

	if (cin.peek() >= NUMBERS_ASCII_MIN && cin.peek() <= NUMBERS_ASCII_MAX) {
		// converting to integer
		int num;
		cin >> num;
		stringstream ss;
		ss << num;
		return TokenFactory::makeNumberToken(num);
	} else {
		// Handles EOL and Operators
		return TokenFactory::makeToken(cin.get());
	}
}

vector<Token*> Scanner::getTokens() {
	vector<Token*> tokens;

	/* If there is an invalid character, continue reading the line and if this is set
	 after reading the line, throw a message regarding invalid character */
	bool is_invalid = false;

	while (true) {
		try {
			Token * token = getNextToken();
			tokens.push_back(token);
			if (token->getType() == EOL)
				break;
		} catch (const char* msg) {
			is_invalid = true;
		}
	}

	if (is_invalid) {
		throw "Invalid Character Present in this Line";
	}
	return tokens;
}

