#include "purchase/components/membernamewidget.h"
#include "purchase/components/membernamewidget_p.h"

#include <QHBoxLayout>
#include <QLabel>

MemberNameWidgetPrivate::MemberNameWidgetPrivate(MemberNameWidget *q)
    : q_ptr(q)
{
}

MemberNameWidgetPrivate::~MemberNameWidgetPrivate() = default;

void MemberNameWidgetPrivate::init()
{
    Q_Q(MemberNameWidget);

    m_layout        = new QHBoxLayout(q);
    m_memberName    = new QLabel("Customer", q);
    m_changeButton  = new QtMaterialFlatButton("\uE674", q);

    m_layout->addWidget(m_memberName);
    m_layout->addWidget(m_changeButton);
    m_layout->setContentsMargins(0, 0, 0, 0);

    m_memberName->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);

    QFont font("iconfont", 18, QFont::Normal);
    m_changeButton->setFont(font);
    m_changeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_changeButton->setHaloVisible(false);
    m_changeButton->setRole(Material::Primary);
    m_changeButton->setRippleStyle(Material::NoRipple);
    m_changeButton->setOverlayStyle(Material::TintedOverlay);
    m_changeButton->setCornerRadius(m_changeButton->sizeHint().height() / 2);

    QObject::connect(m_changeButton, &QPushButton::clicked, [q]() {
        q->changeMember();
    });
}

MemberNameWidget::MemberNameWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MemberNameWidgetPrivate(this))
{
    d_func()->init();
}

MemberNameWidget::~MemberNameWidget() = default;

void MemberNameWidget::changeMemberName(const QString &name)
{
    Q_D(MemberNameWidget);

    d->m_memberName->setText(name);

    if (name != "Konsumen") {
        memberChoosen(true);
    } else {
        memberChoosen(false);
    }
}