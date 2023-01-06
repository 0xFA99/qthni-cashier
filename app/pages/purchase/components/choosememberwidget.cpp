#include "purchase/components/choosememberwidget.h"
#include "purchase/components/choosememberwidget_p.h"

#include <QVBoxLayout>

ChooseMemberWidgetPrivate::ChooseMemberWidgetPrivate(ChooseMemberWidget *q)
    : q_ptr(q)
{
}

ChooseMemberWidgetPrivate::~ChooseMemberWidgetPrivate() = default;

void ChooseMemberWidgetPrivate::init()
{
    Q_Q(ChooseMemberWidget);

    m_layout        = new QVBoxLayout(q);
    m_autoComplete  = new QtMaterialAutoComplete(q);
    m_submitButton  = new QtMaterialFlatButton("SELESAI", q);
    m_memberList    = QStringList();

    m_memberList << "Konsumen" << "Margaret" << "Sebas";

    m_autoComplete->setLabel("Nama Member");
    m_autoComplete->setDataSource(m_memberList);

    m_submitButton->setHaloVisible(false);
    m_submitButton->setRole(Material::Primary);
    m_submitButton->setRippleStyle(Material::NoRipple);
    m_submitButton->setOverlayStyle(Material::TintedOverlay);
    m_submitButton->setIcon(QtMaterialTheme::icon("action", "done"));

    m_layout->addWidget(m_autoComplete);
    m_layout->addStretch(1);
    m_layout->addWidget(m_submitButton);

    QObject::connect(m_submitButton, &QPushButton::clicked, [=]() {
        q->hideChooseMember(m_autoComplete->text());
    });
}

ChooseMemberWidget::ChooseMemberWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ChooseMemberWidgetPrivate(this))
{
    d_func()->init();

    setMinimumHeight(500);
}

ChooseMemberWidget::~ChooseMemberWidget() = default;
