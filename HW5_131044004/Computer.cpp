/* 
 * File: Computer.cpp
 * Author: Amine
 * HW05
 * Student Number :131044004
 * Created on 15 November 2016
 */
#include <iostream>
#include <cstdlib> //used only for exit
#include<string>
#include "Computer.h"

using namespace std;

Computer::Computer(CPU theCPU, CPUProgram theCPUProgram, Memory theMemory, int theOption) {
    setCPU(theCPU);
    setCPUProgram(theCPUProgram);
    setMemory(theMemory);
    setOption(theOption);
}

Computer::Computer(int theOption) {
    setOption(theOption);
}

void Computer::setCPU(CPU theCPU) {
    cpu = theCPU;
}

void Computer::setCPUProgram(CPUProgram theCPUProgram) {
    cpuProgram = theCPUProgram;
}

void Computer::setMemory(Memory theMemory) {
    memory = theMemory;
}

void Computer::setOption(int theOption) {
    if (theOption > 2) {
        cerr << "Invalid option value!" << endl;
        exit(1);
    }
    option = theOption;
}

CPU Computer::getCPU() const {
    return cpu;
}

CPUProgram Computer::getCPUProgram()const {
    return cpuProgram;
}

Memory Computer::getMemory()const {
    return memory;
}

int Computer::getOption()const {
    return option;
}

void Computer::execute() {

    cpu.setHLTIndex(cpuProgram.size());
    while (!(cpu.halted())) {
        string instruction = cpuProgram.getLine(cpu.getPC() - 1);       
        cpu.execute(instruction,memory);
        cpu.increasePC();
    }
}
