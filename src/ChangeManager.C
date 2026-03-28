#include "ChangeManager.H"
#include <map>
#include <list>

void ChangeManager::Register(ISubject* subject, IObserver* observer)
{
    auto& observers = subjectObserverMap[subject];

    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it == observers.end()) {
        observers.push_back(observer); 
    }
    
}

void ChangeManager::Unregister(ISubject* subject, IObserver* observer)
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

void ChangeManager::Notify(ISubject* subject) {
    auto it = subjectObserverMap.find(subject);
    if (it == subjectObserverMap.end()){
        return;
    }

    for (IObserver* observer : it->second) {
        observer->Update(subject);
    }
}

