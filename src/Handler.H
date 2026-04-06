#ifndef HANDLER_H
#define HANDLER_H

#include <memory>
#include "Node.H"

class Handler{

protected:
    std::shared_ptr<dom::Node> next;

public: 
    void setNext(std::shared_ptr<dom::Node>);
};

#endif