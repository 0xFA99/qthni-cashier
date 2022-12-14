#include "products/components/productdialog.h"
#include "products/components/productdialog_p.h"

#include <QGridLayout>
#include <QLocale>

#include "products/product.h"

ProductDialogPrivate::ProductDialogPrivate(ProductDialog *q)
    : q_ptr(q)
{
}

ProductDialogPrivate::~ProductDialogPrivate() = default;

void ProductDialogPrivate::init()
{
    Q_Q(ProductDialog);

    m_layout                = new QGridLayout(q);
    m_avatar                = new QtMaterialAvatar(q);
    m_changeAvatarButton    = new QtMaterialIconButton(QtMaterialTheme::icon("image", "add_a_photo"), q);
    m_nameField             = new QtMaterialTextField(q);
    m_priceField            = new QtMaterialTextField(q);
    m_stockField            = new QtMaterialTextField(q);
    m_pointField            = new QtMaterialTextField(q);
    m_cancelButton          = new QtMaterialFlatButton("CLOSE", q);
    m_submitButton          = new QtMaterialFlatButton("SUBMIT", q);
    m_mode                  = ProductDialog::Mode::Add;
    m_index                 = 0;

    m_avatar->setLetter(QChar('A'));
    m_avatar->setSize(72);

    m_changeAvatarButton->setColor(QRgb(0x8a8a8a));

    QFont font("Roboto", 12, QFont::Normal);
    font.setPixelSize(16);
    m_nameField->setFont(font);
    m_nameField->setLabel("Nama Produk");

    m_priceField->setFont(font);
    m_priceField->setText("Rp 0");
    m_priceField->setLabel("Harga Produk");

    m_stockField->setFont(font);
    m_stockField->setLabel("Stock Produk");

    m_pointField->setFont(font);
    m_pointField->setLabel("Point Produk");

    m_cancelButton->setHaloVisible(false);
    m_cancelButton->setRole(Material::Secondary);

    m_submitButton->setHaloVisible(false);
    m_submitButton->setRole(Material::Primary);

    m_layout->addWidget(m_avatar, 0, 0, 1, 2);
    m_layout->addWidget(m_changeAvatarButton, 1, 0, 1, 2, Qt::AlignCenter);
    m_layout->addWidget(m_nameField, 2, 0, 1, 2);
    m_layout->addWidget(m_priceField, 3, 0, 1, 2);
    m_layout->addWidget(m_stockField, 4, 0, 1, 2);
    m_layout->addWidget(m_pointField, 5, 0, 1, 2);
    m_layout->addWidget(m_cancelButton, 6, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 6, 1, 1, 1);
    m_layout->setSpacing(18);

    QObject::connect(m_priceField, &QLineEdit::textChanged, [=](const QString &string) {
        QLocale indo("id_ID");

        if (string == "") {
            m_priceField->setText("Rp 0");
        } else {
            QString temp = string.split(" ")[1];
            temp.replace('.', "");

            int value = temp.toInt();
            m_priceField->setText("Rp " + indo.toString(value));
        }
    });

    QObject::connect(m_cancelButton, &QPushButton::clicked, [q]() {
        emit q->closedProductDialog();
    });

    /*
    QObject::connect(m_submitButton, &QPushButton::clicked, [=]() {

        struct NewProduct {
            QString name = "";
            int price = 0;
            int stock = 0;
            int point = 0;
        } newProduct;

        newProduct.name = m_nameField->text();

        QString price = m_priceField->text().split(" ")[1];
        price.replace('.', "");
        newProduct.price = price.toInt();

        if (m_stockField->text() == "")
            newProduct.stock = 0;
        newProduct.stock = m_stockField->text().toInt();

        if (m_pointField->text() == "")
            newProduct.point = 0;
        newProduct.point = m_pointField->text().toInt();

        q->addedProduct(newProduct.name, newProduct.price, newProduct.point, newProduct.stock);
        emit q->closedProductDialog();
        emit q->clearField();
    });
    */

    QObject::connect(m_submitButton, &QPushButton::clicked,
                     q, &ProductDialog::addSlot);
}

ProductDialog::ProductDialog(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ProductDialogPrivate(this))
{
    d_func()->init();
}

ProductDialog::~ProductDialog() = default;

void ProductDialog::clearField()
{
    Q_D(ProductDialog);

    d->m_nameField->clear();
    d->m_priceField->setText("Rp 0");
    d->m_pointField->clear();
    d->m_stockField->clear();
}

void ProductDialog::addSlot() {
    Q_D(ProductDialog);

    Product newProduct;
    newProduct.setName(d->m_nameField->text());

    QString price = d->m_priceField->text().split(" ")[1];
    price.replace('.', "");
    newProduct.setPrice(price.toInt());

    if (d->m_stockField->text() == "")
        newProduct.setStock(0);
    newProduct.setStock(d->m_stockField->text().toInt());

    if (d->m_pointField->text() == "")
        newProduct.setPoint(0);
    newProduct.setPoint(d->m_pointField->text().toInt());

    addedProduct(&newProduct);

    closedProductDialog();
    clearField();
}

void ProductDialog::editSlot()
{
    Q_D(ProductDialog);

    Product tempProduct;
    tempProduct.setName(d->m_nameField->text());

    QString price = d->m_priceField->text().split(" ")[1];
    price.replace('.', "");
    tempProduct.setPrice(price.toInt());

    if (d->m_stockField->text() == "")
        tempProduct.setStock(0);
    tempProduct.setStock(d->m_stockField->text().toInt());

    if (d->m_pointField->text() == "")
        tempProduct.setPoint(0);
    tempProduct.setPoint(d->m_pointField->text().toInt());

    editedProduct(d->m_index, &tempProduct);
    closedProductDialog();
    clearField();
}

void ProductDialog::setMode(ProductDialog::Mode mode)
{
    Q_D(ProductDialog);

    if (d->m_mode != mode) {
        if (mode == Mode::Add) {
            d->m_mode = Mode::Add;
            addMode();
        } else {
            d->m_mode = Mode::Edit;
            editMode();
        }
    }
}

void ProductDialog::addMode()
{
    Q_D(ProductDialog);

    QObject::disconnect(d->m_submitButton, &QPushButton::clicked,
                        this, &ProductDialog::editSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked,
                     this, &ProductDialog::addSlot);
}

void ProductDialog::editMode()
{
    Q_D(ProductDialog);

    QObject::disconnect(d->m_submitButton, &QPushButton::clicked,
                        this, &ProductDialog::addSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked,
                     this, &ProductDialog::editSlot);
}

void ProductDialog::setNameField(const QString &name)
{
    Q_D(ProductDialog);

    d->m_nameField->setText(name);
}

void ProductDialog::setPriceField(int price)
{
    Q_D(ProductDialog);

    QLocale indo("id_ID");

    d->m_priceField->setText("Rp " + indo.toString(price));
}

void ProductDialog::setPointField(int point)
{
    Q_D(ProductDialog);

    d->m_pointField->setText(QString::number(point));
}

void ProductDialog::setStockField(int stock)
{
    Q_D(ProductDialog);

    d->m_stockField->setText(QString::number(stock));
}

void ProductDialog::setIndex(int index)
{
    Q_D(ProductDialog);

    d->m_index = index;
}