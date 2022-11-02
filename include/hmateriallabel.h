#ifndef HMATERIALLABEL_H
#define HMATERIALLABEL_H

#include <QLabel>

class HMaterialLabelPrivate;
class HMaterialLabel : public QLabel
{
    Q_OBJECT

public:
    explicit HMaterialLabel(QWidget *parent = nullptr);
    explicit HMaterialLabel(const QString &text, QWidget *parent = nullptr);
    ~HMaterialLabel();

    void setFontSize(int size);
    int fontSize() const;

    void setFontWeight(QFont::Weight weight);
    QFont::Weight fontWeight() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

protected:
    const QScopedPointer<HMaterialLabelPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialLabel);
    Q_DECLARE_PRIVATE(HMaterialLabel);
};

#endif
