#include <iostream>
#include "Command.H"

RunSerial::RunSerial() = default;


void RunSerial::Execute() const {

    std::cout << "Hello World\n" ;
}