#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#include "lexer.h"
#include "parser.h"
//g++ -std=c++11 -c interpreter.cpp -o files/interpreter
//g++ files/parser files/lexer files/interpreter

class Interpreter{
  public:
    Node * parser;
    float final;
    Interpreter(Node p){
      parser = &p;
      final = runInterpreter(*parser);
    }

    float runInterpreter(Node pars){
      if (pars.getOperator()=="Number"){
        float value = stoi(pars.getNumber());
        return value;

      }
      else if (pars.getOperator()=="Plus"){
        return runInterpreter(pars.getA());
      }
      else if (pars.getOperator()=="Negative"){
        return -1*runInterpreter(pars.getA());
      }
      else if (pars.getOperator()=="Add"){
        return runInterpreter(pars.getA())+runInterpreter(pars.getB());
      }
      else if (pars.getOperator()=="Subtract"){
        return runInterpreter(pars.getA())-runInterpreter(pars.getB());
      }
      else if (pars.getOperator()=="Multiply"){
        return runInterpreter(pars.getA())*runInterpreter(pars.getB());
      }
      else if (pars.getOperator()=="Divide"){
        return runInterpreter(pars.getA())/runInterpreter(pars.getB());
      }
    }


};

int main(){
  string expression = "(78/8+10)+10*3+(2+3)";
  cin >> expression;
  cout << "Solving " << expression << "......" << endl;
  Lexer lexer(expression);
  vector <vector<string>> lexerTable = lexer.table;
  Parser parser(lexerTable);
  Node parserNode = parser.getFinal();
  Interpreter interpreter(parserNode);
  cout << interpreter.final << endl;
}
