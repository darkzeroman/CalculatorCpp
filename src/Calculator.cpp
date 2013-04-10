/*
 * Calculator.cpp
 *
 *  Created on: Jan 24, 2013
 *      Author: Vidhur Vohra
 */

#include "./Calculator.h"

int main() {
  Calculator calculator;
  calculator.calculate();
}

Calculator::Calculator() :
    scan() {
}

Calculator::~Calculator() {
}

void Calculator::calculate() {
  // Main loop for calculator. Builds expression and then evaluates.
  cout << "Welcome to the High Order Calculator (q to quit) " << endl;
  while (true) {
    try {
      queue<Token*> expression = buildExpression();

      if (expression.size() == 1 && expression.front()->getType() == EOL) {
        break;
      }
      evaluateExpression(expression);
    } catch (const char* msg) {
      cout << msg << endl;
    }
  }

  cout << "Quitting" << endl;
}
queue<Token*> Calculator::buildExpression() {
  vector<Token*> tokens = scan.getTokens();

  if (DEBUG) {
    cout << "printing vector tokens" << endl;
    for (unsigned int i = 0; i < tokens.size(); i++) {
      cout << tokens[i]->toString() << endl;
    }
    cout << tokens.size() << endl;
  }

  queue<Token*> output;  // Holds the expression
  stack<Token*> the_stack;

  if (tokens.size() == 1
      && (tokens[0]->getType() == EOL || tokens[0]->isNumber())) {
    output.push(tokens.front());
    return output;  // got q command, so exit
  }

  /* Shunting-yard algorithm, http://bit.ly/NDNpU
   Have named the queue and vector appropriately so
   following code follows pseudocode */
  unsigned int i = 0;

  while (i < tokens.size()) {
    if (tokens[i]->isNumber() == NUMBER) {
      output.push(tokens[i]);

    } else if (tokens[i]->isOperator()) {
      OperatorToken* o1 = static_cast<OperatorToken*>(tokens[i]);

      while (!the_stack.empty() && the_stack.top()->isOperator()
          && checkTwoCases(o1, static_cast<OperatorToken*>(the_stack.top()))) {
        output.push(the_stack.top());
        the_stack.pop();
      }
      the_stack.push(o1);

    } else {  // Got to EOL
      // moving the last remaining OPERATORS from queue to stack
      while (!the_stack.empty() && the_stack.top()->isOperator()) {
        output.push(the_stack.top());
        the_stack.pop();
      }
    }
    i++;
  }

  if (DEBUG) {
    printQueueTokens(output);
  }
  return output;
}

void Calculator::evaluateExpression(queue<Token*> output) {
  // Evaluating the expression, check the pseudocode
  stack<Token*> thestack;

  try {
    while (!output.empty()) {
      if (DEBUG) {
        cout << "output next: " << output.front()->toString() << endl;
      }

      if (output.front()->isOperator()) {
        applyOperator(&thestack, static_cast<OperatorToken*>(output.front()));
      } else {
        thestack.push(output.front());
      }
      output.pop();
    }

    if (DEBUG)
      cout << "stack size: " << thestack.size() << endl;

    if (!thestack.top()->isNumber()) {
      throw "Invalid Expression";
    }

    cout << "Result: " << thestack.top()->toString() << endl;
  } catch (const char& msg) {
    // cleaning up.
    for (unsigned int i = 0; i < output.size(); ++i) {
      Token* to_delete = output.front();
      output.pop();
      delete to_delete;
    }

    while (!thestack.empty()) {
      Token * to_delete = thestack.top();
      thestack.pop();
      delete to_delete;
    }

    throw &msg;
  }
}

void Calculator::applyOperator(stack<Token*> * the_stack, OperatorToken * OP) {
  // Apply the OperatorToken OP to the top two elements in the stack

  if (the_stack->size() < 2) {
    throw "Invalid Expression";
  }
  Token * first_token = the_stack->top();
  the_stack->pop();

  Token * second_token = the_stack->top();
  the_stack->pop();

  if (!(first_token->isNumber() && second_token->isNumber())) {
    throw "Invalid Expression";
  }
  int first_number = static_cast<NumberToken*>(first_token)->get_num();
  int second_number = static_cast<NumberToken*>(second_token)->get_num();

  int result_number = static_cast<OperatorToken*>(OP)->apply(first_number,
      second_number);

  delete first_token;
  delete second_token;

  NumberToken * result_number_token = new NumberToken(result_number);
  the_stack->push(result_number_token);
}

void Calculator::printQueueTokens(queue<Token*> output) {
  cout << "Queue size: " << output.size() << endl;
  while (!output.empty()) {
    Token * token = output.front();
    cout << "Type: " << token->getType() << " , " << token << endl;
    output.pop();
  }
}

// Everything below are methods described from the pseudocode

int Calculator::getPrecedence(OperatorToken * token) {
  if (token->getType() == OPERATOR)
    return 3;
  else
    return 2;
}

int Calculator::getAssociativity(OperatorToken * token) {
  return -1; // for now, ADDOP and MULTOP have the same associativity, so return -1
}

bool Calculator::isLeftAssociative(OperatorToken * token) {
  return (getAssociativity(token) == -1);
}

bool Calculator::lessThanOrEqualTo(OperatorToken * first,
    OperatorToken * second) {
  return getPrecedence(first) <= getPrecedence(second);
}

bool Calculator::lessThan(OperatorToken * first, OperatorToken * second) {
  return getPrecedence(first) < getPrecedence(second);
}

bool Calculator::checkTwoCases(OperatorToken * o1, OperatorToken * o2) {
  return ((isLeftAssociative(o1) && lessThanOrEqualTo(o1, o2))
      || (lessThan(o1, o2)));
}

