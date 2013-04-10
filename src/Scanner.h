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
	Token * getNextToken();
	vector<Token*> getTokens();
};

#endif /* SCANNER_H_ */
