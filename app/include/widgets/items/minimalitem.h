#ifndef QTHNI_MINIMALITEM_H
#define QTHNI_MINIMALITEM_H

#include "interfaces/IItem.h"
#include "interfaces/IObserver.h"
#include "interfaces/ISubject.h"

#include <QWidget>

class MinimalItemPrivate;
class MinimalItem : public QWidget, public IObserver, public IItem
{
    Q_OBJECT

public:
    explicit MinimalItem(ISubject &, QWidget *parent = nullptr);
    ~MinimalItem();

    void Update(const QImage&, const QString&, const QString&) override;
    //void extraItem(int) override;
    void ExtraUpdate(const QUuid&, int, int, int, int) override;

    void setImage(const QImage&) override;

    void setTitle(const QString&) override;
    void setTitleColor(const QColor&) override;

    void setSubTitle(const QString&) override;
    void setSubTitleColor(const QColor&) override;

    void removeFromSubject() override;

protected:
    const QScopedPointer<MinimalItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MinimalItem)
    Q_DECLARE_PRIVATE(MinimalItem)

    ISubject &m_subject;
};

#endif //QTHNI_MINIMALITEM_H
