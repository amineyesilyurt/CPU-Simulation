/* Amine Yesilyurt - 131044004 HW01 */
#include <iostream>
#include <cstdlib> //used only for exit
#include <string>
#include <fstream>
#include <sstream>  //only for eliminate spaces and getting integer
#include "cpu.h"

using namespace std;

void toUppercase(string & strWithLowercase) {
    for (int index = ZERO; index < strWithLowercase.size(); ++index) {
        if (strWithLowercase[index] >= 'a' && strWithLowercase[index] <= 'z')
            strWithLowercase[index] = strWithLowercase[index] -('a' - 'A');
    }
}

bool isDigit(char ch) {
    if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5')
        return true;
    else if (ch == '6' || ch == '7' || ch == '8' || ch == '9')
        return true;
    else
        return false;
}

int getNumberOfLine(const char* filename) {

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

void getInstructions(const char* filename, string instruction[]) {

    ifstream inStream; //for input file
    int index = ZERO;
    size_t indexSemicolon; //index of semicolon;

    //opened input file
    inStream.open(filename);
    //controlled if opening input file failed
    if (inStream.fail()) {
        cerr << "Opening input file o failed!" << endl;
        exit(1);
    }
    // gets every line from file and inserts them to instruction array 
    while (!inStream.eof()) {
        getline(inStream, instruction[index]);
        //determined index of semicolon
        indexSemicolon = instruction[index].find_first_of(";");
        //deleted semicolon and string after semicolon from instruction   
        if (indexSemicolon) {
            string noCommentLine = instruction[index].substr(0, indexSemicolon);
            //line converted to uppercase
            toUppercase(noCommentLine);
            instruction[index] = noCommentLine;
        }
        ++index;
    }
    //closed input file
    inStream.close();
}

void ExitProgram(string message) {
    cout << message << endl;
    exit(1);
}

void SubInstruction(string instruction, int option, int registers[]) {

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
    if (unnecessary.size() > ZERO ) {
        ExitProgram("SUB Instruction: There is an error!");
    }
    rightOp>>unnecessary;
    if (unnecessary.size() > ZERO ) {
        ExitProgram("SUB Instruction: There is an error!");
    }

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
        cout << "R1=" << registers[0] << ",";
        cout << " R2=" << registers[1] << ",";
        cout << " R3=" << registers[2] << ",";
        cout << " R4=" << registers[3] << ",";
        cout << " R5=" << registers[4] << endl;
    }
}

void PrintInstruction(string instruction, int option, int registers[]) {

    string operand; //constant or register, without spaces
    string unnecessary;
    string OperandWithSpace;
    size_t lastLetterOfOpcode = instruction.find_first_of("N") + 1; // to start from space, added +1 

    OperandWithSpace = instruction.substr(lastLetterOfOpcode, instruction.size() - lastLetterOfOpcode);

    stringstream sstream(OperandWithSpace);
    sstream >> operand; //no spaces

    //if instruction like this PRN R1 asdf
    //"asdf" is unnecessary so we will detect it 
    sstream>>unnecessary;
    if (unnecessary.size() > ZERO) {
        ExitProgram("PRN Instruction: There is an error!");
    }
    
    //if option is 1 prints registers value to screen
    if (option) {
        cout << "PRN " << operand << "— ";
        cout << "R1=" << registers[0] << ",";
        cout << " R2=" << registers[1] << ",";
        cout << " R3=" << registers[2] << ",";
        cout << " R4=" << registers[3] << ",";
        cout << " R5=" << registers[4] << endl;
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

void AddInstruction(string instruction, int option, int registers[]) {

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
        cout << "R1=" << registers[0] << ",";
        cout << " R2=" << registers[1] << ",";
        cout << " R3=" << registers[2] << ",";
        cout << " R4=" << registers[3] << ",";
        cout << " R5=" << registers[4] << endl;
    }

}

void MoveInstruction(string instruction, int option, int registers[]) {

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
        cout << "R1=" << registers[0] << ",";
        cout << " R2=" << registers[1] << ",";
        cout << " R3=" << registers[2] << ",";
        cout << " R4=" << registers[3] << ",";
        cout << " R5=" << registers[4] << endl;
    }


}

