Vidhur Vohra

Background:

I've only started to take a class to learn C++ this semester, so this might not follow all conventions. 

This is a simple calculator that accepts Numbers and Add/Multiplication/Subtract/Division.

Random Notes:
- Numbers should be weithin the int range.
- Used Google's cpplint and cppchecker.
- Naming convention is camel casing for methods and undercase with underscore for variable names.
- Expressions are evaluated by the shunting yard algorithm, which converts infix expressions to postfix expressions. 
	Pseudocode: http://bit.ly/NDNpU
- Catches invalid expressions that use either incorrect characters (such as =) or invalid expressions such as 2++.

Includes the classes:
- Calculator: Main class which calls the scanner to build and evaluate an expression of tokens.
- Scanner: Reads from stdin and creates tokens.
- Token: Base class for NumberToken, OperatorToken, EOLToken
- TokenFactory: has static methods which creates the appropriate type of tokens

Further improvements this project can have:
- Use exception classes instead of just throwing strings
- Implement support for parenthesis
- Replace toString() with insertion operator (<<)
- Actually do unit testing, I just started to learn them for C++
- Start to use C++11, so unique_ptr can be used

Test Cases (copy/paste)
2+3
4-3
10*3
9/3
1+1+1+1
2*3/2+1
1
+
10++
+++10
q
