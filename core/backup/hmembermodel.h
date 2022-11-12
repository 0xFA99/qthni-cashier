#ifndef HMEMBERMODEL_H
#define HMEMBERMODEL_H

#include <QWidget>

class HMemberModelPrivate;
class HMemberModel : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberModel(QWidget *parent = nullptr);
    ~HMemberModel();

    void setImage(const QImage &image);
    QImage getImage() const;

    void setName(const QString &name);
    QString getName() const;

    void setID(const QString &id);
    QString getID() const;

public slots:
    void editSlot();
    void removeSlot();

signals:
    void editMember();
    void removeMember();

protected:
    const QScopedPointer<HMemberModelPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberModel)
    Q_DECLARE_PRIVATE(HMemberModel)
};

#endif
