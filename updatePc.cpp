#include "headers.h"
#include "methods.h"

// #include<bits/stdc++.h>
// using namespace std;
// struct elements {

// 	string pc;
// 	string start;
// 	string registers[7];
// 	map<string, string> memory;
// 	int flags[8];
// };

int convert2int(char ch) {

	static bool isFirst = true;
  	static std::map<char,int> lookup;
  	if(isFirst) {
		for(int i=0;i<16;++i)
	  		lookup["0123456789ABCDEF"[i]] = i;
	  	isFirst = false;
  	}
  	return lookup[std::toupper(ch)];
}

char convert2char(int digi) {

  	static bool isFirst = true;
  	static std::map<int,char> lookup;
  	if(isFirst) {
		for(int i=0;i<16;++i)
	  		lookup[i] = "0123456789ABCDEF"[i];
	  	isFirst = false;
  	}
  	return lookup[digi];
}

string addPc(string hex1,string hex2) {
	int carry = 0;
  	string sum = "";
  	for(int i=0 ; i<hex1.length() ; ++i)
		sum += " ";
  	for(int i=hex1.length()-1 ; i>=0 ; --i) {
		int tmp = convert2int(hex1[i])+convert2int(hex2[i])+carry;
		if(tmp < 16)
			carry = 0;
		else {
	  		carry = 1;
	  		tmp -= 16;
		}
		sum[i] = convert2char(tmp);
  	}
  	return sum;
}

int instSize(string str) {

	int i, pos;
	string temp = "";
	string one[] = {"MOV", "XCHG", "ADD", "SUB", "INR", "DCR", "INX", "DCX", "DAD", "CMA", "CMP", "HLT"};
	string two[] = {"MVI", "LXI", "ADI", "SUI"};
	string three[] = {"JMP", "JC", "JNC", "JZ", "JNZ", "LDA", "STA", "LHLD", "SHLD"};
	string four[] = {"SET"};
	pos = str.find(' ');
	if(pos == -1)
		temp = str;
	else
		for(i=0;i<pos;i++)
	 		 temp += str[i];
	for(i=0;i<12;i++) {

		if(temp == one[i])
			return 1;
	}
	for(i=0;i<4;i++) {

		if(temp == two[i])
			return 2;
	}
	for(i=0;i<9;i++) {

		if(temp == three[i])
			return 3;
	}
	if(temp == four[0])
		return 4;
	return -1;
}


int updatePc(elements *e) {

	int size;
	string str;
	size = instSize(e->memory[e->pc]);
	if(size == 1)
		str = "0001";
	else if(size == 2)
		str = "0002";
	else if(size == 3)
		str = "0003";
	else if(size == 4)
		str = "0004";
	e->pc = addPc(e->pc, str);
	return 0;
}

// int main() {
  
//   elements e;
//   e.memory["2000"] = "MOV A,B";
//   e.memory["2001"] = "XCHG";
//   e.memory["2002"] = "JMP 2001";
//   e.memory["2007"] = "HLT";
//   e.memory["2008"] = "LDA 2050";
//   e.pc = "2000";
//   cout << e.pc << endl;
//   updatePc(&e);
//   cout << e.pc << endl;
//   updatePc(&e);
//   cout << e.pc << endl;
//   updatePc(&e);
//   cout << e.pc << endl;
//   updatePc(&e);
//   cout << e.pc << endl;
//   return 0;
// }
