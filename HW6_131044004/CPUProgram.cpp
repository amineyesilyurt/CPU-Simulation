/* 
 * File:   CPUProgram.cpp
 * Author: Amine
 * HW06
 * Student Number :131044004
 */
#include <iostream>
#include <cstdlib> //used only for exit
#include <string>
#include <fstream>
#include <sstream>  //only for eliminate spaces and getting integer
#include "CPUProgram.h"
#include "CPU.h"

using namespace std;

CPUProgram::CPUProgram() :numOfLine(0),option(0){

}

CPUProgram::CPUProgram(int theOption):numOfLine(0) {
    setOption(theOption);
}

CPUProgram::CPUProgram(const char* filename) :option(0){
    ReadFile(filename);
}

void CPUProgram::setNumOfLine(int theSize) {
    numOfLine = theSize;
}

void CPUProgram::setOption(int theOption) {
    if (theOption > 2) {
        cerr << "Invalid option value!" << endl;
        exit(1);
    }
    option = theOption;
}

int CPUProgram::getOption()const {
    return option;
}

void CPUProgram::ReadFile(const char* filename) {

    ifstream inStream; //for input file
    size_t indexSemicolon; //index of semicolon;
    string line;
    int numberOfline = 0;
    //opened input file
    inStream.open(filename);
    //controlled if opening input file failed
    if (inStream.fail()) {
        cerr << "Opening input file o failed!" << endl;
        exit(1);
    }
    // gets every line from file and inserts them to instruction vector 
    while (!inStream.eof()) {
        ++numberOfline;
        getline(inStream, line);
        //determined index of semicolon
        indexSemicolon = line.find_first_of(";");
        //deleted semicolon and string after semicolon from instruction   
        if (indexSemicolon) {
            string noCommentLine = line.substr(0, indexSemicolon);
            //line converted to uppercase
            toUppercase(noCommentLine);
            instruction.push_back(noCommentLine);
        } else {
            toUppercase(line);
            instruction.push_back(line);
        }

    }
    
    //set size
    setNumOfLine(numberOfline-1);
    instruction.pop_back(); //deleting empty string
    //closed input file
    inStream.close();
}

int CPUProgram::size()const {
    return numOfLine;
}
//////////////////////////////////////
///////OPERATOR OVERLOADINGS//////////
string CPUProgram::operator[](int theIndex){
	if(theIndex>= instruction.size() || theIndex<0)
		return "Operator [] : Invalid index!";
	else
		return instruction.at(theIndex);
}

CPUProgram CPUProgram::operator+(string newInstruction)const{
	CPUProgram newObj(option);
    newObj.instruction=this->instruction;        
    newObj.instruction.push_back(newInstruction); 
    newObj.setNumOfLine(numOfLine+1);
	return newObj;
}

CPUProgram&  CPUProgram::operator+=(string newInstruction){
	
	if(newInstruction.size()<1)
		cout<<"Operator += can not work with empty string!"<<endl;
	else{  
	   	instruction.push_back(newInstruction);
	   	setNumOfLine(numOfLine+1);
   	}
    return *this;   
}

CPUProgram CPUProgram::operator+( CPUProgram& rtSide)const{
    
	CPUProgram newObj(option);
    newObj.instruction=this->instruction;        
    for(int i=0; i<rtSide.instruction.size();++i ){
        newObj.instruction.push_back(rtSide.instruction.at(i));
    }
    newObj.setNumOfLine(numOfLine+rtSide.numOfLine -1);
    return newObj;
} 

ostream& operator<<(ostream& out, const CPUProgram& theCpuProgram){
    cout<<endl<<"Instructions Vector:"<<endl;
    for(int i=0; i< theCpuProgram.instruction.size() ; ++i )
       out<<theCpuProgram.instruction.at(i)<<endl;
    return out;
}

bool CPUProgram::operator==(const CPUProgram& theCpuProgram )const{
	return (numOfLine==theCpuProgram.numOfLine);
}

bool CPUProgram::operator<=(const CPUProgram& theCpuProgram )const{
	return (numOfLine<=theCpuProgram.numOfLine);
}

bool CPUProgram::operator>(const CPUProgram& theCpuProgram )const{
	return (numOfLine>theCpuProgram.numOfLine);
}

bool CPUProgram::operator!=(const CPUProgram& theCpuProgram )const{
	return (numOfLine!=theCpuProgram.numOfLine);
}

bool CPUProgram::operator>=(const CPUProgram& theCpuProgram )const{
	return (numOfLine>=theCpuProgram.numOfLine);
}

bool CPUProgram::operator<(const CPUProgram& theCpuProgram )const{
	return (numOfLine<theCpuProgram.numOfLine);
}
string CPUProgram::getLine(int indexPC) const {
    return instruction.at(indexPC);
}

CPUProgram CPUProgram::operator--(){
	--numOfLine;
	instruction.pop_back();
	return *this; 
}

CPUProgram CPUProgram::operator--(int ignoreMe){
	CPUProgram temp(option);
	temp.numOfLine= this->numOfLine;
	temp.instruction= this->instruction;
	--numOfLine;
	instruction.pop_back();
	return temp; 
}

CPUProgram CPUProgram::operator()(int index1,int index2)const{
	
	CPUProgram temp(option);
	if(index1>= instruction.size() || index1 < 0)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else if(index2>= instruction.size() || index2 < 0)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else if(index1>index2)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else if(index1==0 &&index2 ==0)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else{
	
		while(index1<=index2){
			temp.instruction.push_back(instruction.at(index1));
			++index1;
		}
		temp.setNumOfLine(temp.instruction.size());
		}
	return temp; 
}

void CPUProgram::toUppercase(string & theLine) {
    for (int index = ZERO; index < theLine.size(); ++index) {
        if (theLine[index] >= 'a' && theLine[index] <= 'z')
            theLine[index] = theLine[index] -('a' - 'A');
    }
}
