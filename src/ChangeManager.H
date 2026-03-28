#ifndef CHANGEMANAGER_H
#define CHANGEMANAGER_H

#include <map>
#include <list>

#include "IChangeManager.H"


class ChangeManager : public IChangeManager {
private: 
    std::map<Subject*, std::list<IObserver*>> subjectObserverMap;

public:
    void Register(ISubject* subject, IObserver* observer) override;
    void Unregister(ISubject* subject, IObserver* observer) override;
    void Notify(ISubject* subject) override;
};





#endif