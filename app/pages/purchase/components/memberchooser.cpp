#include "purchase/components/memberchooser.h"
#include "purchase/components/memberchooser_p.h"

MemberChooserPrivate::MemberChooserPrivate(MemberChooser *q)
    : q_ptr(q)
{
}

MemberChooserPrivate::~MemberChooserPrivate() = default;

void MemberChooserPrivate::init()
{
    Q_Q(MemberChooser);

    m_memberList = QStringList {"Customer", "Sebas", "Margaret"};
}

MemberChooser::MemberChooser(QWidget *parent)
    : QtMaterialAutoComplete(parent)
    , d_ptr(new MemberChooserPrivate(this))
{
    d_func()->init();

    initMemberList();
}

MemberChooser::~MemberChooser() = default;

void MemberChooser::initMemberList()
{
    Q_D(MemberChooser);

    setDataSource(d->m_memberList);
}