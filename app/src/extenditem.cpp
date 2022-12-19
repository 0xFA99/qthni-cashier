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
    m_avatar            = new QtMaterialAvatar(q);
    m_title             = new QLabel("Untitled", q);
    m_amount            = new QLabel("1", q);
    m_decreaseButton    = new QtMaterialFlatButton(q);
    m_increaseButton    = new QtMaterialFlatButton(q);
    m_removeButton      = new QtMaterialFlatButton(q);

    m_titleSize = m_amountSize = 12;

    m_avatar->setLetter(QChar('A'));
    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QFont font("Roboto", m_titleSize, QFont::Normal);
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

    m_removeButton->setFont(font);
    m_removeButton->setText("\uE63A");
    m_removeButton->setHaloVisible(false);
    m_removeButton->setRole(Material::Secondary);
    m_removeButton->setSizePolicy(sizePolicy);

    int cr = m_increaseButton->sizeHint().height() / 2;
    m_decreaseButton->setCornerRadius(cr);
    m_increaseButton->setCornerRadius(cr);
    m_removeButton->setCornerRadius(cr);

    m_layout->addWidget(m_avatar);
    m_layout->addWidget(m_title);
    m_layout->addStretch(1);
    m_layout->addWidget(m_decreaseButton);
    m_layout->addWidget(m_amount);
    m_layout->addWidget(m_increaseButton);
    m_layout->addWidget(m_removeButton);
    m_layout->setContentsMargins(0, 10, 0, 0);

    QObject::connect(m_decreaseButton, &QPushButton::clicked, [=]() {
        int temp = m_amount->text().toInt();
        if (temp > 1) temp--;
        m_amount->setText(QString::number(temp));
    });

    QObject::connect(m_increaseButton, &QPushButton::clicked, [=]() {
        int temp = m_amount->text().toInt();
        m_amount->setText(QString::number(temp + 1));
    });
}

ExtendItem::ExtendItem(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ExtendItemPrivate(this))
{
    d_func()->init();
}

ExtendItem::~ExtendItem() = default;

void ExtendItem::setImage(const QImage &image)
{
    Q_D(ExtendItem);

    d->m_avatar->setImage(image);
}

QImage ExtendItem::image() const
{
    Q_D(const ExtendItem);

    return d->m_avatar->image();
}

void ExtendItem::setTitle(const QString &text)
{
    Q_D(ExtendItem);

    d->m_title->setText(text);
}

QString ExtendItem::title() const
{
    Q_D(const ExtendItem);

    return d->m_title->text();
}

void ExtendItem::setTitleColor(const QColor &color)
{
    Q_D(ExtendItem);

    d->m_titleColor = color;

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

QColor ExtendItem::titleColor() const
{
    Q_D(const ExtendItem);

    return d->m_titleColor;
}

void ExtendItem::setTitleSize(int size)
{
    Q_D(ExtendItem);

    d->m_titleSize = size;

    QFont font = d->m_title->font();
    font.setPointSize(size);
    d->m_title->setFont(font);
}

int ExtendItem::titleSize() const
{
    Q_D(const ExtendItem);

    return d->m_titleSize;
}

int ExtendItem::amount() const
{
    Q_D(const ExtendItem);

    return d->m_amount->text().toInt();
}

void ExtendItem::setAmountColor(const QColor &color)
{
    Q_D(ExtendItem);

    d->m_amountColor = color;

    QPalette palette = d->m_amount->palette();
    palette.setColor(d->m_amount->foregroundRole(), color);
    d->m_amount->setPalette(palette);
}

QColor ExtendItem::amountColor() const
{
    Q_D(const ExtendItem);

    return d->m_amountColor;
}

void ExtendItem::setAmountSize(int size)
{
    Q_D(ExtendItem);

    d->m_amountSize = size;

    QFont font = d->m_amount->font();
    font.setPointSize(size);
    d->m_amount->setFont(font);
}

int ExtendItem::amountSize() const
{
    Q_D(const ExtendItem);

    return d->m_amountSize;
}
