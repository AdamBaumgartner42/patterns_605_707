
#include "Mediator.H"

void BaseComponent::set_mediator(Mediator *mediator) {
    this->mediator_ = mediator;
}

ConcreteMediator::ConcreteMediator(Builder *c1, Observer *c2) : builder_(c1), observer_(c2) {
    this->builder_->set_mediator(this);
    this->observer_->set_mediator(this);
}