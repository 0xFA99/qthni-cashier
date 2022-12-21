#ifndef QTHNI_MEMBEROBJECT_P_H
#define QTHNI_MEMBEROBJECT_P_H

#include <QImage>
#include <QVector>

class MemberObject;
class MemberObjectPrivate
{
    Q_DISABLE_COPY(MemberObjectPrivate)
    Q_DECLARE_PUBLIC(MemberObject)

public:
    explicit MemberObjectPrivate(MemberObject *q);
    ~MemberObjectPrivate();

    void init();

    MemberObject *const     q_ptr;
    QImage                  m_image;
    QString                 m_name;
    QString                 m_id;

    QVector<IObserver *>    m_observerList;
};

#endif //QTHNI_MEMBEROBJECT_P_H
