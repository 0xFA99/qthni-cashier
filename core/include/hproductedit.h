#ifndef HPRODUCTEDIT_H
#define HPRODUCTEDIT_H

#include <QWidget>

class HProduct;
class HProductEditPrivate;
class HProductEdit : public QWidget
{
Q_OBJECT

public:
    explicit HProductEdit(QWidget *parent = nullptr);
    ~HProductEdit();

    enum Mode { AddMode, EditMode };

    void setTargetProduct(HProduct *);

    void setMode(Mode mode);

public slots:
    void addSlot();
    void editSlot();

signals:
    void hideDialog();
    void addSignal(const QImage &, const QString &, int, int);

protected:
    const QScopedPointer<HProductEditPrivate> d_ptr;

private:
    void setEmptyField();
    void editMode();
    void addMode();

    Q_DISABLE_COPY(HProductEdit)
    Q_DECLARE_PRIVATE(HProductEdit)
};

#endif

