#ifndef HANDLER_H
#define HANDLER_H

#include <memory>
#include "Node.H"

class Handler{

protected:
    std::shared_ptr<Node_Impl> next;

public: 
    void setNext(std::shared_ptr<Node_Impl>);

};

#endif