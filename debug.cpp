#include "headers.h"
#include "methods.h"
#include <algorithm>

void execDebug(elements *e)
{
	//	cout<<"***INEXEC**\n";
	string inst="";
	int p;
	//map<string, string>::iterator it;
	//e->pc = e->start;
	inst = e->memory[e->pc ];
	string cmd;
	stringstream ss(inst);
	ss >> inst;
//	p = (it->second).find(' ');
//	for(int i=0;i<p;i++)
//		inst += (it->second)[i];
//	//cout<<inst<<"111"<<endl;
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
			return;
		
	updatePc(e);
	//cout<<"***OUTEXEC**\n";

}
int debug(elements *e)
{
	e->pc = e->start;
	cout<<"DEBUGGER MODE ON :\ntype \"help\" for help\n\n";
	map<int, int > breakPt;
	int line=0,end=0;
	// cin.ignore();
	int i;
	while(i < 10)
	{
		// cin.ignore();
		i++;
		string input,cmd;
		int lineNo;
		cout<<"debug:";
		fflush(stdin);
		getline(cin,input);
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		//2cout<<input<<"***inp****\n";
		stringstream inputstream(input);
		//getline(inputstream,cmd);
		inputstream >> cmd;
		cout << cmd<<endl;
		//cout<<cmd<<"****";
		if(cmd == "B" ||cmd == "b")
		{
			//string lno;
			//getline(inputstream, lno);
			int lineNo;
			inputstream >> lineNo; 
			//cout<<lineNo <<"***lineNo****\n";
			breakPt[lineNo]=1;
			
		}
		else if(cmd == "R"||cmd == "r")
		{
			while(end==0 && breakPt.find(line) == breakPt.end() )
			{
				cout<<e->memory[e->pc ]<<endl;
				
				if(e->memory[e->pc ]=="HLT"){
					line++;
					end=1;
					break;
				}
				execDebug(e);
				line++;
			}
		}
		else if(cmd == "S"||cmd == "s")
		{
		//	cout<<"***IN S**\n";
			if(end == 0)
			{
				cout<<e->memory[e->pc ]<<endl;
				if(e->memory[e->pc ] == "HLT")
				{
					end=1;
					//cout<<"HLT\n";
				}
				execDebug(e);
				line++;
				
			}
			else
				cout<<"THATS ALL FOLKS\n";

		}
		else if(cmd == "P"||cmd == "p")
		{
			string arg;
			//getline(inputstream, arg);
			inputstream.ignore() ;
			inputstream >>arg;
			//cout<<arg<<"***pArg****\n";
			if(arg[0] == 'A'||arg[0] == 'B'||arg[0] == 'C'||arg[0] == 'D'||arg[0] == 'E'||arg[0] == 'H'||arg[0] == 'L')
			{
				cout<<"register "<<arg[0]<<":"<<e->registers[arg[0]-'A']<<endl;
			}
			else if(arg[0]== 'x'||arg[0]== 'X')
			{
				arg = arg.substr(1);
				cout<<"memory "<<arg<<":"<<e->memory[arg]<<endl;
				
			}
		}
		else if(cmd == "Q"||cmd == "q")
		{
			return 0;
		}
		else if(cmd == "HELP"||cmd == "help")
		{
			cout<<"1. break or b `line no`:- It will set break point on given line number.\n2. run or r :- Run the program until it ends or breakpoint is encountered.\n3. step or s :- It will run the program one instruction at a time.\n4. print or p:- It prints the value of register or memory location. for ex p A will print the value ofregister A. p x2500 will print the value at memory location x2500 if any.\n5. quit or q:- quits the debugger.\n6. help:- will show all the commands of debugger."<<endl;
		}
		else
			cout<<"*invalid*\n";
			
		
	}
	
	return 0;
}
