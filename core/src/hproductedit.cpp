#include "hproductedit.h"
#include "hproductedit_p.h"

#include <QLocale>
#include <QGridLayout>

#include "hproduct.h"

HProductEditPrivate::HProductEditPrivate(HProductEdit *q)
    : q_ptr(q)
{
}

HProductEditPrivate::~HProductEditPrivate()
{
}

void HProductEditPrivate::init()
{
    Q_Q(HProductEdit);

    m_layout        = new QGridLayout(q);

    m_image         = new HMaterialAvatar(QImage(":/images/images/default.png"), q);
    m_name          = new HMaterialTextField(q);
    m_price         = new HMaterialTextField(q);
    m_stock         = new HMaterialTextField(q);
    m_imageButton   = new HMaterialFlatButton("\uE626", q);
    m_cancelButton  = new HMaterialFlatButton(q);
    m_submitButton  = new HMaterialFlatButton(q);
    m_mode          = HProductEdit::Mode::AddMode;

    m_price->setCurrencyFormat(true);

    QFont font("iconfont", 12, QFont::Medium);

    m_imageButton->setFont(font);
    m_imageButton->setBackgroundColor(QColor("#f1f4f9"));
    m_imageButton->setForegroundColor(QColor("#545557"));
    m_imageButton->setFixedWidth(m_imageButton->sizeHint().height());
    m_imageButton->setCornerRadius(m_imageButton->sizeHint().height() / 2);
    m_imageButton->setHaloVisible(false);
    m_imageButton->setBackgroundMode(Qt::OpaqueMode);

    m_image->setSize(112);

    m_name->setLabel("Product Name");
    m_price->setLabel("Product Price");
    m_stock->setLabel("Product Stock");

    m_cancelButton->setRippleStyle(HMaterial::NoRipple);
    m_cancelButton->setForegroundColor(QColor("#ff8296"));
    m_cancelButton->setText("Cancel");

    m_submitButton->setRippleStyle(HMaterial::NoRipple);
    m_submitButton->setForegroundColor(QColor("#657ef8"));
    m_submitButton->setText("Submit");

    QFrame *sp = new QFrame(q);
    sp->setMinimumHeight(50);

    m_layout->addWidget(m_image, 0, 0, 1, 2);
    m_layout->addWidget(m_imageButton, 1, 0, 1, 2, Qt::AlignCenter);
    m_layout->addWidget(m_name, 2, 0, 1, 2);
    m_layout->addWidget(m_price, 3, 0, 1, 2);
    m_layout->addWidget(m_stock, 4, 0, 1, 2);
    m_layout->addWidget(sp, 5, 0, 1, 2);
    m_layout->addWidget(m_cancelButton, 6, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 6, 1, 1, 1);

    QObject::connect(m_cancelButton, &QPushButton::clicked, q, &HProductEdit::hideDialog);
    QObject::connect(m_submitButton, &QPushButton::clicked, q, &HProductEdit::addSlot);
}

HProductEdit::HProductEdit(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductEditPrivate(this))
{
    d_func()->init();
}

HProductEdit::~HProductEdit()
{
}

void HProductEdit::addSlot()
{
    Q_D(HProductEdit);

    emit hideDialog();

    QString price = d->m_price->text().split(" ")[1];
    price.replace('.', "");

    emit addSignal(
            d->m_image->getImage(),
            d->m_name->text(),
            price.toInt(),
            d->m_stock->text().toInt());

    emit d->m_product->updateSlot();

    setEmptyField();
}

void HProductEdit::editSlot()
{
    Q_D(HProductEdit);

    emit hideDialog();

    QString price = d->m_price->text().split(" ")[1];
    price.replace('.', "");

    d->m_product->setImage(d->m_image->getImage());
    d->m_product->setName(d->m_name->text());
    d->m_product->setPrice(price.toInt());
    d->m_product->setStock(d->m_stock->text().toInt());

    emit d->m_product->updateSlot();

    setEmptyField();
}

void HProductEdit::setMode(HProductEdit::Mode mode)
{
    Q_D(HProductEdit);

    if (d->m_mode != mode) {
        if (mode == Mode::AddMode) {
            d->m_mode = Mode::AddMode;
            addMode();
        } else {
            d->m_mode = Mode::EditMode;
            editMode();
        }
    }
}

void HProductEdit::addMode()
{
    Q_D(HProductEdit);

    QObject::disconnect(d->m_submitButton, &QPushButton::clicked, this, &HProductEdit::editSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked, this, &HProductEdit::addSlot);
}

void HProductEdit::editMode()
{
    Q_D(HProductEdit);

    QObject::disconnect(d->m_submitButton, &QPushButton::clicked, this, &HProductEdit::addSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked, this, &HProductEdit::editSlot);
}

void HProductEdit::setEmptyField()
{
    Q_D(HProductEdit);

    d->m_image->setImage(QImage(":/images/images/default.png"));
    d->m_name->clear();
    d->m_price->clear();
    d->m_stock->clear();
}

void HProductEdit::setTargetProduct(HProduct *product)
{
    Q_D(HProductEdit);

    QLocale locale("id_ID");

    d->m_product = product;

    d->m_image->setImage(product->image());
    d->m_name->setText(product->name());
    d->m_price->setText("Rp " + locale.toString(product->price()));
    d->m_stock->setText(QString::number(product->stock()));
}