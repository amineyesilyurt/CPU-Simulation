/* 
 * File:   CPU.h
 * Author: Amine
 * HW03
 * Student Number :131044004
 * Created on 22 October 2016, 22:17
 */

#ifndef CPU_H
#define	CPU_H

#include <iostream>
#include <string>

using std::string;
//macros
#define REGISTER_SIZE 5
#define ZERO 0

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
    bool execute(string theInstruction);

    void increasePC() {
        ++PC;
    }

private:
    int PC ; //program counter
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
    //Do ADD reg,reg or ADD reg,constant operations
    void AddInstruction(string instruction);
    //if there is any error instruction exits program 
    //Do SUB reg,reg or SUB reg,constant operations
    void SubInstruction(string instruction);
    // prints value of register or constant value to screen
    void PrintInstruction(string instruction);
    //if there is any error instruction exits program 
    //Do MOV reg,reg or ADD reg,constant operations
    void MoveInstruction(string instruction);
    // prints error message and exit program
    void ExitProgram(string message);
    //gets a character type as a parameter 
    //if character is digit return true, else return false
    bool isDigit(char ch);
};

#endif	/* CPU_H */

