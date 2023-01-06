#ifndef QTHNI_OPERATEITEM_H
#define QTHNI_OPERATEITEM_H

#include "interfaces/IItem.h"
#include "interfaces/IObserver.h"

#include <QWidget>
#include <QUuid>

class OperateItemPrivate;
class OperateItem : public QWidget, public IObserver, public IItem
{
    Q_OBJECT

public:
    explicit OperateItem(QWidget *parent = nullptr);
    ~OperateItem();

    void Update(const QImage &, const QString &, const QString &) override;
    void ExtraUpdate(const QUuid&, int, int, int, int) override;

    void setImage(const QImage &) override;

    void setTitle(const QString &) override;
    void setTitleColor(const QColor &) override;

    void setSubTitle(const QString &) override;
    void setSubTitleColor(const QColor &) override;

    void setUUID(QUuid);
    [[nodiscard]] QUuid uuid() const;

signals:
    void s_editButton(const QUuid &uuid);
    void s_deleteButton(const QUuid &uuid);

protected:
    const QScopedPointer<OperateItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(OperateItem)
    Q_DECLARE_PRIVATE(OperateItem)
};


#endif //QTHNI_OPERATEITEM_H
