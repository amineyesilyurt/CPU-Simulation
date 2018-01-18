/* 
 * File:   CPUProgram.cpp
 * Author: Amine
 * HW03
 * Student Number :131044004
 * Created on 22 October 2016, 22:17
 */
#include <iostream>
#include <cstdlib> //used only for exit
#include <string>
#include <fstream>
#include <sstream>  //only for eliminate spaces and getting integer
#include "CPUProgram.h"

using namespace std;

CPUProgram::CPUProgram(const char* filename) {
    ReadFile(filename);
}

void CPUProgram::ReadFile(const char* filename) {

    ifstream inStream; //for input file
    size_t indexSemicolon; //index of semicolon;
    string line;
    //opened input file
    inStream.open(filename);
    //controlled if opening input file failed
    if (inStream.fail()) {
        cerr << "Opening input file o failed!" << endl;
        exit(1);
    }
    // gets every line from file and inserts them to instruction vector 
    while (!inStream.eof()) {
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
    //closed input file
    inStream.close();
}

int CPUProgram::size(const char* filename)const {
    ifstream inStream;
    int numberOfLine = ZERO;
    string line;
    //opened input file
    inStream.open(filename);
    //controlled if opening file is fail
    //if failed, give error message and exit the program
    if (inStream.fail()) {
        cerr << "Opening input file failed!" << endl;
        exit(1);
    }
    //increase number of line until end of file
    while (!inStream.eof()) {
        getline(inStream, line);
        ++numberOfLine;
    }
    //closed input file
    inStream.close();

    return numberOfLine;
}

string CPUProgram::getLine(int indexPC) const {
    return instruction.at(indexPC - 1);
}

void CPUProgram::toUppercase(string & theLine) {
    for (int index = ZERO; index < theLine.size(); ++index) {
        if (theLine[index] >= 'a' && theLine[index] <= 'z')
            theLine[index] = theLine[index] -('a' - 'A');
    }
}