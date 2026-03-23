#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Builder.H"
#include "Observer.H"

class Builder;
class Observer;

class BaseComponent;
class Mediator {
};


class BaseComponent {
protected:
    Mediator *mediator_;

public:
    void set_mediator(Mediator *mediator);
};


class ConcreteMediator : public Mediator {
private:
    Builder *builder_;
    Observer *observer_;

public:
    ConcreteMediator(Builder *c1, Observer *c2);

};



#endif