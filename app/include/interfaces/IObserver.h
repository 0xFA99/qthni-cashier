#ifndef QTHNI_IOBSERVER_H
#define QTHNI_IOBSERVER_H

#include <vector>

class QImage;
class QString;
class QUuid;

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void Update(const QImage &, const QString &, const QString &) = 0;

    // For Product Update
                            // tag        mem  cus  poi  sto
    virtual void ExtraUpdate(const QUuid&, int, int, int, int) {};
};

#endif //QTHNI_IOBSERVER_H
