


make: lex pars int
	echo "Making...."
	g++ files/parser files/lexer files/interpreter

int:
	@echo "Creating Int..."
	g++ -std=c++11 -c interpreter.cpp -o files/interpreter

pars:
	@echo "Creating Pars..."
	g++ -std=c++11 -c parser.cpp -o files/parser

lex:
	@echo "Creating Lex..."
	g++ -std=c++11 -c lexer.cpp -o files/lexer


run: int
	g++ files/parser files/lexer files/interpreter
