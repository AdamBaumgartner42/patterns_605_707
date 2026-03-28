#include "ChangeManager.H"
#include <map>
#include <list>

// Reference
// std::map<Subject*, std::list<Observer*>> subjectObserverMap;

void ChangeManager::Register(Subject* subject, IObserver* observer)
{
    auto& observers = subjectObserverMap[subject];

    // Only Add 
    auto it = std::find(observers.begin(), observers.end(), observer) {
        if (it == observers.end()) {
            observers.push_back 
        }
    }
}

void ChangeManager::Unregister(Subject* subject, IObserver* observer)
{
    // Check that subject exists
    auto it = subjectObserverMap.find(subject);
    if (it == subjectObserverMap.end()){
        return;
    }

    // get the list of observers for the subject
    auto& observers = it->second; 
    
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end()
    );
}

void ChangeManager::Notify(Subject* subject) override {
    auto it = subjectObserverMap.find(subject);
    if (it == subjectObserverMap.end()){
        return;
    }

    for (Observer* observer : it->second) {
        observer->Update(subject);
    }
}

