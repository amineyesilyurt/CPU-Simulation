/* 
 * File:   Memory.h
 * Author: Amine
 * HW04
 * Student Number :131044004
 * Created on 01 November 2016, 21:45
 */

#ifndef MEMORY_H
#define	MEMORY_H

#define MEMORY_SIZE 50  // start from 0
#define ZERO 0
class Memory {
public:
    Memory();
    Memory(int theOption);
    int getMem(int index)const;
    void setMem(int index,int value);
    void printAll()const;
private:
    int memory[MEMORY_SIZE];
    int option;
};

#endif	/* MEMORY_H */

