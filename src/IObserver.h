#ifndef IOBSERVER_H
#define IOBSERVER_H


class IObserver {
public:
    virtual void Update(const std::string &message_from_subject);
};

#endif