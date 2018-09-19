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

/*int execute(elements *e) {

	string inst;
	int p;
	map<string, string>::iterator it;
	// it = e->memory.end();
	// it--;
	e->pc = e->start;
	for(it = (e->memory).begin();it != (e->memory).end();it++) {

		inst = "";
		p = (it->second).find(' ');
		if(p == -1)
			inst = it->second;
		else
			for(int i=0;i<p;i++)
				inst += (it->second)[i];
		if(inst == "MOV")
			mov(e);
		else if(inst == "XCHG")
			xchg(e);
		else if(inst == "ADD")
			addSub(e);
		else if(inst == "SUB")
			addSub(e);
		else if(inst == "INR")
			inrDcr(e);
		else if(inst == "DCR")
			inrDcr(e);
		else if(inst == "INX")
			inxDcx(e);
		else if(inst == "DCX")
			inxDcx(e);
		else if(inst == "DAD")
			dad(e);
		else if(inst == "CMA")
			cma(e);
		else if(inst == "CMP")
			cmp(e);
		else if(inst == "MVI")
			mvi(e);
		else if(inst == "LXI")
			lxi(e);
		else if(inst == "ADI")
			adiSui(e);
		else if(inst == "SUI")
			adiSui(e);
		else if(inst == "JMP")
			jmp(e);
		else if(inst == "JC")
			jc(e);
		else if(inst == "JNC")
			jnc(e);
		else if(inst == "JZ")
			jz(e);
		else if(inst == "JNZ")
			jnz(e);
		else if(inst == "LDA")
			lda(e);
		else if(inst == "STA")
			sta(e);
		else if(inst == "LHLD")
			lhld(e);
		else if(inst == "SHLD")
			shld(e);
		else if(inst == "SET")
			sett(e);
		else if(inst == "HLT")
			return 0;
		if(!(inst == "JMP" || inst == "JC" || inst == "JNC" || inst == "JZ" || inst == "JNZ")) {

			updatePc(e);
		}
	} 
	return 0;
}*/



int execute(elements *e) {

	string inst, str;
	int p;
	map<string, string>::iterator it;
	it = e->memory.end();
	it--;
	e->pc = e->start;
	// for(it = (e->memory).begin();it != (e->memory).end();it++) {
	while(e->pc != it->first) {

		str = e->memory[e->pc];
		inst = "";
		p = str.find(' ');
		if(p == -1)
			inst = str;
		else
			for(int i=0;i<p;i++)
				inst += str[i];
		if(inst == "MOV")
			mov(e);
		else if(inst == "XCHG")
			xchg(e);
		else if(inst == "ADD")
			addSub(e);
		else if(inst == "SUB")
			addSub(e);
		else if(inst == "INR")
			inrDcr(e);
		else if(inst == "DCR")
			inrDcr(e);
		else if(inst == "INX")
			inxDcx(e);
		else if(inst == "DCX")
			inxDcx(e);
		else if(inst == "DAD")
			dad(e);
		else if(inst == "CMA")
			cma(e);
		else if(inst == "CMP")
			cmp(e);
		else if(inst == "MVI")
			mvi(e);
		else if(inst == "LXI")
			lxi(e);
		else if(inst == "ADI")
			adiSui(e);
		else if(inst == "SUI")
			adiSui(e);
		else if(inst == "JMP")
			jmp(e);
		else if(inst == "JC")
			jc(e);
		else if(inst == "JNC")
			jnc(e);
		else if(inst == "JZ")
			jz(e);
		else if(inst == "JNZ")
			jnz(e);
		else if(inst == "LDA")
			lda(e);
		else if(inst == "STA")
			sta(e);
		else if(inst == "LHLD")
			lhld(e);
		else if(inst == "SHLD")
			shld(e);
		else if(inst == "SET")
			sett(e);
		else if(inst == "HLT")
			return 0;
		if(!(inst == "JMP" || inst == "JC" || inst == "JNC" || inst == "JZ" || inst == "JNZ")) {

			updatePc(e);
		}
	} 
	return 0;
}





/*int main() {

	elements e;
	e.memory["2000"] = "MOV A,B";
  	e.memory["2001"] = "LDA 2050";
  	e.memory["2004"] = "JMP 2001";
  	e.memory["2007"] = "HLT";
  	for(i=0;i<8;i++)
    	(e.flags)[i] = 0;
    for(i=0;i<7;i++)
    	(e.registers)[i] = "NULL";
}*/
