#include <vector>
#include <iostream>
#include <string.h>
#include <map>
#include "lexer.h"
using namespace std;
//g++ -std=c++11 -c lexer.cpp -o files/lexer

string Lexer::generateNumber(string newWord){
  numString = newWord[0];
  currentChar = newWord[1];
  while (isNumberType(currentChar) & (newWord.length()>0)){
    numString = numString + currentChar;
    newWord = advance(newWord);
    currentChar = newWord[1];
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
    addNewLexerValue("Multiply"," ");
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
