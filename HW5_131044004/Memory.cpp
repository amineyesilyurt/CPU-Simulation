/* 
 * File:   Memory.cpp
 * Author: Amine
 * HW05
 * Student Number :131044004
 * Created on 15 November 2016
 */
#include <iostream>
#include <cstdlib> //used only for exit
#include <string>
#include "Memory.h"

using namespace std;

Memory::Memory() : option(0) {
    for (int index = 0; index < MEMORY_SIZE; ++index)
        memory[index] = 0;
}

Memory::Memory(int theOption){
    
    setOption(theOption);
    for (int index = 0; index < MEMORY_SIZE; ++index)
        memory[index] = 0;
}

int Memory::getMem(int index) const {
    return memory[index];
}

int Memory::getOption()const {
    return option;
}

void Memory::setMem(int index, int value) {
    memory[index] = value;
}

void Memory::setOption(int theOption) {
    if (theOption > 2) {
        ExitProgram("Invalid option value!");
    }
    option = theOption;
}

void Memory::printAll() const {
    cout << endl << "Memory Values:" << endl;
    for (int index = ZERO; index < MEMORY_SIZE; ++index) {
        cout << "m[" << index << "]=" << memory[index] << endl;
    }
    cout << endl << endl;
}

void Memory::printAll(int ignore) const {
    for (int index = ZERO; index < MEMORY_SIZE; ++index) {
        if (0 == (index % 10))
            cout << endl;
        cout << "m[" << index << "]=" << memory[index] << "   ";
    }
    cout << endl << endl;
}

void Memory::ExitProgram(string message) {
    cout << message << endl;
    exit(1);
}
