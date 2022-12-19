#ifndef QTHNI_EXTENDITEM_H
#define QTHNI_EXTENDITEM_H

#include <QWidget>

class ExtendItemPrivate;
class ExtendItem : public QWidget
{
    Q_OBJECT

public:
    explicit ExtendItem(QWidget *parent = nullptr);
    ~ExtendItem();

    void setImage(const QImage &image);
    [[nodiscard]] QImage image() const;

    void setTitle(const QString &text);
    [[nodiscard]] QString title() const;

    void setTitleColor(const QColor &color);
    [[nodiscard]] QColor titleColor() const;

    void setTitleSize(int size);
    [[nodiscard]] int titleSize() const;

    [[nodiscard]] int amount() const;

    void setAmountColor(const QColor &color);
    [[nodiscard]] QColor amountColor() const;

    void setAmountSize(int size);
    [[nodiscard]] int amountSize() const;

protected:
    const QScopedPointer<ExtendItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ExtendItem)
    Q_DECLARE_PRIVATE(ExtendItem)
};

#endif //QTHNI_EXTENDITEM_H
