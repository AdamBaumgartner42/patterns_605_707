#ifndef CHANGEMANAGER_H
#define CHANGEMANAGER_H

#include <map>
#include <list>

#include "IChangeManager.H"


class ChangeManager : public IChangeManager {
private: 
    std::map<ISubject*, std::list<IObserver*>> subjectObserverMap;

public:
	ChangeManager() {}
    virtual void Register(ISubject* subject, IObserver* observer) override;
    virtual void Unregister(ISubject* subject, IObserver* observer) override;
    virtual void Notify(ISubject* subject) override;
};





#endif