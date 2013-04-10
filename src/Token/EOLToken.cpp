/*
 * EOLToken.cpp
 *
 *  Created on: Apr 3, 2013
 *      Author: Vidhur Vohra
 */

#include "EOLToken.h"

EOLToken::EOLToken() :
  Token(EOL) {
}

EOLToken::~EOLToken() {
}

string EOLToken::toString() {
 return "EOL";
}

