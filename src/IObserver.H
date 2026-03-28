#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>

class ISubject; // forward declaration

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void Update(ISubject* subject) = 0;
};

#endif