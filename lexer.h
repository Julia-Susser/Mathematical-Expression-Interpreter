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
      //Print();
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
