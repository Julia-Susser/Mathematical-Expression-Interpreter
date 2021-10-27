#include <vector>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

class Node{
  public:
  string number;
  vector <Node> nodes;
  string theOperator;
  Node(Node aa, Node bb, string oper){
    theOperator = oper;
    nodes.push_back(aa);
    nodes.push_back(bb);
  }
  Node(Node aa, string oper){
    theOperator = oper;
    nodes.push_back(aa);
  }
  Node(string num){
    theOperator = "Number";
    number = num;
  }
  Node getA(){
    return nodes[0];
  }
  Node getB(){
    return nodes[1];
  }
  string getNumber(){
    return number;
  }
  string getOperator(){
    return theOperator;
  }
};
