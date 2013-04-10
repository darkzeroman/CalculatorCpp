/*
 * Scanner.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Vidhur Vohra
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#include "TokenFactory.h"

using namespace std;

class Scanner {

public:
	Scanner();
	virtual ~Scanner();
	// Returns a vector of token pointers, represents one line
	vector<Token*> getTokens();
private:
	Token * getNextToken();
};

#endif /* SCANNER_H_ */
