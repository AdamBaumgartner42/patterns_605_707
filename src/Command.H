#ifndef COMMAND_H
#define COMMAND_H

class Receiver {
public:
    void RunSerialTask() const;
    
};

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() const = 0;
};

class RunSerial : public Command {
private:
    const Receiver& m_receiver;

public:
    RunSerial(const Receiver& receiver);
    void Execute() const override;
};




#endif 