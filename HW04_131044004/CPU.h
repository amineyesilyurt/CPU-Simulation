/* 
 * File:   CPU.h
 * Author: Amine
 * HW04
 * Student Number :131044004
 * Created on 01 November 2016, 21:41
 */

#ifndef CPU_H
#define	CPU_H

#include <iostream>
#include <string>
#include "Memory.h"
using std::string;
//macros
#define REGISTER_SIZE 5
#define ZERO 0
#define MEMORY_SIZE 50  // start from 0

class CPU {
public:
    CPU();
    CPU(int theOption);
    int getRegisters(int index) const;
    int getPC()const;
    int getHLTIndex()const;
    void setRegisters(int value, int index);
    void setPC(int value);
    void setHLTIndex(int index);
    void print() const;
    bool halted() const;
    //determines the instruction and calls related function
    bool execute(string theInstruction, Memory memoryObj);

    void increasePC() {
        ++PC;
    }

private:
    int PC; //program counter
    int option;
    int HLTIndex;
    int registers[REGISTER_SIZE];
    //if there is any error instruction exits program 
    //Do JMP reg,lineAdress operation
    void JumpInstructionWithTwoOperand(string instruction);
    //if there is any error instruction exits program 
    //Do JMP  lineAdress
    void JumpInstructionWithOneOperand(string instruction);
    //if there is any error instruction exits program 
    //Do ADD reg,reg,  ADD reg,constant and ADD reg ,address operations
    void AddInstruction(string instruction, Memory memoryObj);
    //if there is any error instruction exits program 
    //Do SUB reg,reg , SUB reg,constant and SUB reg,address operations
    void SubInstruction(string instruction, Memory memoryObj);
    // prints value of register or constant value  or value of memory some address to screen
    void PrintInstruction(string instruction, Memory memoryObj);
    //if there is any error instruction exits program 
    //Do MOV reg,reg 
    //MOV reg,constant
    //MOV reg, address
    //MOV address, reg
    //MOV address, constant operations
    void MoveInstruction(string instruction,Memory memoryObj);
    // prints error message and exit program
    void ExitProgram(string message);
    //gets a character type as a parameter 
    //if character is digit return true, else return false
    bool isDigit(char ch);
    //helper functions
    void toUppercase(string & theLine); // convert the instruction to uppercase 
};

#endif	/* CPU_H */


