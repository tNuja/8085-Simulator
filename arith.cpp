#include "headers.h"
#include "methods.h"

bool* binAdd(bool *Ar1, bool *Ar2, elements *e)
{
	bool *Res = new bool[8];
	bool a,b,c=0;
	for(int i=7;i>=0;i--)
				{
					a=Ar1[i];
					b=Ar2[i];
					Res[i]=a^b^c;
					c=(a&b)|(b&c)|(a&c);
					if(i==4) e->flags[4]=c;
					e->flags[6]= e->flags[6] | Res[i];
					e->flags[2]^=Res[i];
				}
				e->flags[0]=c;
	e->flags[7]=Res[0];
	e->flags[2]=!(e->flags[2]); 
	e->flags[6]=!(e->flags[6]);
	return Res;
}

bool* binSub(bool *Ar1, bool *Ar2, elements *e)
{
	bool *Res = new bool[8];
	bool a,b,c=0;
	for(int i=7;i>=0;i--)
				{
					a=Ar1[i];
					b=Ar2[i];
					Res[i]=(a)^b^c;
					c=((!a)&b)|(b&c)|((!a)&c);
					if(i==4) e->flags[4]=c;
					e->flags[6]= e->flags[6] | Res[i];
					e->flags[2]^=Res[i];
				}
	e->flags[0]=c;
	e->flags[7]=Res[0];
	e->flags[2]=!(e->flags[2]); 
	e->flags[6]=!(e->flags[6]);
	return Res;
}

int addSub(elements *e)
{
    string inst = e->memory[e->pc];
    string r,x,memo="",data;
	bool *Ar1,*Ar2,*Res,*Re;
	int i; bool a,b,c=0;
	e->flags[5]=e->flags[3]=e->flags[1]=0;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
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
		
	Ar2=ToBin(data);
	Ar1=ToBin(e->registers[0]);
	
	
	if(x=="add")
	{
		Res=binAdd(Ar1,Ar2,e);
	}
	else if(x=="sub")
	{
		e->flags[6]=e->flags[2]=e->flags[0]=0;	
		Res=binSub(Ar1,Ar2,e);
    }
    else
    return 0;
	

	e->registers[0]=ToHex(Res);
	
return 1;	
}

int adiSui(elements *e)
{
    string inst = e->memory[e->pc];
    string r,x;
	bool *Ar1,*Ar2,*Res;
	int i; bool a,b,c=0;
	e->flags[5]=e->flags[3]=e->flags[1]=0;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
	
	Ar1=ToBin(e->registers[0]);
	Ar2=ToBin(r);
	if(x=="adi")
	{
		Res=binAdd(Ar1,Ar2,e);
	}
	else if(x=="sui")
	{
		e->flags[6]=e->flags[2]=e->flags[0]=0;	
		Res=binSub(Ar1,Ar2,e);
    }
    else
    return 0;
	
	e->registers[0]=ToHex(Res);
return 1;	
}

int dad(elements *e)
{
	string inst = e->memory[e->pc];
    string r,x,data;
	bool *Ar1,*Ar2,*Res;
	int i; bool a,b,c=0;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    if(!(r[0]=='b'||r[0]=='d'||r[0]=='h'))
	return 0;
	
    int rdd;
    switch(r[0])
	{
		
		case 'b':rdd=2;break;
		case 'd':rdd=4;break;
		case 'h':rdd=6;break;
		default : return 0;
	}
		
	Ar2=ToBin(e->registers[rdd]);
	Ar1=ToBin(e->registers[6]);
	
	for(i=7;i>=0;i--)
				{
					a=Ar1[i];
					b=Ar2[i];
					Res[i]=a^b^c;
					c=(a&b)|(b&c)|(a&c);
				}
	
	e->registers[6]=ToHex(Res);
	
	Ar2=ToBin(e->registers[rdd-1]);
	Ar1=ToBin(e->registers[5]);
	for(i=7;i>=0;i--)
				{
					a=Ar1[i];
					b=Ar2[i];
					Res[i]=a^b^c;
					c=(a&b)|(b&c)|(a&c);
				}
	e->flags[0]=1;
	e->registers[5]=ToHex(Res);
	
return 1;		
}

int inrDcr(elements *e)
{
	string inst = e->memory[e->pc];
    string r,x,memo="",data;
	bool *Ar1,*Res;
	bool Ar2[8]={0,0,0,0,0,0,0,1};
	int i; bool a,b,c=0;
	e->flags[5]=e->flags[3]=e->flags[1]=0;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
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
		
	Ar1=ToBin(data);
	
	if(x=="inr")
	{
		Res=binAdd(Ar1,Ar2,e);
		e->flags[0]=0;
	}
	else if(x=="dcr")
	{
		e->flags[6]=e->flags[2]=e->flags[0]=0;	
		Res=binSub(Ar1,Ar2,e);
		e->flags[0]=0;
    }
    else
    return 0;
	
	e->registers[rdd]=ToHex(Res);
	
	return 1;	
}

int inxDcx(elements *e)
{
	string inst = e->memory[e->pc];
    string r,x,data;
	bool *Ar1;
	int i; bool a,b,c=1;
    stringstream ss(inst);
    getline(ss,x,' ');
    getline(ss,r);
    if(r.length()>1)	return 0;
   
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    if(!(r[0]=='b'||r[0]=='d'||r[0]=='h'))
	return 0;
	
    int rdd;
    switch(r[0])
	{
		case 'b':rdd=2;break;
		case 'd':rdd=4;break;
		case 'h':rdd=6;break;
		default : return 0;
	}
	Ar1=ToBin(e->registers[rdd]);
	for(i=7;i>=0;i--)
	{
			a=Ar1[i];
			Ar1[i]=(a)^c;
			if(x=="dcx")
			c=((!a)&c);
			else
			c=a&c;
			
	}
	e->registers[rdd]=ToHex(Ar1);
	Ar1=ToBin(e->registers[rdd-1]);
	for(i=7;i>=0;i--)
	{
			a=Ar1[i];
			Ar1[i]=(a)^c;
			if(x=="dcx")
			c=((!a)&c);
			else
			c=a&c;
			
	}
	e->registers[rdd-1]=ToHex(Ar1);
	
	return 1;	
}