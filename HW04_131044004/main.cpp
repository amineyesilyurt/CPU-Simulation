/* 
 * File:   main.cpp
 * Author: Amine
 * HW04
 * Student Number :131044004
 * Created on 01 November 2016, 21:41
 */
#include <iostream>
#include <cstdlib> //used only for exit
#include <string>
#include <sstream>
#include "CPU.h"
#include "Memory.h"

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
    if (optionValue != 0 && optionValue != 1 && optionValue != 2) {
        ExitProgram("Invalid option value!");
    }
    Memory m;
    m.setMem(0,10);
    m.setMem(1,11);
    CPU myCPU(optionValue);
    myCPU.execute("Add R1,#0 ",m);
    myCPU.execute("Add R2,#1 ",m);
    myCPU.execute("mov R1,#2 ",m);
    myCPU.execute("Sub R1,#1 ",m);
    myCPU.execute("add R1,13 ",m);
    myCPU.execute("prn #10 ",m);
    myCPU.execute("hlt",m);
    m.printAll();
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

