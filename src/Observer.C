#include <iostream>
#include "Observer.H"

int Observer::static_number_ = 0;

Observer::Observer(ISubject &subject) : subject_(subject)
{
    this->subject_.Attach(this);
    this->number_= ++Observer::static_number_;
    std::cout << "Hi, I'm the observer \"" << this->number_ << "\".\n";
}

Observer::~Observer()
{
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void Observer::Update(ISubject* subject)
{
    subject_message_ = subject->getMessage();
    PrintInfo();
}

void Observer::RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}

void Observer::PrintInfo() {
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->subject_message_ << "\n";
}