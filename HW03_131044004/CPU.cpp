/* 
 * File:   CPU.cpp
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
#include "CPU.h"

using namespace std;

CPU::CPU():option(0),PC(1) {
    for (int index = 0; index < REGISTER_SIZE; ++index) {
        setRegisters(0, index);
    }
}

CPU::CPU(int theOption) : option(theOption),PC(1) {
    for (int index = 0; index < REGISTER_SIZE; ++index) {
        setRegisters(0, index);
    }
}

int CPU::getRegisters(int index) const {
    return registers[index];
}

int CPU::getPC()const {
    return PC;
}

int CPU::getHLTIndex()const {
    return HLTIndex;
}

void CPU::setRegisters(int value, int index) {
    registers[index] = value;
}

void CPU::setPC(int value) {
    PC = value;
}

void CPU::setHLTIndex(int index) {
    HLTIndex = index;
}

void CPU::print() const {
    for (int index = 0; index < REGISTER_SIZE; ++index)
        cout << "R" << index + 1 << ":" << registers[index] << ", ";
    cout << "PC:" << getPC() << endl;
}

bool CPU::halted() const {
    bool isHLT = false;
    if (getPC() == getHLTIndex())
        isHLT = true;
    return isHLT;
}

bool CPU::execute(string theInstruction) {
    string last;
    string opcode;
    string unnecessary;
    stringstream streamLine(theInstruction);

    streamLine>>opcode;

    if (opcode == "HLT") {
        size_t lastLetterOfOpcode = theInstruction.find_first_of("T") + 1; //+1 is space
        last = theInstruction.substr(lastLetterOfOpcode, theInstruction.size() - 3); //3 is length of opcode
        stringstream sstream(last);
        sstream>>unnecessary;
        //if there is unnecessary strings in instruction,exit program
        if (unnecessary.size() > ZERO) {
            ExitProgram("HLT Instruction: ERROR");
        } else {
            //if option is 1
            if (option) {
                cout << "HLT— ";
                print();
            }
            //halts the program and prints on the screen the contents of all registers
            cout << "R1 :" << registers[0] << endl;
            cout << "R2 :" << registers[1] << endl;
            cout << "R3 :" << registers[2] << endl;
            cout << "R4 :" << registers[3] << endl;
            cout << "R5 :" << registers[4] << endl;

        }
    } else if (opcode == "JMP") {
        size_t found = theInstruction.find(",");
        //if instruction like : JMP reg,lineAdress
        if (found != string::npos)
            JumpInstructionWithTwoOperand(theInstruction);

        else //if instruction like : JMP lineAdress
            JumpInstructionWithOneOperand(theInstruction);
        
        if (PC >= getHLTIndex() || PC < ZERO) {
            ExitProgram("JMP ERROR: Out of the range!");
        }

    } else if (opcode == "ADD") {
        AddInstruction(theInstruction);
    } else if (opcode == "SUB") {
        SubInstruction(theInstruction);
    } else if (opcode == "PRN") {
        PrintInstruction(theInstruction);
    } else if (opcode == "MOV") {
        MoveInstruction(theInstruction);

    } else {
        cout<< "Line:" << PC; 
        ExitProgram(" Invalid opcode!");
    }
    return true;
}

void CPU::JumpInstructionWithTwoOperand(string instruction) {
    size_t indexOfComma = instruction.find_first_of(",");
    size_t lastLetterOfOpcode = instruction.find_first_of("P") + 1;
    string leftOperandWithSpace;
    string rightOperandWithSpace;
    string leftOperand;
    string rightOperand;
    string unnecessary;

    leftOperandWithSpace = instruction.substr(lastLetterOfOpcode, indexOfComma - lastLetterOfOpcode);
    rightOperandWithSpace = instruction.substr(indexOfComma + 1, instruction.size()-(indexOfComma));

    stringstream leftOp(leftOperandWithSpace);
    leftOp>>leftOperand; //without space

    stringstream rightOp(rightOperandWithSpace);
    rightOp>>rightOperand; //without space

    if (!(rightOperand.size() > 0))
        ExitProgram("JMP Instruction: There is no right operand!");

    //if instruction like this JMP R1 ab , R2 ab ;
    //"ab" is unnecessary so we will detect it 
    leftOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("JMP Instruction: There is an error!");
    }
    rightOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("JMP Instruction: There is an error!");
    }

    if (leftOperand == "R1") {

        if (registers[0] == 0) {
            //controls if lineAdress is integer
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("JMP Instruction: There is an error on right operand!");
                }
            }
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            setPC(value - 1);
        }

    } else if (leftOperand == "R2") {

        if (registers[1] == 0) {
            //controls if lineAdress is integer
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("JMP Instruction: There is an error on right operand!");
                }
            }
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            setPC(value - 1);
        }

    } else if (leftOperand == "R3") {

        if (registers[2] == 0) {
            //controls lineAdress is integer
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("JMP Instruction: There is an error on right operand!");
                }
            }
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            setPC(value - 1);
        }

    } else if (leftOperand == "R4") {

        if (registers[3] == 0) {
            //controls lineAdress is integer
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("JMP Instruction: There is an error on right operand!");
                }
            }
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            setPC(value - 1);
        }

    } else if (leftOperand == "R5") {

        if (registers[4] == 0) {
            //controls lineAdress is integer
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("JMP Instruction: There is an error on right operand!");
                }
            }
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            setPC(value - 1);
        }

    } else {
        ExitProgram("JMP Instruction: Invalid left operand");
    }
    //if option 1 prints registers value to screen
    if (option) {
        cout << "JMP " << leftOperand << ", " << rightOperand << "— ";
        print();
    }
}

void CPU::JumpInstructionWithOneOperand(string instruction) {
    string operand;
    string unnecessary;
    string OperandWithSpace;
    size_t lastLetterOfOpcode = instruction.find_first_of("P") + 1; // to start space added +1 

    OperandWithSpace = instruction.substr(lastLetterOfOpcode, instruction.size() - lastLetterOfOpcode);

    stringstream sstream(OperandWithSpace);
    sstream >> operand;

    if (!(operand.size() > 0))
        ExitProgram("JMP Instruction: There is no right operand!");
    //if instruction like this JMP R1 10  ab ;
    //"ab" is unnecessary so we will detect it 
    sstream>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("JMP Instruction: There is an error!");
    }

    for (int i = ZERO; i < operand.size(); ++i) {
        if (!isDigit(operand[i])) {
            ExitProgram("JMP Instruction: There is an error on right operand!");
        }
    }
    istringstream intstr(operand);
    int value;
    intstr>>value;
    setPC(value - 1);
    //if option 1 prints registers value to screen
    if (option) {
        cout << "JMP " << operand << "— ";
        print();
    }

}

void CPU::AddInstruction(string instruction) {

    string leftOperandWithSpace; //may contains lots of spaces
    string rightOperandWithSpace; //may contains lots of spaces
    string leftOperand; // operand without unnecessary spaces
    string rightOperand; // operand without unnecessary spaces
    string unnecessary; //if instruction line has unnecessary things like:
    //ADD r1 asd , r2 asdfas ;asdf is unnecessary string

    size_t indexOfComma = instruction.find_first_of(",");
    size_t lastLetterOfOpcode = instruction.find_first_of("D") + 2;
    // index of first space  after opcode
    //+2 because ADD include two D letter

    leftOperandWithSpace = instruction.substr(lastLetterOfOpcode, indexOfComma - lastLetterOfOpcode);
    rightOperandWithSpace = instruction.substr(indexOfComma + 1, instruction.size()-(indexOfComma));

    stringstream leftOp(leftOperandWithSpace);
    leftOp>>leftOperand; //without space

    stringstream rightOp(rightOperandWithSpace);
    rightOp>>rightOperand; //without space

    if (!(rightOperand.size() > 0))
        ExitProgram("ADD Instruction: There is no right operand!");

    //if instruction like this ADD R1 ab , R2 ab ;
    //"ab" is unnecessary so we will detect it 
    leftOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("ADD Instruction: There is an error!");
    }
    rightOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("ADD Instruction: There is an error!");
    }

    if (leftOperand == "R1") {
        if (rightOperand == "R1") {
            registers[0] += registers[0];
        } else if (rightOperand == "R2") {
            registers[0] += registers[1];
        } else if (rightOperand == "R3") {
            registers[0] += registers[2];
        } else if (rightOperand == "R4") {
            registers[0] += registers[3];
        } else if (rightOperand == "R5") {
            registers[0] += registers[4];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("ADD Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[0] += value;
        }
    } else if (leftOperand == "R2") {

        if (rightOperand == "R1") {
            registers[1] += registers[0];
        } else if (rightOperand == "R2") {
            registers[1] += registers[1];
        } else if (rightOperand == "R3") {
            registers[1] += registers[2];
        } else if (rightOperand == "R4") {
            registers[1] += registers[3];
        } else if (rightOperand == "R5") {
            registers[1] += registers[4];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("ADD Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[1] += value;
        }
    } else if (leftOperand == "R3") {

        if (rightOperand == "R1") {
            registers[2] += registers[0];
        } else if (rightOperand == "R2") {
            registers[2] += registers[1];
        } else if (rightOperand == "R3") {
            registers[2] += registers[2];
        } else if (rightOperand == "R4") {
            registers[2] += registers[3];
        } else if (rightOperand == "R5") {
            registers[2] += registers[4];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("ADD Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[2] += value;
        }
    } else if (leftOperand == "R4") {

        if (rightOperand == "R1") {
            registers[3] += registers[0];
        } else if (rightOperand == "R2") {
            registers[3] += registers[1];
        } else if (rightOperand == "R3") {
            registers[3] += registers[2];
        } else if (rightOperand == "R4") {
            registers[3] += registers[3];
        } else if (rightOperand == "R5") {
            registers[3] += registers[4];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("ADD Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[3] += value;
        }
    } else if (leftOperand == "R5") {

        if (rightOperand == "R1") {
            registers[4] += registers[0];
        } else if (rightOperand == "R2") {
            registers[4] += registers[1];
        } else if (rightOperand == "R3") {
            registers[4] += registers[2];
        } else if (rightOperand == "R4") {
            registers[4] += registers[3];
        } else if (rightOperand == "R5") {
            registers[4] += registers[4];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("ADD Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[4] += value;
        }
    } else {
        ExitProgram("ADD Instruction: There is an error on left operand!");
    }

    //if option is 1 prints registers value to screen
    if (option) {
        cout << "ADD " << leftOperand << ", " << rightOperand << "— ";
        print();
    }

}

void CPU::SubInstruction(string instruction) {
    string leftOperandWithSpace; //may contains lots of spaces
    string rightOperandWithSpace; //may contains lots of spaces
    string leftOperand; // operand without unnecessary spaces
    string rightOperand; // operand without unnecessary spaces
    string unnecessary; //if instruction line has unnecessary things like:
    //SUB r1 asd , r2 asdfas ;asdf is unnecessary string

    size_t indexOfComma = instruction.find_first_of(",");
    size_t lastLetterOfOpcode = instruction.find_first_of("B") + 1;
    // +1 because to start from space

    leftOperandWithSpace = instruction.substr(lastLetterOfOpcode, indexOfComma - lastLetterOfOpcode);
    rightOperandWithSpace = instruction.substr(indexOfComma + 1, instruction.size()-(indexOfComma));

    stringstream leftOp(leftOperandWithSpace);
    leftOp>>leftOperand; //without space

    stringstream rightOp(rightOperandWithSpace);
    rightOp>>rightOperand; //without space

    //if there is unnecessary strings exit program
    leftOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("SUB Instruction: There is an error!");
    }
    rightOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("SUB Instruction: There is an error!");
    }

    if (!(rightOperand.size() > 0))
        ExitProgram("SUB Instruction: There is no right operand!");

    if (leftOperand == "R1") {

        if (rightOperand == "R1") {
            registers[0] -= registers[0];
        } else if (rightOperand == "R2") {
            registers[0] -= registers[1];
        } else if (rightOperand == "R3") {
            registers[0] -= registers[2];
        } else if (rightOperand == "R4") {
            registers[0] -= registers[3];
        } else if (rightOperand == "R5") {
            registers[0] -= registers[4];
        } else {
            //controlling constant value valid 
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("SUB Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            //subtraction 
            registers[0] -= value;
        }
    } else if (leftOperand == "R2") {

        if (rightOperand == "R1") {
            registers[1] -= registers[0];
        } else if (rightOperand == "R2") {
            registers[1] -= registers[1];
        } else if (rightOperand == "R3") {
            registers[1] -= registers[2];
        } else if (rightOperand == "R4") {
            registers[1] -= registers[3];
        } else if (rightOperand == "R5") {
            registers[1] -= registers[4];
        } else {
            //controlling constant value valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("SUB Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            //subtraction 
            registers[1] -= value;
        }
    } else if (leftOperand == "R3") {

        if (rightOperand == "R1") {
            registers[2] -= registers[0];
        } else if (rightOperand == "R2") {
            registers[2] -= registers[1];
        } else if (rightOperand == "R3") {
            registers[2] -= registers[2];
        } else if (rightOperand == "R4") {
            registers[2] -= registers[3];
        } else if (rightOperand == "R5") {
            registers[2] -= registers[4];
        } else {
            //controlling constant value valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("SUB Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            //subtraction 
            registers[2] -= value;
        }
    } else if (leftOperand == "R4") {

        if (rightOperand == "R1") {
            registers[3] -= registers[0];
        } else if (rightOperand == "R2") {
            registers[3] -= registers[1];
        } else if (rightOperand == "R3") {
            registers[3] -= registers[2];
        } else if (rightOperand == "R4") {
            registers[3] -= registers[3];
        } else if (rightOperand == "R5") {
            registers[3] -= registers[4];
        } else {
            //controlling constant value valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("SUB Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            //subtraction 
            registers[3] -= value;
        }
    } else if (leftOperand == "R5") {

        if (rightOperand == "R1") {
            registers[4] -= registers[0];
        } else if (rightOperand == "R2") {
            registers[4] -= registers[1];
        } else if (rightOperand == "R3") {
            registers[4] -= registers[2];
        } else if (rightOperand == "R4") {
            registers[4] -= registers[3];
        } else if (rightOperand == "R5") {
            registers[4] -= registers[4];
        } else {
            //controlling constant value valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("SUB Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            //subtraction 
            registers[4] -= value;
        }
    } else {
        ExitProgram("SUB Instruction: There is an error on left operand!");
    }
    //if option is 1 prints registers value to screen
    if (option) {
        cout << "SUB " << leftOperand << ", " << rightOperand << "— ";
        print();
    }
}

void CPU::PrintInstruction(string instruction) {
    string operand; //constant or register, without spaces
    string unnecessary;
    string OperandWithSpace;
    size_t lastLetterOfOpcode = instruction.find_first_of("N") + 1; // to start from space, added +1 

    OperandWithSpace = instruction.substr(lastLetterOfOpcode, instruction.size() - lastLetterOfOpcode);

    stringstream sstream(OperandWithSpace);
    sstream >> operand; //no spaces

    if (!(operand.size() > 0))
        ExitProgram("PRN Instruction: There is no operand!");

    //if instruction like this PRN R1 asdf
    //"asdf" is unnecessary so we will detect it 
    sstream>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("PRN Instruction: There is an error!");
    }

    //if option is 1 prints registers value to screen
    if (option) {
        cout << "PRN " << operand << "— ";
        print();
    }

    if (operand == "R1") {
        cout << registers[0] << endl;
    } else if (operand == "R2") {
        cout << registers[1] << endl;
    } else if (operand == "R3") {
        cout << registers[2] << endl;
    } else if (operand == "R4") {
        cout << registers[3] << endl;
    } else if (operand == "R5") {
        cout << registers[4] << endl;
    } else {
        //controlling constant value valid
        for (int i = ZERO; i < operand.size(); ++i) {
            if (!isDigit(operand[i])) {
                ExitProgram("PRN Instructor:Error in operand!");
            }
        }
        //after confirmation if  constant is valid 
        //value read using istringstream
        istringstream intstr(operand);
        int value;
        intstr>>value;
        cout << value << endl;
    }
}

void CPU::MoveInstruction(string instruction) {

    string leftOperandWithSpace; //may contains lots of spaces
    string rightOperandWithSpace; //may contains lots of spaces
    string leftOperand; // operand without unnecessary spaces
    string rightOperand; // operand without unnecessary spaces
    string unnecessary; //if instruction line has unnecessary things like:
    //MOV r1 asd , r2 asdfas ;asdf is unnecessary string

    size_t indexOfComma = instruction.find_first_of(",");
    size_t lastLetterOfOpcode = instruction.find_first_of("V") + 1; // index of first space  after opcode



    leftOperandWithSpace = instruction.substr(lastLetterOfOpcode, indexOfComma - lastLetterOfOpcode);
    rightOperandWithSpace = instruction.substr(indexOfComma + 1, instruction.size()-(indexOfComma));

    stringstream leftOp(leftOperandWithSpace);
    leftOp>>leftOperand; //without space

    stringstream rightOp(rightOperandWithSpace);
    rightOp>>rightOperand; //without space

    if (!(rightOperand.size() > 0))
        ExitProgram("MOV Instruction: There is no right operand!");

    //if instruction like this MOV R1 ab , R2 ab ;
    //"ab" is unnecessary so we will detect it 
    leftOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("MOV Instruction: There is an error!");
    }
    rightOp>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("MOV Instruction: There is an error!");
    }

    if (leftOperand == "R1") {
        if (rightOperand == "R1") {
            registers[0] = registers[0];
        } else if (rightOperand == "R2") {
            registers[1] = registers[0];
        } else if (rightOperand == "R3") {
            registers[2] = registers[0];
        } else if (rightOperand == "R4") {
            registers[3] = registers[0];
        } else if (rightOperand == "R5") {
            registers[4] = registers[0];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("MOV Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[0] = value;
        }
    } else if (leftOperand == "R2") {

        if (rightOperand == "R1") {
            registers[0] = registers[1];
        } else if (rightOperand == "R2") {
            registers[1] = registers[1];
        } else if (rightOperand == "R3") {
            registers[2] = registers[1];
        } else if (rightOperand == "R4") {
            registers[3] = registers[1];
        } else if (rightOperand == "R5") {
            registers[4] = registers[1];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("MOV Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[1] = value;
        }
    } else if (leftOperand == "R3") {

        if (rightOperand == "R1") {
            registers[0] = registers[2];
        } else if (rightOperand == "R2") {
            registers[1] = registers[2];
        } else if (rightOperand == "R3") {
            registers[2] = registers[2];
        } else if (rightOperand == "R4") {
            registers[3] = registers[2];
        } else if (rightOperand == "R5") {
            registers[4] = registers[2];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("MOV Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[2] = value;
        }
    } else if (leftOperand == "R4") {

        if (rightOperand == "R1") {
            registers[0] = registers[3];
        } else if (rightOperand == "R2") {
            registers[1] = registers[3];
        } else if (rightOperand == "R3") {
            registers[2] = registers[3];
        } else if (rightOperand == "R4") {
            registers[3] = registers[3];
        } else if (rightOperand == "R5") {
            registers[4] = registers[3];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("MOV Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[3] = value;
        }
    } else if (leftOperand == "R5") {

        if (rightOperand == "R1") {
            registers[0] = registers[4];
        } else if (rightOperand == "R2") {
            registers[1] = registers[4];
        } else if (rightOperand == "R3") {
            registers[2] = registers[4];
        } else if (rightOperand == "R4") {
            registers[3] = registers[4];
        } else if (rightOperand == "R5") {
            registers[4] = registers[4];
        } else {
            //controlling if constant value is valid
            for (int i = ZERO; i < rightOperand.size(); ++i) {
                if (!isDigit(rightOperand[i])) {
                    ExitProgram("MOV Instruction: There is an error on right operand!");
                }
            }
            //after confirmation if  constant is valid 
            //value read using istringstream
            istringstream intstr(rightOperand);
            int value;
            intstr>>value;
            registers[4] = value;
        }
    } else {
        ExitProgram("MOV Instruction: There is an error on left operand!");
    }
    //if option is 1 prints registers value to screen
    if (option) {
        cout << "MOV " << leftOperand << ", " << rightOperand << "— ";
        print();
    }

}

void CPU::ExitProgram(string message) {
    cout << message << endl;
    exit(1);
}

bool CPU::isDigit(char ch) {
    if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5')
        return true;
    else if (ch == '6' || ch == '7' || ch == '8' || ch == '9')
        return true;
    else
        return false;
}

