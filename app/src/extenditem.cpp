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
    m_removeButton      = new QtMaterialFlatButton(q);

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
        if (temp <= m_stock)
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

void ExtendItem::Update(const QImage &image, const QString& title, const QString& subTitle)
{
    setImage(image);
    setTitle(title);
    // setStock(stock);
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

int ExtendItem::amount() const
{
    Q_D(const ExtendItem);

    return d->m_amount->text().toInt();
}

void ExtendItem::setIndex(int index)
{
    Q_D(ExtendItem);

    d->m_index = index;
}

int ExtendItem::index() const
{
    Q_D(const ExtendItem);

    return d->m_index;
}