#include "widgets/items/extenditem.h"
#include "widgets/items/extenditem_p.h"

#include <QHBoxLayout>

ExtendItemPrivate::ExtendItemPrivate(ExtendItem *q)
    : q_ptr(q)
{
}

ExtendItemPrivate::~ExtendItemPrivate() = default;

void ExtendItemPrivate::init()
{
    Q_Q(ExtendItem);

    m_layout            = new QHBoxLayout(q);
    m_avatar            = new QtMaterialAvatar(QImage(":/images/images/profiles/defaultimage.png"), q);
    m_title             = new QLabel("Untitled", q);
    m_amount            = new QLabel("1", q);
    m_decreaseButton    = new QtMaterialFlatButton(q);
    m_increaseButton    = new QtMaterialFlatButton(q);

    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QFont font("Roboto", 12, QFont::Normal);
    m_title->setFont(font);
    m_amount->setFont(font);

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    font.setFamily("iconfont");
    font.setPixelSize(18);

    m_decreaseButton->setFont(font);
    m_decreaseButton->setRole(Material::Primary);
    m_decreaseButton->setText("\uE621");
    m_decreaseButton->setHaloVisible(false);
    m_decreaseButton->setSizePolicy(sizePolicy);

    m_increaseButton->setFont(font);
    m_increaseButton->setRole(Material::Primary);
    m_increaseButton->setText("\uE62D");
    m_increaseButton->setHaloVisible(false);
    m_increaseButton->setSizePolicy(sizePolicy);

    int cr = m_increaseButton->sizeHint().height() / 2;
    m_decreaseButton->setCornerRadius(cr);
    m_increaseButton->setCornerRadius(cr);

    m_layout->addWidget(m_avatar);
    m_layout->addWidget(m_title);
    m_layout->addStretch(1);
    m_layout->addWidget(m_decreaseButton);
    m_layout->addWidget(m_amount);
    m_layout->addWidget(m_increaseButton);
    m_layout->setContentsMargins(0, 10, 0, 0);

    QObject::connect(m_decreaseButton, &QPushButton::clicked, [=]() {
        int temp = m_amount->text().toInt();
        if (temp > 1) {
            temp--;
            m_amount->setText(QString::number(temp));
            q->updateAmount(temp);
            q->changeSubPrice(m_uuid, (m_memberPrice * temp));
            q->changeDiscount(m_uuid, (m_customerPrice * temp));
        }
    });


    QObject::connect(m_increaseButton, &QPushButton::clicked, [=]() {
        int temp = m_amount->text().toInt();
        if (temp < m_stock) {
            temp++;
            m_amount->setText(QString::number(temp));
            q->updateAmount(temp);
            q->changeSubPrice(m_uuid, (m_memberPrice * temp));
            q->changeDiscount(m_uuid, (m_customerPrice * temp));
        }
    });
}

ExtendItem::ExtendItem(ISubject &subject, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ExtendItemPrivate(this))
    , m_subject(subject)
{
    d_func()->init();

    this->m_subject.Attach(this);
}

ExtendItem::~ExtendItem() = default;

void ExtendItem::ExtraUpdate(const QUuid &tagUUID, int memPrice, int cusPrice, int point, int stock)
{
    Q_D(ExtendItem);
    if (d->m_amount->text().toInt() > stock) {
        d->m_amount->setText(QString::number(stock));
    }

    setStock(stock);
    setMemberPrice(memPrice);
    setCustomerPrice(cusPrice);
}

void ExtendItem::Update(const QImage &image, const QString& title, const QString& subTitle)
{
    Q_D(ExtendItem);

    setImage(image);
    setTitle(title);
}

void ExtendItem::removeFromSubject()
{
    m_subject.Detach(this);
}

void ExtendItem::setImage(const QImage &image)
{
    Q_D(ExtendItem);

    d->m_avatar->setImage(image);
}

void ExtendItem::setTitle(const QString &text)
{
    Q_D(ExtendItem);

    d->m_title->setText(text);
}

void ExtendItem::setTitleColor(const QColor &color)
{
    Q_D(ExtendItem);

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

void ExtendItem::setSubTitle(const QString &)
{
    Q_D(ExtendItem);
}

void ExtendItem::setSubTitleColor(const QColor &)
{
    Q_D(const ExtendItem);
}

void ExtendItem::setStock(int stock)
{
    Q_D(ExtendItem);

    d->m_stock = stock;
}

void ExtendItem::setMemberPrice(int price)
{
    Q_D(ExtendItem);

    d->m_memberPrice = price;
}

int ExtendItem::memberPrice() const
{
    Q_D(const ExtendItem);

    return d->m_memberPrice;
}

void ExtendItem::setCustomerPrice(int price)
{
    Q_D(ExtendItem);

    d->m_customerPrice = price;
}

int ExtendItem::customerPrice() const
{
    Q_D(const ExtendItem);

    return d->m_customerPrice;
}

void ExtendItem::setUUID(const QUuid &uuid)
{
    Q_D(ExtendItem);

    d->m_uuid = uuid;
}

QUuid ExtendItem::uuid() const
{
    Q_D(const ExtendItem);

    return d->m_uuid;
}