#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

#include "IObserver.H"
#include "ISubject.H"



class Observer : public IObserver {
public:
    Observer(ISubject &subject);
    virtual ~Observer();
    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();

private:
    std::string message_from_subject_;
    ISubject &subject_;
    static int static_number_;
    int number_;
};



#endif 