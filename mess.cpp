# include <iostream>
# include <vector>
#include <string.h>

using namespace std;


class Node{
  public:
  Node* a;
  string number;
  Node(Node aa, Node bb, string oper){
    string theOperator = oper;
    *a = aa;
    Node b = bb;
  }
  Node(Node aa, string oper){
    string theOperator = oper;
    Node a = aa;
  }
  Node(string num){
    number = num;
  }
  Node getFinal(){
    return *a;
  }

};

int main(){

  int i =5;
  int * t = &i;
  t = &i;
  *t = i;
  i = 3;
  cout << *t << i << endl;
  //int& ref = x;

  Node* k;
  Node obj("5");
  k = &obj;
  Node c = *k;
  cout << c.number;
  cout << k->number;
  int l = 5;
  //cout << k->Volume() ;

}
