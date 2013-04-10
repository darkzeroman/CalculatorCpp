Vidhur Vohra

Background:

I am an experienced software developer who is taking a class on C++. The idea for this project was a homework which I have added to.

I am also learning about standard naming conventions. Currently the naming convention is camel casing for methods and undercase with underscore for variable names.

This is a simple calculator that accepts Numbers and Add/Multiplication/Subtract/Division.

Expressions are evaluated by the shunting yard algorithm, which converts infix expressions to postfix expressions. Pseudocode: http://bit.ly/NDNpU

Includes the classes:

Calculator: Main class which calls the scanner to build and evaluate an expression.
Scanner: Reads from stdin and creates tokens.
Token: Base class for NumberToken, OperatorToken, EOLToken
TokenFactory: has static methods which creates the appropriate type of tokens

Catches invalid expressions that use either incorrect characters (such as =) or things such as 2++.

Further improvements this project can have:
- Use exception classes instead of just throwing strings
- Implement support for parenthesis
- Replace toString() with insertion operator (<<)