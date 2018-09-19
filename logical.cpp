#include <bits/stdc++.h>
#include "headers.h"
#include "methods.h"

// using namespace std;


// struct elements
// {
//     string pc,start,registers[7];
//     map<string , string> memory;
//     int flags[8];
    
// };

bool* ToBin(string Hex)
{
  bool *Ar = new bool[8];
  int i=0; string data="";
	
	if(Hex.length()==1)
		data.append("0000");
		
	while(i<Hex.length())
	{
		switch(Hex[i++])
	    {
	        case '0': data.append("0000");break;
	        case '1': data.append("0001");break;
	        case '2': data.append("0010");break;
	        case '3': data.append("0011");break;
	        case '4': data.append("0100");break;
	        case '5': data.append("0101");break;
	        case '6': data.append("0110");break;
	        case '7': data.append("0111");break;
	        case '8': data.append("1000");break;
	        case '9': data.append("1001");break;
	        case 'A':
	        case 'a': data.append("1010");break;
	        case 'B':
	        case 'b': data.append("1011");break;
	        case 'C':
	        case 'c': data.append("1100");break;
	        case 'D':
	        case 'd': data.append("1101");break;
	        case 'E':
	        case 'e': data.append("1110");break;
	        case 'F':
	        case 'f': data.append("1111");break;
	    }
	}
	for(i=0;i<8;i++)
		Ar[i]=(data[i]=='0'?0:1);
  return Ar;
}
string ToHex(bool* Ar)
{

  string T; int i=7,temp,k=2,j=0; char hexa[3];
    while(k--){
    temp =  Ar[i-3] *8 + Ar[i-2] *4 +  Ar[i-1] *2 + Ar[i] ;
                if(temp > 9)
                        hexa[j++] = temp + 55;
                else
                        hexa[j++] = temp + 48;
                i=i-4;
		}
		hexa[2]='\0';
		T=hexa;
		reverse(T.begin(),T.end());
  return T;
}
int ToDec(string HexVal)
{
  int i=0,Res=0;
  int l=HexVal.length();
  while(i<l)
  {
    if((HexVal[i]>=48)&&(HexVal[i]<=57))
       Res=(Res*16)+(HexVal[i]-48);
    else if((HexVal[i]>=65)&&(HexVal[i]<=70))
       Res=(Res*16)+(HexVal[i]-55);
    else return -1;
    i++;
  }
  return Res;
}

int cma(elements *e)
{
	string inst = e->memory[e->pc];
	transform(inst.begin(), inst.end(), inst.begin(), ::tolower);
	bool *Ar;
	if(inst!="cma")
	return 0;
	
	Ar=ToBin(e->registers[0]);
	for(int i=0;i<8;i++)
		Ar[i]=!Ar[i];
	
	e->registers[0]=ToHex(Ar);
	return 1;
}

int cmp(elements *e)
{
	string inst = e->memory[e->pc];
    string r,x,memo="",data;
	int a,b;
	 stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    if(x!="cmp")
    return 0;
    
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    if(!(r[0]=='a'||r[0]=='b'||r[0]=='c'||r[0]=='d'||r[0]=='e'||r[0]=='h'||r[0]=='l'||r[0]=='m'))
	return 0;
	
    int rdd;
    switch(r[0])
	{
		
		case 'a':rdd=0;break;
		case 'b':rdd=1;break;
		case 'c':rdd=2;break;
		case 'd':rdd=3;break;
		case 'e':rdd=4;break;
		case 'h':rdd=5;break;
		case 'l':rdd=6;break;
		case 'm':break;
		default : return 0;
	}
	if(r[0]=='m' || r[0]=='M')
	{
        memo.append(e->registers[5]);
        memo.append(e->registers[6]);
        data=e->memory[memo];
	}
	else
		data=e->registers[rdd];
		
	b=ToDec(data);
	a=ToDec(e->registers[0]);
	
	if(a>b)
		e->flags[0]=0;
		
	else if(a<b)
		e->flags[0]=1;
		
	else if(a==b)
		e->flags[6]=1;
		
	return 1;
}

// int main()
// {
//     elements e;
//     e.pc="2000";
//     e.registers[1]="FF";
//     e.registers[0]="FE";
//     e.memory["2000"]="cmp b";
//     for(int i=7;i>=0;i--)
//     e.flags[i]=0;
//     cmp(&e);
//     //cout<<e.registers[0]<<endl;
    
//     cout<<"S Z X AC X P X CY"<<endl;
//     for(int i=7;i>=0;i--)
//     cout<<e.flags[i]<<" ";
//     return 0;

// }   
