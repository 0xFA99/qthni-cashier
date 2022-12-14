#ifndef QTHNI_MINIMALITEM_H
#define QTHNI_MINIMALITEM_H

#include <QWidget>

class MinimalItemPrivate;
class MinimalItem : public QWidget
{
    Q_OBJECT

public:
    explicit MinimalItem(QWidget *parent = nullptr);
    explicit MinimalItem(const QString &title, const QString &extra, QWidget *parent = nullptr);
    ~MinimalItem();

    void setTitle(const QString &title);
    QString title() const;

    void setExtraTitle(const QString &extra);
    QString extraTitle() const;

    void setAvatarImage(const QImage &image);

protected:
    const QScopedPointer<MinimalItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MinimalItem)
    Q_DECLARE_PRIVATE(MinimalItem)
};

#endif //QTHNI_MINIMALITEM_H
