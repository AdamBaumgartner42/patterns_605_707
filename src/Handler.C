#include "Handler.H"

void Handler::setNext(std::shared_ptr<Node_Impl> n){
    Handler::next = n;
}