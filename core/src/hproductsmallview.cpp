#include "hproductsmallview.h"
#include "hproductsmallview_p.h"

#include <QGridLayout>
#include <QPainter>

HProductSmallViewPrivate::HProductSmallViewPrivate(HProductSmallView *q)
    : q_ptr(q)
{
}

HProductSmallViewPrivate::~HProductSmallViewPrivate()
{
}

void HProductSmallViewPrivate::init()
{
    Q_Q(HProductSmallView);
    
    m_layout        = new QGridLayout(q);
    m_image         = new HMaterialImage(QImage(":/images/images/ANDRO.png"), q);
    m_title         = new HMaterialLabel("Rokok Surya", q);
    m_price         = new HMaterialCurrency(0, q);
    m_minus         = new HMaterialFlatButton(q);
    m_amount        = new HMaterialLabel("1", q);
    m_plus          = new HMaterialFlatButton(q);
   
    m_image->setSize(50);
    m_image->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    m_title->setFontSize(12);
    m_title->setFontWeight(QFont::Medium);
    m_title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_title->setTextColor(QColor(70, 70, 70));

    m_price->setTextColor(QColor(119, 119, 119));
    m_price->setAlignment(Qt::AlignLeft);
    m_price->setFontSize(12);
    
    m_minus->setIcon(QIcon(":/icons/icons/personal/subtract-line.svg"));
    m_minus->setHaloVisible(false);
    m_minus->setOverlayStyle(HMaterial::TintedOverlay);
    m_minus->setRippleStyle(HMaterial::PositionedRipple);
    m_minus->setRippleColor(QColor(38, 115, 221));
    m_minus->setOverlayColor(QColor(38, 115, 221));
    m_minus->setIconPlacement(HMaterial::CenterIcon);
    m_minus->setFixedWidth(m_minus->sizeHint().height());

    m_amount->setAlignment(Qt::AlignCenter);
    m_amount->setFontSize(12);
    m_amount->setFixedWidth(m_amount->height());
    m_amount->setTextColor(QColor(70, 70, 70));

    m_plus->setIcon(QIcon(":/icons/icons/personal/add-line.svg"));
    m_plus->setHaloVisible(false);
    m_plus->setOverlayStyle(HMaterial::TintedOverlay);
    m_plus->setRippleStyle(HMaterial::PositionedRipple);
    m_plus->setRippleColor(QColor(38, 115, 221));
    m_plus->setOverlayColor(QColor(38, 115, 221));
    m_plus->setIconPlacement(HMaterial::CenterIcon);
    m_plus->setFixedWidth(m_plus->sizeHint().height());

    m_layout->addWidget(m_image, 0, 0, 2, 1);
    m_layout->addWidget(m_title, 0, 1, 1, 2);
    m_layout->addWidget(m_price, 1, 1, 1, 2);
    m_layout->addWidget(m_minus, 0, 2, 2, 1);
    m_layout->addWidget(m_amount, 0, 3, 2, 1);
    m_layout->addWidget(m_plus, 0, 4, 2, 1);

    QObject::connect(m_minus, &QPushButton::clicked, [this]() {
        int value = m_amount->text().toInt();
        if (!(value <= 1))
            m_amount->setText(QString::number(value - 1));
    });

    QObject::connect(m_plus, &QPushButton::clicked, [this]() {
        int value = m_amount->text().toInt();
        m_amount->setText(QString::number(value + 1));
    });
}

HProductSmallView::HProductSmallView(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductSmallViewPrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

}

HProductSmallView::~HProductSmallView()
{
}

void HProductSmallView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HProductSmallView);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainter painter(this);
    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
