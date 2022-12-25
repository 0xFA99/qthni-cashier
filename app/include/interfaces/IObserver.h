#ifndef QTHNI_IOBSERVER_H
#define QTHNI_IOBSERVER_H

class QImage;
class QString;

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void Update(const QImage &, const QString &, const QString &) = 0;
    virtual void extraItem(int) {};
};

#endif //QTHNI_IOBSERVER_H
