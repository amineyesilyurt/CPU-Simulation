/* 
 * File:   Memory.cpp
 * Author: Amine
 * HW04
 * Student Number :131044004
 * Created on 01 November 2016, 21:45
 */
#include <iostream>
#include <cstdlib> //used only for exit
#include "Memory.h"

using namespace std;

Memory::Memory():option(0){
    for(int index=0; index<MEMORY_SIZE; ++index)
        memory[index]=0;
}

Memory::Memory(int theOption):option(theOption){
    for(int index=0; index<MEMORY_SIZE; ++index)
        memory[index]=0;
}

int Memory::getMem(int index) const{
    return memory[index];
}

void Memory::setMem(int index,int value){
    memory[index]=value;
}

void Memory::printAll() const{
    for (int index = ZERO; index < MEMORY_SIZE; ++index) {
        if (0 == (index % 10))
            cout << endl;
        cout << "m[" << index << "]=" << memory[index] << "   ";
    }
    cout << endl << endl;
}