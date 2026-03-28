#ifndef ICHANGEMANAGER_H
#define ICHANGEMANAGER_H

#include "IObserver.H"


class IChangeManager {
public:
    virtual ~IChangeManager() = default;
    virtual void Register(ISubject* subject, IObserver *observer) = 0;
    virtual void Unregister(ISubject* subject, IObserver *observer) = 0;
    virtual void Notify(ISubject* subject) = 0;
};


#endif