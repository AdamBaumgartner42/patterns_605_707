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

void Observer::Update(const std::string &message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}

void PrintInfo() {
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}