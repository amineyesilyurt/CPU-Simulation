/* 
 * File:   Memory.h
 * Author: Amine
 * HW05
 * Student Number :131044004
 * Created on 15 November 2016
 */

#ifndef MEMORY_H
#define MEMORY_H

#include <string>
using std::string;

#define MEMORY_SIZE 50  // start from 0
#define ZERO 0

class Memory {
public:
    Memory();
    Memory(int theOption);
    int getMem(int index)const;
    int getOption()const;
    void setMem(int index, int value);
    void setOption(int theOption);
    void printAll()const;
    void printAll(int ignore)const;
private:
    int memory[MEMORY_SIZE];
    int option;
    // prints error message and exit program
    void ExitProgram(string message);
};

#endif /* MEMORY_H */

