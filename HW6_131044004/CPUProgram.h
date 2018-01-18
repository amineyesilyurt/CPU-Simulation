/* 
 * File:   CPUProgram.h
 * Author: Amine
 * HW06
 * Student Number :131044004
 */
#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H

#include <iostream>
#include <string>
#include<vector>
//macros
#define ZERO 0

using std::string;
using std::vector;
using std::ostream;

class CPUProgram {
public:
    CPUProgram();
    CPUProgram(int theOption);
    CPUProgram(const char* filename);
    string getLine(int indexPC)const;
    int getOption()const;
    void setNumOfLine(int theSize);
    void setOption(int theOption);
    void ReadFile(const char* filename);
    int size()const;
    //operator overloadings
    string operator[](int theIndex);
    CPUProgram operator+(string newInstruction)const;
    CPUProgram& operator+=(string newInstruction);
    CPUProgram operator+(CPUProgram& rtSide)const;
    friend ostream& operator<<(ostream& out, const CPUProgram& theCpuProgram);
    
    bool operator==(const CPUProgram& theCpuProgram )const;
    bool operator<=(const CPUProgram& theCpuProgram )const;
    bool operator>(const CPUProgram& theCpuProgram )const;
    bool operator<(const CPUProgram& theCpuProgram )const;
    bool operator>=(const CPUProgram& theCpuProgram )const;
    bool operator!=(const CPUProgram& theCpuProgram )const;
    
    CPUProgram operator--();   //pre decrement  
	CPUProgram operator--(int ignoreMe);//post decrement
	
	//function call
	CPUProgram operator()(int index1,int index2)const;
     
private:
    vector<string> instruction; //holds instructions
    void toUppercase(string & theLine); // convert the instruction to uppercase
    int numOfLine;
    int option;
};

#endif /* CPUPROGRAM_H */