void JumpInstructionWithTwoOperand(string instruction, int option, int& index, int registers[]) {

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
            index = value - 2; // -2 because of index will increase again in for loop
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
            index = value - 2; // -2 because of index will increase again in for loop
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
            index = value - 2; // -2 because of index will increase again in for loop
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
            index = value - 2; // -2 because of index will increase again in for loop
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
            index = value - 2; // -2 because of index will increase again in for loop
        }

    } else {
        ExitProgram("JMP Instruction: Invalid left operand");
    }
    //if option 1 prints registers value to screen
    if (option) {
        cout << "JMP " << leftOperand << ", " << rightOperand << "— ";
        cout << "R1=" << registers[0] << ",";
        cout << " R2=" << registers[1] << ",";
        cout << " R3=" << registers[2] << ",";
        cout << " R4=" << registers[3] << ",";
        cout << " R5=" << registers[4] << endl;
    }
}

void JumpInstructionWithOneOperand(string instruction, int option, int& index, int registers[]) {

    string operand;
    string unnecessary;
    string OperandWithSpace;
    size_t lastLetterOfOpcode = instruction.find_first_of("P") + 1; // to start space added +1 

    OperandWithSpace = instruction.substr(lastLetterOfOpcode, instruction.size() - lastLetterOfOpcode);

    stringstream sstream(OperandWithSpace);
    sstream >> operand;
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
    index = value - 2; // -2 because of index will increase again in for loop
    //if option 1 prints registers value to screen
    if (option) {
        cout << "JMP " << operand << "— ";
        cout << "R1=" << registers[0] << ",";
        cout << " R2=" << registers[1] << ",";
        cout << " R3=" << registers[2] << ",";
        cout << " R4=" << registers[3] << ",";
        cout << " R5=" << registers[4] << endl;
    }

}

void startCPU(const char* filename, int option, int registers[]) {
    string last;
    string opcode;
    string unnecessary;
    int numberOfInstruction;
    //first determine number of instruction
    numberOfInstruction = getNumberOfLine(filename);
   
    string instruction[numberOfInstruction]; //holds all instruction  
    getInstructions(filename, instruction);//get instruction from file to instruction array 

    for (int index = ZERO; index < numberOfInstruction; ++index) {

        stringstream streamLine(instruction[index]);
        streamLine>>opcode; 

        if (opcode == "HLT") {
            size_t lastLetterOfOpcode = instruction[index].find_first_of("T") + 1; //+1 is space
            last = instruction[index].substr(lastLetterOfOpcode, instruction[index].size() - 3); //3 is lenght of opcode
            stringstream sstream(last);
            sstream>>unnecessary;
            //if there is unnecessary strings in instruction,exit program
            if (unnecessary.size() > ZERO)
                ExitProgram("HLT Instruction: ERROR");
            else {
                //if option is 1
                if (option) {
                    cout << "HLT— ";
                    cout << "R1=" << registers[0] << ",";
                    cout << " R2=" << registers[1] << ",";
                    cout << " R3=" << registers[2] << ",";
                    cout << " R4=" << registers[3] << ",";
                    cout << " R5=" << registers[4] << endl;
                }
                //halts the program and prints on the screen the contents of all registers
                cout << "R1 :" << registers[0] << endl;
                cout << "R2 :" << registers[1] << endl;
                cout << "R3 :" << registers[2] << endl;
                cout << "R4 :" << registers[3] << endl;
                cout << "R5 :" << registers[4] << endl;
                break;
            }
        }

        if (opcode == "JMP") {
            size_t found = instruction[index].find(",");
            //if instruction like : JMP reg,lineAdress
            if (found != string::npos)
                JumpInstructionWithTwoOperand(instruction[index], option, index, registers);

            else //if instruction like : JMP lineAdress
                JumpInstructionWithOneOperand(instruction[index], option, index, registers);
            if (index >= numberOfInstruction || index < ZERO) {
                ExitProgram("JMP ERROR: Out of the range!");
            }

        } else if (opcode == "ADD") {
            AddInstruction(instruction[index], option, registers);
        } else if (opcode == "SUB") {
            SubInstruction(instruction[index], option, registers);
        } else if (opcode == "PRN") {
            PrintInstruction(instruction[index], option, registers);
        } else if (opcode == "MOV") {
            MoveInstruction(instruction[index], option, registers);

        } else {
            cout << "Line:" << index + 1 << " Invalid opcode!" << endl;
            break;
        }
    }
}

