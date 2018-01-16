/* Amine Yesilyurt - 131044004 HW02 */
#ifndef YESILYURT_CPU_H__
#define YESILYURT_CPU_H__

#include <iostream>
#include <string>

using namespace std;

//macros 
#define REGISTER_SIZE 5
#define ZERO 0
#define MEMORY_SIZE 50  // start from 0
#define MAX_INSTRUCTION_SIZE 200

//teke a string as a parameter , convert string's lowercases to uppercase 
//Example mov  converted to MOV, r1 converted to R1
void toUppercase(string & strWithLowercase);

//gets a character type as a parameter 
//if character is digit return true, else return false
bool isDigit(char ch);

//opens input file, determines number of line and returns it 
int getNumberOfLine(const char* filename);

//opens input file, gets each line ,deletes comments 
//and inserts each non-comment lines  to instruction array 
//before inserting line converted to uppercase
void getInstructions(const char* filename, string instruction[]);

// prints error message and exit program
void ExitProgram(string message);

//if there is any error instruction exits program 
//Do SUB reg,reg or SUB reg,constant operations
void SubInstruction(string instruction, int option, int registers[],int memory[]);

// prints value of register or constant value to screen
void PrintInstruction(string instruction, int option, int registers[],int memory[]);

//if there is any error instruction exits program 
//Do ADD reg,reg or ADD reg,constant operations
void AddInstruction(string instruction, int option, int registers[],int memory[]);

//if there is any error instruction exits program 
//Do MOV reg,reg or ADD reg,constant operations
void MoveInstruction(string instruction, int option, int registers[],int memory[]);

//if there is any error instruction exits program 
//Do JMP reg,lineAdress operation
void JumpInstructionWithTwoOperand(string instruction, int option, int& index, int registers[],int memory[]);

//if there is any error instruction exits program 
//Do JMP  lineAdress
void JumpInstructionWithOneOperand(string instruction, int option, int& index, int registers[],int memory[]);

//jumps to target line of the program if the value of register is zero or smaller.
void JPNInstruction(string instruction, int option, int& index, int registers[],int memory[]);

//print memory contents on screen
void printMemory(int memory[]);

//calls other functions and starts program
void startCPU(const char* filename, int option);

#endif

