#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <string>

#include "IObserver.H"
#include "ChangeManager.H"

class ISubject {
public:
	virtual ~ISubject() = default;
	virtual void Attach(IObserver *observer) = 0;
	virtual void Detach(IObserver *observer) = 0;
	virtual void Notify() = 0;
	virtual std::string getMessage(void) = 0;
	virtual void setChangeManager(IChangeManager* chman) = 0;
};

#endif