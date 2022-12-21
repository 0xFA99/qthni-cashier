#ifndef QTHNI_IITEM_H
#define QTHNI_IITEM_H

class QImage;
class QColor;
class QString;

class IItem
{
public:
    ~IItem() = default;
    virtual void setImage(const QImage &) = 0;

    virtual void setTitle(const QString &) = 0;
    virtual void setTitleColor(const QColor &) = 0;

    virtual void setSubTitle(const QString &) = 0;
    virtual void setSubTitleColor(const QColor &) = 0;
};

#endif //QTHNI_IITEM_H
