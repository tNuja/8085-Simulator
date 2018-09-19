#include "headers.h"
#include "methods.h"

/*#include<bits/stdc++.h>

using namespace std;

struct elements {

  string pc;
  string start;
  string registers[7];
  map<string, string> memory;
  int flags[8];
};*/

int jmp(elements *e) {

  map<string,  string> :: iterator it;
  string inst = e->memory[e->pc];
  string address = "";
  int i;
  int p = inst.find(' ');
  for(i = p+1;i<inst.length();i++) {

    address += inst[i];
  }
  if(e->memory.find(address) != e->memory.end())
    e->pc = address;
  else
    updatePc(e);
  return 0;
}

/*int main() {

  elements e;
  e.memory["2000"] = "MOV A,B";
  e.memory["2001"] = "LDA 2050";
  e.memory["2004"] = "JMP 2007";
  e.memory["2007"] = "HLT";
  e.pc = "2004";
  if(jmp(&e))
    cout << e.pc << " " << e.memory[e.pc] << endl;
  else
    cout << "Invalid address" << endl;
  return 0;
}*/
