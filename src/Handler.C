#include "Handler.H"

void Handler::setNext(std::shared_ptr<dom::Node> n){
    Handler::next = n;
}