#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() const = 0;
};

class RunSerial : public Command {
public:
    RunSerial();
    void Execute() const override;
};

class Receiver {
public:
    
};




#endif 