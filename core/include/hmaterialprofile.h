#ifndef HMATERIALPROFILE_H
#define HMATERIALPROFILE_H

#include "hmaterialframe.h"

class HMaterialProfilePrivate;
class HMaterialProfile : public HMaterialFrame
{
    Q_OBJECT

public:
    HMaterialProfile(QWidget *parent = nullptr);
    HMaterialProfile(const QString &name, const QString &id, QWidget *parent = nullptr);
    ~HMaterialProfile();

    void setImage(const QImage &image);

    void setName(const QString &name);

    void setId(const QString &id);

protected:
    const QScopedPointer<HMaterialProfilePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialProfile)
    Q_DECLARE_PRIVATE(HMaterialProfile)
};

#endif
