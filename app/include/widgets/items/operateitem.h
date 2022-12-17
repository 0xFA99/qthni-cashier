#ifndef QTHNI_OPERATEITEM_H
#define QTHNI_OPERATEITEM_H

#include <QWidget>
#include "members/member.h"

class OperateItemPrivate;
class OperateItem : public QWidget
{
    Q_OBJECT

public:
    explicit OperateItem(QWidget *parent = nullptr);
    explicit OperateItem(int index, QWidget *parent = nullptr);
    ~OperateItem();

    void setImage(const QImage &image);
    QImage image() const;

    void setTitle(const QString &text);
    [[nodiscard]] QString title() const;

    void setTitleColor(const QColor &color);
    [[nodiscard]] QColor titleColor() const;

    void setTitleSize(int size);
    [[nodiscard]] int titleSize() const;

    void setSubTitle(const QString &text);
    [[nodiscard]] QString subTitle() const;

    void setSubTitleColor(const QColor &color);
    [[nodiscard]] QColor subTitleColor() const;

    void setSubTitleSize(int size);
    [[nodiscard]] int subTitleSize() const;

    void setIndex(int index);
    int getIndex() const;

signals:
    void editItem(int);
    void deleteItem(int);

protected:
    const QScopedPointer<OperateItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(OperateItem)
    Q_DECLARE_PRIVATE(OperateItem)
};

#endif //QTHNI_OPERATEITEM_H
