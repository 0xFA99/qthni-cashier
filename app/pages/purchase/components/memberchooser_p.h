#ifndef QTHNI_MEMBERCHOOSER_P_H
#define QTHNI_MEMBERCHOOSER_P_H

#include <QtCore>

class MemberChooser;
class MemberChooserPrivate
{
    Q_DISABLE_COPY(MemberChooserPrivate)
    Q_DECLARE_PUBLIC(MemberChooser)

public:
    explicit MemberChooserPrivate(MemberChooser *q);
    ~MemberChooserPrivate();

    void init();

    MemberChooser *const    q_ptr;
    QStringList             m_memberList;
};

#endif //QTHNI_MEMBERCHOOSER_P_H
