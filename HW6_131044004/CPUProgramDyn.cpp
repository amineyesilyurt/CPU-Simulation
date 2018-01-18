/* 
 * File:   CPUProgramDyn.cpp
 * Author: Amine
 * HW06
 * Student Number :131044004
 */
 
#include <iostream>
#include <cstdlib> //used only for exit
#include <string>
#include <fstream>
#include <sstream>  //only for eliminate spaces and getting integer
#include "CPUProgramDyn.h"
#include "CPU.h"

using namespace std;

CPUProgramDyn::CPUProgramDyn() :numOfLine(0),option(0),capacity(200),used(0){
	instruction = new string[capacity];
}

CPUProgramDyn::CPUProgramDyn(int theOption):numOfLine(0),capacity(200),used(0){
    setOption(theOption);
    instruction = new string[capacity];
}

CPUProgramDyn::CPUProgramDyn(int theOption,int theCapacity):numOfLine(0),used(0){
    setOption(theOption);
    capacity=theCapacity;
    instruction = new string[capacity];
}

CPUProgramDyn::CPUProgramDyn(const char* filename) :option(0),capacity(200),used(0),numOfLine(0){
    ReadFile(filename);
    instruction = new string[capacity];
}

CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn& CPUProgramDynObject) //copy constructor
:capacity(CPUProgramDynObject.getCapacity()), used(CPUProgramDynObject.getNumberUsed()),
option(CPUProgramDynObject.getOption()),numOfLine(CPUProgramDynObject.size()){
	instruction = new string[capacity];
	for(int i=0;i<used;++i)	
		instruction[i]=CPUProgramDynObject.instruction[i];
		
}

void CPUProgramDyn::setNumOfLine(int theSize) {
    numOfLine = theSize;
}

void CPUProgramDyn::setOption(int theOption) {
    if (theOption > 2) {
        cerr << "Invalid option value!" << endl;
        exit(1);
    }
    option = theOption;
}

int CPUProgramDyn::getOption()const {
    return option;
}

void CPUProgramDyn::ReadFile(const char* filename) {

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
            push_back(noCommentLine);
        } else {
            toUppercase(line);
            push_back(line);
        }

    }
    
    //set size
    setNumOfLine(numberOfline-1);
    pop_back(); //deleting empty string
    //closed input file
    inStream.close();
}

int CPUProgramDyn::size()const {
    return numOfLine;
}
//////////////////////////////////////
///////OPERATOR OVERLOADINGS//////////


