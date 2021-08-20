#include <vector>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
class Lexer{
  public:
  string input;
  char currentChar;
  bool contained;
  string numString;
  vector <vector<string> > table;

  const char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};
  Lexer(string word){
    input = word;
    bool finished = createLexer(input);
    if (finished){
      Print();
    }else{
      cout << "ERROR";
    }

  }
  bool createLexer(string newWord);
  string generateNumber(string newWord);

  bool isNumberType(char currentChar){
    contained = memchr(digits, currentChar, sizeof(digits));
    return (currentChar == '.') | (contained);
  }
  void Print(){
    for (int i=0; i<table.size();i++){
      cout << table[i][0] << " " << table[i][1] << endl;
    }
  }

  string advance(string newWord){
    return newWord.substr(1, newWord.length());
  }
  void addNewLexerValue(string Type, string Value){
    vector<string> row = {Type,Value};
    table.push_back(row);
  }

};

string Lexer::generateNumber(string newWord){
  numString = newWord[0];
  currentChar = newWord[1];
  while (isNumberType(currentChar) & (newWord.length()>0)){
    numString = numString + currentChar;
    newWord = advance(newWord);
    currentChar = newWord[0];
  }
  addNewLexerValue("Number",numString);
  return newWord;
}

bool Lexer::createLexer(string newWord){
  if (newWord.length()==0){ return true; }
  currentChar = newWord[0];
  if (isNumberType(currentChar)){
    newWord = generateNumber(newWord);
  }else if (currentChar=='+'){
    addNewLexerValue("Plus"," ");
  }else if (currentChar=='-'){
    addNewLexerValue("Negative"," ");
  }else if (currentChar=='*'){
    addNewLexerValue("Negative"," ");
  }else if (currentChar=='/'){
    addNewLexerValue("Divide"," ");
  }else if (currentChar=='('){
    addNewLexerValue("LParen"," ");
  }else if (currentChar==')'){
    addNewLexerValue("RParen"," ");
  }else{
    return false;
  }
  newWord = advance(newWord);
  return createLexer(newWord);

}

class Node{
  public:
  Node(Node aa, Node bb, string oper){
    string theOperator = oper;
    Node a = aa;
    Node b = bb;
  }
  Node(Node aa, string oper){
    string theOperator = oper;
    Node a = aa;
  }
  Node(string num){
    string number = num;
  }

};

class Parser{
  public:
  vector <vector<string> > lexer;
  string currentType;
  string currentVal;
  int currentIndx;

  Parser(vector <vector<string> > lex){
    lexer = lex;
    currentIndx = 0;
  }
  void next(){
    currentType = lexer[currentIndx][0];
    currentVal = lexer[currentIndx][1];
    currentIndx = currentIndx + 1;
  }
  Node createTree(){
    return subtract_add();
  }
  Node subtract_add(){
    Node result = multiply_divide();

    while (currentType=="Plus" | currentType=="Negative"){
      if (currentType=="Plus"){
        result = Node(result, number(),"Add");
      }
      if (currentType=="Negative"){
        result = Node(result, number(),"Subtract");
      }
      next();
    }
    return result;
  }
  Node multiply_divide(){
    Node result = number();

    while ((currentType=="Multiply" | currentType=="Divide")){
      if (currentType=="Multiply"){
        result = Node(result, number(),"Multiply");
      }
      if (currentType=="Divide"){
        result = Node(result, number(),"Divide");
      }
      next();
    }
    return result;
  }
  Node number(){
    if (currentType=="LParent"){
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
      Node result = number();
      next();
      return Node(result,"+");
    }
    if (currentType=="Negative"){
      Node result = number();
      next();
      return Node(result,"-");
    }

  }

};

int main(){
  cout << "hey";
  

}
