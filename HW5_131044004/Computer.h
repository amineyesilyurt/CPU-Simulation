/* 
 * File: Computer.h
 * Author: Amine
 * HW05
 * Student Number :131044004
 * Created on 15 November 2016
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include "CPU.h"
#include "CPUProgram.h"
#include "Memory.h"

class Computer {
public:
    Computer(CPU theCPU, CPUProgram theCPUProgram, Memory theMemory,int theOption);
    Computer(int theOption);
    void setCPU(CPU theCPU);
    void setCPUProgram(CPUProgram theCPUProgram);
    void setMemory(Memory theMemory);
    void setOption(int theOption);
    CPU getCPU() const;
    CPUProgram getCPUProgram()const;
    Memory getMemory()const;
    int getOption()const;
    void execute();
private:
    CPU cpu;
    CPUProgram cpuProgram;
    Memory memory;
    int option;
};

#endif /* COMPUTER_H */