CPUProgramDyn& CPUProgramDyn::operator=(const CPUProgramDyn& rightSide) {
    if (capacity != rightSide.capacity) {
        delete[] instruction;
        instruction = new string[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; ++i)
        instruction[i] = rightSide.instruction[i];
    return *this;

}

string CPUProgramDyn::operator[](int theIndex){
	if(theIndex>= getNumberUsed() || theIndex<0)
		return "Operator [] : Invalid index!";
	else
		return instruction[theIndex];
}

CPUProgramDyn CPUProgramDyn::operator+(string newInstruction)const{
	CPUProgramDyn newObj(option,capacity);
	newObj.used=used;
    for(int i=0;i<used;++i)	
		newObj.instruction[i]=instruction[i];        
    newObj.push_back(newInstruction); 
    newObj.setNumOfLine(numOfLine+1);
	return newObj;
}

CPUProgramDyn&  CPUProgramDyn::operator+=(string newInstruction){
	
	if(newInstruction.size()<1)
		cout<<"Operator += can not work with empty string!"<<endl;
	else{  
	   	push_back(newInstruction);
	   	setNumOfLine(numOfLine+1);
   	}
    return *this;   
}

CPUProgramDyn CPUProgramDyn::operator+( CPUProgramDyn& rtSide)const{
    
	CPUProgramDyn newObj(option,capacity);
	newObj.used=used;
	for(int i=0;i<used;++i)	
		newObj.instruction[i]=instruction[i];        
    for(int i=0; i<rtSide.size();++i ){
        newObj.push_back(rtSide[i]);
    }
    newObj.setNumOfLine(numOfLine+rtSide.numOfLine -1);
    return newObj;
} 

ostream& operator<<(ostream& out, const CPUProgramDyn& theCPUProgramDyn){
    cout<<endl<<"Instructions Vector:"<<endl;
    for(int i=0; i< theCPUProgramDyn.getNumberUsed() ; ++i )
       out<<theCPUProgramDyn.instruction[i]<<endl;
    return out;
}

bool CPUProgramDyn::operator==(const CPUProgramDyn& theCPUProgramDyn )const{
	return (numOfLine==theCPUProgramDyn.numOfLine);
}

bool CPUProgramDyn::operator<=(const CPUProgramDyn& theCPUProgramDyn )const{
	return (numOfLine<=theCPUProgramDyn.numOfLine);
}

bool CPUProgramDyn::operator>(const CPUProgramDyn& theCPUProgramDyn )const{
	return (numOfLine>theCPUProgramDyn.numOfLine);
}

bool CPUProgramDyn::operator!=(const CPUProgramDyn& theCPUProgramDyn )const{
	return (numOfLine!=theCPUProgramDyn.numOfLine);
}

bool CPUProgramDyn::operator>=(const CPUProgramDyn& theCPUProgramDyn )const{
	return (numOfLine>=theCPUProgramDyn.numOfLine);
}

bool CPUProgramDyn::operator<(const CPUProgramDyn& theCPUProgramDyn )const{
	return (numOfLine<theCPUProgramDyn.numOfLine);
}
string CPUProgramDyn::getLine(int indexPC) const {
    return instruction[indexPC];
}

CPUProgramDyn CPUProgramDyn::operator--(){
	--numOfLine;
	pop_back();
	return *this; 
}

CPUProgramDyn CPUProgramDyn::operator--(int ignoreMe){
	CPUProgramDyn temp(option);
	temp.numOfLine= this->numOfLine;
	temp.instruction= this->instruction;
	--numOfLine;
	pop_back();
	return temp; 
}

CPUProgramDyn CPUProgramDyn::operator()(int index1,int index2)const{
	
	CPUProgramDyn temp(option);
	if(index1 >= getNumberUsed() || index1 < 0)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else if(index2>= getNumberUsed() || index2 < 0)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else if(index1>index2)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else if(index1==0 &&index2 ==0)
		cout<<"Function Call: Invalid parameters!"<<endl;
	else{
	
		while(index1<=index2){
			temp.push_back(instruction[index1]);
			++index1;
		}
		temp.setNumOfLine(temp.getNumberUsed());
		}
	return temp; 
}

void CPUProgramDyn::toUppercase(string & theLine) {
    for (int index = ZERO; index < theLine.size(); ++index) {
        if (theLine[index] >= 'a' && theLine[index] <= 'z')
            theLine[index] = theLine[index] -('a' - 'A');
    }
}

void CPUProgramDyn::push_back(string theIntruction){
	if(used >= capacity){
		rescale(2); //double the capacity
	}
	instruction[used] =	theIntruction;
	++used;
}

string CPUProgramDyn::pop_back(){

	string popedInstruction;
	if(used>0){
		popedInstruction=instruction[used-1];
		--used;
	}
	return popedInstruction;
}

bool CPUProgramDyn::isFull()const{
	return (capacity == used);
}
int CPUProgramDyn::getCapacity()const{
	return capacity;
}
int CPUProgramDyn::getNumberUsed()const{
	return used;
}

//copied from moodle ps code Açksjldgakl
void CPUProgramDyn::rescale(int scale) {

    capacity *= scale;
    string* newStringArray = new string[capacity];

    for (int i = 0; i < used; i++)
        newStringArray[i] = instruction[i];

    delete[] instruction;

    instruction = newStringArray;
}

CPUProgramDyn::~CPUProgramDyn(){
	delete [] instruction;
}


