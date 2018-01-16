/* Amine Yesilyurt - 131044004 HW01 */
#include <iostream>
#include <string>
#include <sstream>
#include "cpu.h"

using namespace std;

int main(int argc, char** argv) {

    int registers[REGISTER_SIZE] = {0, 0, 0, 0, 0}; //holds registers value
    int optionValue; // keeps option value
    
    if(argc != 3)
    	ExitProgram("Error in command line!\nTry this: ./exe filename.txt option");

    //option value taken as a string then converted to integer
    string optionString(argv[2]);
    istringstream intstr(optionString);
    
    //checking option value 
    if(optionString.size()>1){
    	ExitProgram("Invalid option value!");
    }    
    if(!isDigit(optionString[0])){
    	ExitProgram("Invalid option value!");
    }
    
    //get option value as integer
    intstr>>optionValue;
    
    //controlling option value
    if (optionValue != 0 && optionValue != 1){
        ExitProgram("Invalid option value!");
    }
    //starts CPU program
    startCPU(argv[1], optionValue, registers);

    return 0;
}

