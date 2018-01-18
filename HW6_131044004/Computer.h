/* 
 * File: Computer.h
 * Author: Amine
 * HW06
 * Student Number :131044004
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include "CPU.h"
#include "CPUProgramDyn.h"
//#include "CPUProgram.h"
#include "Memory.h"

class Computer {
public:
    Computer(CPU theCPU, CPUProgramDyn theCPUProgram, Memory theMemory,int theOption);
    Computer(int theOption);
    void setCPU(CPU theCPU);
    void setCPUProgram(CPUProgramDyn theCPUProgram);
    void setMemory(Memory theMemory);
    void setOption(int theOption);
    CPU getCPU() const;
    CPUProgramDyn getCPUProgram()const;
    Memory getMemory()const;
    int getOption()const;
    void execute();
private:
    CPU cpu;
    CPUProgramDyn cpuProgram;
    Memory memory;
    int option;
};

#endif /* COMPUTER_H */

