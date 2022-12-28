#ifndef QTHNI_ISUBJECT_H
#define QTHNI_ISUBJECT_H

#include "interfaces/IObserver.h"

class ISubject
{
public:
    virtual ~ISubject(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Update() = 0;
};

#endif //QTHNI_ISUBJECT_H
