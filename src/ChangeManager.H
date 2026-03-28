#ifndef CHANGEMANAGER_H
#define CHANGEMANAGER_H

#include "IChangeManager.H"


class ChangeManager : public IChangeManager {
private: 
    std::map<Subject*, std::list<Observer*>> subjectObserverMap;

public:
    void Register(Subject* subject, Observer* observer) override;
    void Unregister(Subject* subject, Observer* observer) override;
    void Notify(Subject* subject) override;
};





#endif