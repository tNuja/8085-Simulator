# 8085-Simulator

This is a simulator for the 8085 microprocessor.

To run your program run main.cpp
You can also provide path of assembly language program in an .asm file as argument
If no file provided, input your program via command line

arith.cpp contains code for all arithmetic instructions like ADD,ADI,SUB,SUI,DAD,DCR,DCX,INX

logical.cpp contains code for instruction CMA,CMP

All other .cpp files represent code for a command as named

Any memory location which will be used as input source for the program will have to initialsed first
	This will be done by using the SET command provided in the instruction set.
		example : if memory location 3051 has to be used the command would be :
			SET 3051,13
		where 13 is data in hexadecimal format stored at location 3051
