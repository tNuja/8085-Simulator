#ifndef _METHODS_H
#define _METHODS_H

#include <string>
#include "headers.h"
using namespace std;

struct elements {

  string pc;
  string start;
  string registers[7];
  map<string, string> memory;
  int flags[8];
  vector<string> breakPoints;
};

int execute(elements *);
bool validAddress(string);
bool validInst(string);
int jmp(struct elements *);
int jc(struct elements *);
int jnc(struct elements *);
int jz(struct elements * );
int jnz(struct elements *);
int lhld(struct elements *);
int lxi(struct elements *);
int mov(struct elements *);
int mvi(struct elements *);
int sett(struct elements *);
int shld(struct elements *);
int sta(struct elements *);
int xchg(struct elements *);
int lda(struct elements *);
void display(elements *);
int adiSui(elements *);
int addSub(elements *);
int dad(elements *);
int inrDcr(elements *);
int inxDcx(elements *);
int cma(elements *);
int cmp(elements *);

int debug(elements *);
bool* ToBin(string);
string ToHex(bool*);
int convert2int(char);
char convert2char(int);
string addPc(string ,string);
int instSize(string);
bool val16(string);
int updatePc(elements *);
bool val8(string);
bool threeByte(vector<string>);
bool twoByte(vector<string> );
bool oneByte(vector<string> );
int instByteSize(string );
#endif
