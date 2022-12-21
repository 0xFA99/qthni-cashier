#ifndef QTHNI_OPERATEITEM_H
#define QTHNI_OPERATEITEM_H

#include "interfaces/IItem.h"
#include "interfaces/IObserver.h"
#include <QWidget>

class OperateItemPrivate;
class OperateItem : public QWidget, public IObserver, public IItem
{
    Q_OBJECT

public:
    explicit OperateItem(QWidget *parent = nullptr);
    ~OperateItem();

    void Update(const QImage &, const QString &, const QString &) override;

    void setImage(const QImage &) override;

    void setTitle(const QString &) override;
    void setTitleColor(const QColor &) override;

    void setSubTitle(const QString &) override;
    void setSubTitleColor(const QColor &) override;
    [[nodiscard]] QString subTitle() const;

    void setIndex(int);
    [[nodiscard]] int index() const;

signals:
    void s_editButton(int);
    void s_deleteButton(int);

protected:
    const QScopedPointer<OperateItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(OperateItem)
    Q_DECLARE_PRIVATE(OperateItem)
};


#endif //QTHNI_OPERATEITEM_H
