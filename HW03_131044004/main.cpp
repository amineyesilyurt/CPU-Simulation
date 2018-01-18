/* 
 * File:   main.cpp
 * Author: Amine
 * HW03
 * Student Number :131044004
 * Created on 22 October 2016, 22:17
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> //used only for exit
#include "CPU.h"
#include "CPUProgram.h"

using namespace std;

// prints error message and exit program
void ExitProgram(string message);

//gets a character type as a parameter 
//if character is digit return true, else return false
bool isDigit(char ch);

int main(int argc, char** argv) {

    int optionValue; // keeps option value
    if (argc != 3)
        ExitProgram("Error in command line!\nTry this: ./exe filename.txt option");

    //option value taken as a string then converted to integer
    string optionString(argv[2]);
    istringstream intstr(optionString);

    //checking option value 
    if (optionString.size() > 1) {
        ExitProgram("Invalid option value!");
    }
    if (!isDigit(optionString[0])) {
        ExitProgram("Invalid option value!");
    }

    //get option value as integer
    intstr>>optionValue;

    //controlling option value
    if (optionValue != 0 && optionValue != 1) {
        ExitProgram("Invalid option value!");
    }

    CPU myCPU(optionValue);
    CPUProgram myProg(argv[1]);

    int indexOfHLT = myProg.size(argv[1]);
    myCPU.setHLTIndex(indexOfHLT); //hereafter CPU program knows HLT of index 

    while (!(myCPU.halted()) ) {
        string instruction = myProg.getLine(myCPU.getPC());
        myCPU.execute(instruction);
        myCPU.increasePC();
    }    

    return 0;
}

void ExitProgram(string message) {
    cerr << message << endl;
    exit(1);
}

bool isDigit(char ch) {
    if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5')
        return true;
    else if (ch == '6' || ch == '7' || ch == '8' || ch == '9')
        return true;
    else
        return false;
}