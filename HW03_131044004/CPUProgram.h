/* 
 * File:   CPUProgram.h
 * Author: Amine
 * HW03
 * Student Number :131044004
 * Created on 22 October 2016, 22:17
 */
#ifndef CPUPROGRAM_H
#define	CPUPROGRAM_H

#include <iostream>
#include <string>
#include<vector>
//macros
#define ZERO 0

using std::string;
using std::vector;

class CPUProgram {
public:
    CPUProgram(const char* filename);
    void ReadFile(const char* filename);
    string getLine(int indexPC)const;
    int size(const char* filename)const;
private:
    vector<string> instruction; //holds instructions
    void toUppercase(string & theLine); // convert the instruction to uppercase 
};

#endif	/* CPUPROGRAM_H */

