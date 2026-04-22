#include <iostream>
#include "Command.H"

void Receiver::RunSerialTask() const {
    std::cout << "Receiver: running serial task\n";
}

RunSerial::RunSerial(const Receiver& receiver) : m_receiver(receiver) {}

void RunSerial::Execute() const {
    m_receiver.RunSerialTask();
}

