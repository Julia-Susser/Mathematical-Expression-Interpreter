#include <vector>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

#include "parser.h"
#include "lexer.h"
//I can get a class inside a class when I to main. for ex. I can get the operator but not the number in B from main.
//g++ -std=c++11 -c parser.cpp -o files/parser
//g++ files/parser files/lexer
Node Parser::subtract_add(){
  Node result = multiply_divide();
  while (currentType=="Plus" | currentType=="Negative"){
    if (currentType=="Plus"){
      next();
      result = Node(result, multiply_divide(),"Add");
    }
    if (currentType=="Negative"){
      next();
      result = Node(result, multiply_divide(),"Subtract");
    }

  }
  return result;
}

Node Parser::multiply_divide(){
  Node result = number();
  while ((currentType=="Multiply" | currentType=="Divide")){
    if (currentType=="Multiply"){
      next();
      result = Node(result, number(),"Multiply");
    }
    if (currentType=="Divide"){
      next();
      result = Node(result, number(),"Divide");
    }

  }
  return result;
}
Node Parser::number(){
  if (currentType=="LParen"){
    next();
    Node result = subtract_add();
    if (currentType != "RParen"){
      cout << "ERROR";
    }
    next();
    return result;
  }
  if (currentType=="Number"){
    Node result(currentVal);
    next();
    return result;
  }
  if (currentType=="Plus"){
    next();
    Node result = number();
    return Node(result,"+");
  }
  if (currentType=="Negative"){
    next();
    Node result = number();
    return Node(result,"-");
  }
}


// int main(){
//   Lexer lexer("10+10/2");
//   vector <vector<string>> lexerTable = lexer.table;
//   cout << "\n\n\n";
//   Parser parser(lexerTable);
//   Node parserNode = parser.getFinal();
//
// }
