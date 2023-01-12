#include "purchase/components/purchase_order_dialog.h"
#include "purchase/components/purchase_order_dialog_p.h"

#include <QGridLayout>
#include <QDebug>

#include "products/ProductObject.h"
#include "qtmaterial/components/qtmaterialscrollbar.h"

PurchaseOrderDialogPrivate::PurchaseOrderDialogPrivate(PurchaseOrderDialog *q)
    : q_ptr(q)
{
}

PurchaseOrderDialogPrivate::~PurchaseOrderDialogPrivate() = default;

void PurchaseOrderDialogPrivate::init()
{
    Q_Q(PurchaseOrderDialog);

    m_layout            = new QGridLayout(q);
    m_memberNameTitle   = new QLabel(q);

    m_scrollArea        = new QScrollArea(q);
    m_orderWidget       = new QWidget(m_scrollArea);
    m_orderWidgetLayout = new QVBoxLayout(m_orderWidget);

    m_subTotal          = new QLabel("Rp 0", q);
    m_discount          = new QLabel("Rp 0", q);
    m_total             = new QLabel("Rp 0", q);

    m_closeButton       = new QtMaterialFlatButton("TUTUP", q);
    m_submitButton      = new QtMaterialFlatButton("SUBMIT", q);
    m_locale            = QLocale("id_ID");

    m_orderWidgetLayout->addStretch(1);
    m_orderWidgetLayout->setContentsMargins(0, 0, 0, 0);

    auto subtotalLabel = new QLabel("Sub Total", q);
    auto discountLabel = new QLabel("Discount", q);
    auto totalLabel = new QLabel("Total", q);

    QFont font("Roboto", 12, QFont::Normal);
    subtotalLabel->setFont(font);
    discountLabel->setFont(font);
    totalLabel->setFont(font);

    m_subTotal->setFont(font);
    m_discount->setFont(font);
    m_total->setFont(font);

    m_subTotal->setAlignment(Qt::AlignRight);
    m_discount->setAlignment(Qt::AlignRight);
    m_total->setAlignment(Qt::AlignRight);

    m_scrollArea->setWidget(m_orderWidget);
    m_scrollArea->setMinimumHeight(300);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setStyleSheet("background-color: white;");
    m_scrollArea->setHorizontalScrollBar(new QtMaterialScrollBar(m_scrollArea));
    m_scrollArea->setVerticalScrollBar(new QtMaterialScrollBar(m_scrollArea));

    QObject::connect(m_closeButton, &QPushButton::clicked, [q]() { emit q->hideDialog(); });

    m_closeButton->setHaloVisible(false);
    m_closeButton->setRole(Material::Secondary);
    m_closeButton->setOverlayStyle(Material::TintedOverlay);

    m_submitButton->setHaloVisible(false);
    m_submitButton->setRole(Material::Primary);
    m_submitButton->setOverlayStyle(Material::TintedOverlay);

    m_layout->addWidget(m_memberNameTitle, 0, 0, 1, 2);
    m_layout->addWidget(m_scrollArea, 1, 0, 1, 2);

    m_layout->addWidget(subtotalLabel, 2, 0, 1, 1);
    m_layout->addWidget(discountLabel, 3, 0, 1, 1);
    m_layout->addWidget(totalLabel, 4, 0, 1, 1);

    m_layout->addWidget(m_subTotal, 2, 1, 1, 1);
    m_layout->addWidget(m_discount, 3, 1, 1, 1);
    m_layout->addWidget(m_total, 4, 1, 1, 1);

    m_layout->addWidget(m_closeButton, 5, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 5, 1, 1, 1);
}

PurchaseOrderDialog::PurchaseOrderDialog(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new PurchaseOrderDialogPrivate(this))
{
    d_func()->init();

    setMinimumWidth(600);
}

PurchaseOrderDialog::~PurchaseOrderDialog() = default;

void PurchaseOrderDialog::addItem(FinalWidget *item)
{
    Q_D(PurchaseOrderDialog);

    item->setParent(this);

    d->m_orderWidgetLayout->insertWidget(d->m_orderWidgetLayout->count() - 1, item);
}

void PurchaseOrderDialog::updateSubTotal(const QString &price)
{
    Q_D(PurchaseOrderDialog);
    d->m_subTotal->setText(price);
}

void PurchaseOrderDialog::deleteItem(QUuid uuid)
{
    Q_D(PurchaseOrderDialog);

    FinalWidget *item;
    for (int i = 0; i < d->m_orderWidgetLayout->count(); i++) {
        QLayoutItem *litem = d->m_orderWidgetLayout->itemAt(i);

        if ((item = dynamic_cast<FinalWidget *>(litem->widget()))) {

            if (item->uuid() == uuid) {
                d->m_layout->removeWidget(item);
                item->removeFromSubject();
                delete item;
                break;
            }
        }
    }
}