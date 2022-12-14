#ifndef QTHNI_DEFAULTITEM_H
#define QTHNI_DEFAULTITEM_H

#include <QWidget>

class DefaultItemPrivate;
class DefaultItem : public QWidget
{
    Q_OBJECT

public:
    explicit DefaultItem(QWidget *parent = nullptr);
    ~DefaultItem();

    void setTitle(const QString &text);
    QString title() const;

    void setTitleColor(const QColor &color);
    QColor titleColor() const;

    void setTitleSize(int size);
    int titleSize() const;

    void setSubTitle(const QString &text);
    QString subTitle() const;

    void setSubTitleColor(const QColor &color);
    QColor subTitleColor() const;

    void setSubTitleSize(int size);
    int subTitleSize() const;

    void setExtraTitle(const QString &text);
    QString extraTitle() const;

    void setExtraTitleColor(const QColor &text);
    QColor extraTitleColor() const;

    void setExtraTitleSize(int size);
    int extraTitleSize() const;

    void setImage(const QImage &image);
    void removeImage();

protected:
    const QScopedPointer<DefaultItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(DefaultItem)
    Q_DECLARE_PRIVATE(DefaultItem)
};

#endif //QTHNI_DEFAULTITEM_H
