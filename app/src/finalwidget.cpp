#include "widgets/items/finalwidget.h"
#include "widgets/items/finalwidget_p.h"

#include <QHBoxLayout>
#include <QLabel>

FinalWidgetPrivate::FinalWidgetPrivate(FinalWidget *q)
    : q_ptr(q)
{
}

FinalWidgetPrivate::~FinalWidgetPrivate() = default;

void FinalWidgetPrivate::init()
{
    Q_Q(FinalWidget);

    m_layout    = new QHBoxLayout(q);
    m_avatar    = new QtMaterialAvatar(q);
    m_name      = new QLabel(q);
    m_price     = new QLabel(q);
    m_discount  = new QLabel(q);
    m_quantity  = new QLabel(q);
    m_total     = new QLabel(q);
    m_locale    = QLocale("id_ID");
    m_uuid      = nullptr;

    // Set Image Widget
    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Set Font
    QFont font("Roboto", 12, QFont::Normal);
    m_name->setFont(font);
    m_price->setFont(font);
    m_discount->setFont(font);
    m_quantity->setFont(font);
    m_total->setFont(font);

    // Set Alignment
    m_total->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_price->setAlignment(Qt::AlignCenter);
    m_discount->setAlignment(Qt::AlignCenter);
    m_quantity->setAlignment(Qt::AlignCenter);

    // Setup all widget to layout
    m_layout->addWidget(m_avatar);
    m_layout->addWidget(m_name);
    m_layout->addWidget(m_price);
    m_layout->addWidget(m_discount);
    m_layout->addWidget(m_quantity);
    m_layout->addWidget(m_total);
}

FinalWidget::FinalWidget(ISubject &subject, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new FinalWidgetPrivate(this))
    , m_subject(subject)
{
    d_func()->init();

    this->m_subject.Attach(this);
}

FinalWidget::~FinalWidget() = default;

void
FinalWidget::Update(const QImage &image, const QString &title, const QString &subTitle)
{
    setImage(image);
    setTitle(title);
    // setSubTitle(subTitle);
}

void
FinalWidget::ExtraUpdate(const QUuid &tag, int memPrice, int cusPrice, int point, int stock)
{
    Q_D(FinalWidget);

    d->m_price->setText("Rp " + d->m_locale.toString(cusPrice));
    d->m_discount->setText("Rp " + d->m_locale.toString(memPrice));
}

void
FinalWidget::setImage(const QImage &image)
{
    Q_D(FinalWidget);

    d->m_avatar->setImage(image);
}

void
FinalWidget::setTitle(const QString &title)
{
    Q_D(FinalWidget);

    d->m_name->setText(title);
}

void
FinalWidget::setTitleColor(const QColor &color)
{
    Q_D(FinalWidget);

    QPalette palette = d->m_name->palette();
    palette.setColor(d->m_name->foregroundRole(), color);
    d->m_name->setPalette(palette);
}

void
FinalWidget::setSubTitle(const QString &subTitle)
{
    Q_D(FinalWidget);

}

void
FinalWidget::setSubTitleColor(const QColor &color)
{
    Q_D(FinalWidget);

}

void
FinalWidget::removeFromSubject()
{
    m_subject.Detach(this);
}

void
FinalWidget::setUUID(QUuid uuid)
{
    Q_D(FinalWidget);

    d->m_uuid = uuid;
}

QUuid
FinalWidget::uuid() const
{
    Q_D(const FinalWidget);

    return d->m_uuid;
}

void
FinalWidget::changeAmount(int amount)
{
    Q_D(FinalWidget);

    d->m_quantity->setText(QString::number(amount));
}

void
FinalWidget::changeTotal(QUuid uuid, int total)
{
    Q_D(FinalWidget);

    d->m_total->setText("Rp " + d->m_locale.toString(total));
}