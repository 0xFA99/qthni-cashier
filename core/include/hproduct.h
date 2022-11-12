#ifndef HNILIB_HPRODUCT_H
#define HNILIB_HPRODUCT_H

#include <QObject>

class HProductPrivate;
class HProduct : public QObject
{
    Q_OBJECT

public:
    explicit HProduct(QObject *parent = nullptr);
    ~HProduct();

    void setImage(const QImage &image);
    QImage image() const;

    void setName(const QString &name);
    QString name() const;

    void setPrice(int price);
    int price() const;

    void setStock(int value);
    int stock() const;

public slots:
    void updateSlot();

signals:
    void updateSignal(HProduct *);

protected:
    const QScopedPointer<HProductPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProduct)
    Q_DECLARE_PRIVATE(HProduct)
};

#endif
