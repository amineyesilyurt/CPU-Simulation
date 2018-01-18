/* 
 * File:   CPUProgramDyn.h
 * Author: Amine
 * HW06
 * Student Number :131044004
 */
#ifndef CPUPROGRAMDYN_H
#define CPUPROGRAMDYN_H

#include <iostream>
#include <string>
#include <vector>
//macros
#define ZERO 0

using std::string;
using std::vector;
using std::ostream;

class CPUProgramDyn {
public:
    CPUProgramDyn();
    CPUProgramDyn(int theOption);
    CPUProgramDyn(int theOption,int theCapacity);
    CPUProgramDyn(const CPUProgramDyn& CPUProgramDynObject); //copy constructor,for big three
    CPUProgramDyn(const char* filename);
    string getLine(int indexPC)const;
    int getOption()const;
    void setNumOfLine(int theSize);
    void setOption(int theOption);
    void ReadFile(const char* filename);
    int size()const;
    
    //functions related instruction array 
    void push_back(string theIntruction);
    string pop_back();
    bool isFull()const;
    int getCapacity()const;
    int getNumberUsed()const;   
    
    //operator overloadings
    CPUProgramDyn& operator=(const CPUProgramDyn& rightSide); //for big three
    string operator[](int theIndex);
    CPUProgramDyn operator+(string newInstruction)const;
    CPUProgramDyn& operator+=(string newInstruction);
    CPUProgramDyn operator+(CPUProgramDyn& rtSide)const;
    friend ostream& operator<<(ostream& out, const CPUProgramDyn& theCPUProgramDyn);
    
    bool operator==(const CPUProgramDyn& theCPUProgramDyn )const;
    bool operator<=(const CPUProgramDyn& theCPUProgramDyn )const;
    bool operator>(const CPUProgramDyn& theCPUProgramDyn )const;
    bool operator<(const CPUProgramDyn& theCPUProgramDyn )const;
    bool operator>=(const CPUProgramDyn& theCPUProgramDyn )const;
    bool operator!=(const CPUProgramDyn& theCPUProgramDyn )const;
    
    CPUProgramDyn operator--();   //pre decrement  
	CPUProgramDyn operator--(int ignoreMe);//post decrement
	
	//function call
	CPUProgramDyn operator()(int index1,int index2)const;
	
	~CPUProgramDyn(); //for big three
     
private:
    string* instruction; //holds instructions
    int capacity;
    int used;
    void toUppercase(string & theLine); // convert the instruction to uppercase
    int numOfLine;
    int option;
    void rescale(int scale);
   
};

#endif /* CPUPROGRAMDYN_H */



