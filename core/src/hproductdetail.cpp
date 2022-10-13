#include "hproductdetail.h"
#include "hproductdetail_p.h"

#include <QGridLayout>
#include <QLocale>
#include <QDebug>

#include "hmaterialtheme.h"

HProductDetailPrivate::HProductDetailPrivate(HProductDetail *q)
    : q_ptr(q)
{
}

HProductDetailPrivate::~HProductDetailPrivate()
{
}

void HProductDetailPrivate::init()
{
    Q_Q(HProductDetail);

    m_layout        = new QGridLayout(q);
    m_image         = new HMaterialImage(q);
    m_name          = new HMaterialTextField(q);
    m_category      = new HMaterialTextField(q);
    m_stock         = new HMaterialTextField(q);
    m_normalPrice   = new HMaterialTextField(q);
    m_memberPrice   = new HMaterialTextField(q);
    m_cancelButton  = new HMaterialFlatButton("Batal", q);
    m_submitButton  = new HMaterialFlatButton("Kirim", q);

    m_name->setLabel("Nama Produk");
    m_category->setLabel("Category Produk");
    m_stock->setLabel("Stock Produk");
    m_normalPrice->setLabel("Harga Konsumen");
    m_memberPrice->setLabel("Harga Member");

    m_cancelButton->setBackgroundMode(Qt::OpaqueMode);
    m_cancelButton->setRole(HMaterial::Secondary);
    
    m_submitButton->setBackgroundMode(Qt::OpaqueMode);
    m_submitButton->setRole(HMaterial::Primary);

    m_layout->addWidget(m_image, 0, 0, 2, 1);
    m_layout->addWidget(m_name, 0, 1, 1, 3);
    m_layout->addWidget(m_category, 1, 1, 1, 3);

    m_layout->addWidget(m_stock, 2, 0);
    m_layout->addWidget(m_normalPrice, 2, 1);
    m_layout->addWidget(m_memberPrice, 2, 2);

    // Sperator
    QWidget *sep = new QWidget(q);
    sep->setMinimumHeight(10);
    m_layout->addWidget(sep, 3, 0, 1, 3);

    m_layout->addWidget(m_cancelButton, 4, 0);
    m_layout->addWidget(m_submitButton, 4, 2);

    m_normalPrice->setCurrencyFormat(true);
    m_memberPrice->setCurrencyFormat(true);
    /*
    QObject::connect(m_normalPrice, &QLineEdit::textChanged, [=](const QString &string) {
        QString temp = string.split(" ")[1];
        temp.replace('.', "");
        
        QLocale indo = QLocale("id_ID");
        int value = temp.toInt();
        m_normalPrice->setText("Rp " + indo.toString(value));
    });

    QObject::connect(m_memberPrice, &QLineEdit::textChanged, [=](const QString &string) {
        QString temp = string.split(" ")[1];
        temp.replace('.', "");

        QLocale indo = QLocale("id_ID");
        int value = temp.toInt();

        m_memberPrice->setText("Rp " + indo.toString(value));
    });
    */
}

HProductDetail::HProductDetail(QWidget *parent)
    : HMaterialFrame(parent)
    , d_ptr(new HProductDetailPrivate(this))
{
    d_func()->init();
}

HProductDetail::~HProductDetail()
{
}
