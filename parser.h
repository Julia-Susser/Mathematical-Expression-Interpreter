#include <vector>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
#include "Node.h"

class Parser{
  public:
  vector <vector<string> > lexer;
  string currentType;
  string currentVal;
  int currentIndx;
  //Node* final;
  Parser(vector <vector<string> > lex){
    lexer = lex;
    Node tree = createTree();
    //final = &tree;
    //cout << "here" << final->getA().number << endl;
    getFinal();
  }

  Node getFinal(){
    return createTree();
  }
  void next(){
    if (currentIndx < lexer.size()){
      currentType = lexer[currentIndx][0];
      currentVal = lexer[currentIndx][1];
      currentIndx = currentIndx + 1;
    }
  }
  Node createTree(){
    currentIndx = 0;
    next();
    Node final = subtract_add();
    //cout << final.getA().getOperator() << endl;
    return final;
  }
  Node subtract_add();
  Node multiply_divide();
  Node number();

};
