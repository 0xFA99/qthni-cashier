#include "products/components/productdialog.h"
#include "products/components/productdialog_p.h"

#include <QGridLayout>
#include <QFileDialog>
#include <QLocale>
#include <QDebug>

#include "products/ProductObject.h"
#include "products/ProductObjectManager.h"

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
    m_memberPriceField      = new QtMaterialTextField(q);
    m_customerPriceField    = new QtMaterialTextField(q);
    m_stockField            = new QtMaterialTextField(q);
    m_pointField            = new QtMaterialTextField(q);
    m_cancelButton          = new QtMaterialFlatButton("CLOSE", q);
    m_submitButton          = new QtMaterialFlatButton("SUBMIT", q);
    m_locale                = QLocale("id_ID");
    m_mode                  = ProductDialog::Mode::Add;
    m_uuid                  = nullptr;

    m_avatar->setImage(QImage(":/images/images/profiles/defaultimage.png"));
    m_avatar->setSize(72);

    m_changeAvatarButton->setColor(QRgb(0x8a8a8a));

    QFont font("Roboto", 12, QFont::Normal);
    font.setPixelSize(16);
    m_nameField->setFont(font);
    m_nameField->setLabel("Nama Produk");

    m_memberPriceField->setFont(font);
    m_memberPriceField->setText("Rp 0");
    m_memberPriceField->setLabel("Harga Member");

    m_customerPriceField->setFont(font);
    m_customerPriceField->setText("Rp 0");
    m_customerPriceField->setLabel("Harga Konsumen");

    m_stockField->setFont(font);
    m_stockField->setLabel("Stock Produk");

    m_pointField->setFont(font);
    m_pointField->setLabel("Point Produk");

    m_cancelButton->setHaloVisible(false);
    m_cancelButton->setRole(Material::Secondary);
    m_cancelButton->setRippleStyle(Material::NoRipple);
    m_cancelButton->setOverlayStyle(Material::TintedOverlay);

    m_submitButton->setHaloVisible(false);
    m_submitButton->setRole(Material::Primary);
    m_submitButton->setRippleStyle(Material::NoRipple);
    m_submitButton->setOverlayStyle(Material::TintedOverlay);

    auto secondWidget = new QFrame(q);
    auto secondWidgetLayout = new QVBoxLayout(secondWidget);
    secondWidgetLayout->setContentsMargins(0, 0, 0, 0);

    m_layout->addWidget(m_avatar, 0, 0, 1, 2);
    m_layout->addWidget(m_changeAvatarButton, 1, 0, 1, 2, Qt::AlignCenter);
    m_layout->addWidget(m_nameField, 2, 0, 1, 2);
    m_layout->addWidget(m_memberPriceField, 3, 0, 1, 2);
    m_layout->addWidget(m_customerPriceField, 4, 0, 1, 2);
    m_layout->addWidget(m_stockField, 5, 0, 1, 2);
    m_layout->addWidget(m_pointField, 6, 0, 1, 2);
    m_layout->addWidget(m_cancelButton, 7, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 7, 1, 1, 1);
    m_layout->setSpacing(18);

    QObject::connect(m_changeAvatarButton, &QPushButton::clicked, [q]() {
        q->chooseImage();
    });

    QObject::connect(m_memberPriceField, &QLineEdit::textChanged, [=](const QString &string) {
        if (string == "") {
            m_memberPriceField->setText("Rp 0");
        } else {
            int price = string.split(" ")[1].replace('.', "").toInt();

            m_memberPriceField->setText("Rp " + m_locale.toString(price));
        }
    });

    QObject::connect(m_customerPriceField, &QLineEdit::textChanged, [=](const QString &string) {
        if (string == "") {
            m_customerPriceField->setText("Rp 0");
        } else {
            int price = string.split(" ")[1].replace('.', "").toInt();

            m_customerPriceField->setText("Rp " + m_locale.toString(price));
        }
    });

    QObject::connect(m_cancelButton, &QPushButton::clicked, [q]() {
        emit q->closedProductDialog();
    });

    QObject::connect(m_submitButton, &QPushButton::clicked, q, &ProductDialog::addSlot);
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
    d->m_avatar->setImage(QImage(":/images/images/profiles/defaultimage.png"));
    d->m_nameField->clear();
    d->m_memberPriceField->setText("Rp 0");
    d->m_customerPriceField->setText("Rp 0");
    d->m_pointField->clear();
    d->m_stockField->clear();
    d->m_uuid = nullptr;
}

void ProductDialog::addSlot() {
    Q_D(ProductDialog);

    ProductObject newProduct;

    // Generate new UUID
    QUuid newUUID = QUuid::createUuid();
    qDebug() << "App - Success - Create new Product UUID: " << newUUID;

    newProduct.setUUID(newUUID);
    newProduct.setImage(d->m_avatar->image());
    newProduct.setName(d->m_nameField->text());

    newProduct.setMemberPrice(d->m_memberPriceField->text().split(" ")[1].replace('.', "").toInt());
    newProduct.setCustomerPrice(d->m_customerPriceField->text().split(" ")[1].replace('.', "").toInt());

    if (d->m_stockField->text() == "") newProduct.setStock(0);
    newProduct.setStock(d->m_stockField->text().toInt());

    if (d->m_pointField->text() == "") newProduct.setPoint(0);
    newProduct.setPoint(d->m_pointField->text().toInt());

    addedProduct(newProduct);

    closedProductDialog();
    clearField();
}

void ProductDialog::editSlot()
{
    Q_D(ProductDialog);

    ProductObject tempProduct;
    tempProduct.setImage(d->m_avatar->image());
    tempProduct.setName(d->m_nameField->text());

    tempProduct.setMemberPrice(d->m_memberPriceField->text().split(" ")[1].replace('.', "").toInt());
    tempProduct.setCustomerPrice(d->m_customerPriceField->text().split(" ")[1].replace('.', "").toInt());

    if (d->m_stockField->text() == "") tempProduct.setStock(0);
    tempProduct.setStock(d->m_stockField->text().toInt());

    if (d->m_pointField->text() == "") tempProduct.setPoint(0);
    tempProduct.setPoint(d->m_pointField->text().toInt());

    editedProduct(d->m_uuid, tempProduct);

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


void ProductDialog::chooseImage()
{
    Q_D(ProductDialog);

    QString filename = QFileDialog::getOpenFileName(
                this, "Choose Image",
                QDir::currentPath(),
                "All files (*.*) ;; PNG files (*.png)"
            );

    d->m_avatar->setImage(QImage(filename.toUtf8()));
}

void ProductDialog::setProductFromUUID(QUuid uuid)
{
    Q_D(ProductDialog);

    d->m_uuid = uuid;

    ProductObject *product = d->m_productManager->getProductObject(uuid);

    d->m_avatar->setImage(product->image());
    d->m_nameField->setText(product->name());
    d->m_memberPriceField->setText("Rp " + d->m_locale.toString(product->memberPrice()));
    d->m_customerPriceField->setText("Rp " + d->m_locale.toString(product->customerPrice()));
    d->m_stockField->setText(QString::number(product->stock()));
    d->m_pointField->setText(QString::number(product->point()));
}

void ProductDialog::addProductManager(ProductObjectManager* productManager)
{
    Q_D(ProductDialog);

    d->m_productManager = productManager;
}