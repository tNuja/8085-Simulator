/*#include<bits/stdc++.h>

using namespace std;

struct elements {

  string pc;
  string start;
  string registers[7];
  map<string, string> memory;
  int flags[8];
};*/
#include "headers.h"

#include "methods.h"

int jc(elements *e) {

  map<string,  string> :: iterator it = e->memory.begin();
  string inst = e->memory[e->pc];
  string address = "", instAdd = e->pc;
  int i;
  int p = inst.find(' ');
  for(i = p+1;i<inst.length();i++) {

    address += inst[i];
  }
  if(e->memory.find(address) != e->memory.end()) {

    if(e->flags[0] == 1)
      e->pc = address;
    else {

      updatePc(e);
      // while(it->first != instAdd) {

      //   it++;
      // }
      // it++;
      // e->pc = it->first;
    }
    return 1;
  }
  else
    return 0;
}

/*int main() {

  elements e;
  e.memory["2000"] = "MOV A,B";
  e.memory["2001"] = "LDA 2050";
  e.memory["2004"] = "JMP 2001";
  e.memory["2007"] = "HLT";
  e.pc = "2004";
  e.flags[7] = 0;
  if(jc(&e))
    cout << e.pc << " " << e.memory[e.pc] << endl;
  else
    cout << "Invalid address" << endl;
  return 0;
}*/
