#include <QApplication>
#include <QPainter>
#include <QDebug>

#include "hmaterialtextfield.h"
#include "hmaterialtextfield_p.h"
#include "hmaterialtextfield_internal.h"

#include "hmaterialstyle.h"

HMaterialTextFieldPrivate::HMaterialTextFieldPrivate(HMaterialTextField *q)
    : q_ptr(q)
{
}

HMaterialTextFieldPrivate::~HMaterialTextFieldPrivate()
{
}

void HMaterialTextFieldPrivate::init()
{
    Q_Q(HMaterialTextField);

    stateMachine    = new HMaterialTextFieldStateMachine(q);
    label           = 0;
    labelFontSize   = 9.5;
    showLabel       = false;
    showInputLine   = true;
    useThemeColors  = true;

    q->setFrame(false);
    q->setStyle(&HMaterialStyle::instance());
    q->setAttribute(Qt::WA_Hover);
    q->setMouseTracking(true);
    q->setTextMargins(0, 2, 0, 4);

    q->setFont(QFont("ProductSans", 11, QFont::Normal));

    stateMachine->start();
    QCoreApplication::processEvents();
}

HMaterialTextField::HMaterialTextField(QWidget *parent)
    : QLineEdit(parent),
      d_ptr(new HMaterialTextFieldPrivate(this))
{
    d_func()->init();
}

HMaterialTextField::~HMaterialTextField()
{
}

void HMaterialTextField::setUseThemeColors(bool value)
{
    Q_D(HMaterialTextField);

    if (d->useThemeColors == value)
        return;

    d->useThemeColors = value;
    d->stateMachine->setupProperties();
}

bool HMaterialTextField::useThemeColors() const
{
    Q_D(const HMaterialTextField);

    return d->useThemeColors;
}

void HMaterialTextField::setShowLabel(bool value)
{
    Q_D(HMaterialTextField);

    if (d->showLabel == value)
        return;

    d->showLabel = value;

    if (!d->label && value) {
        d->label = new HMaterialTextFieldLabel(this);
        d->stateMachine->setLabel(d->label);
    }   

    if (value) {
        setContentsMargins(0, 23, 0, 0);
    } else {
        setContentsMargins(0, 0, 0, 0);
    }
}

bool HMaterialTextField::hasLabel() const
{
    Q_D(const HMaterialTextField);

    return d->showLabel;
}

void HMaterialTextField::setLabelFontSize(qreal size)
{
    Q_D(HMaterialTextField);

    d->labelFontSize = size;

    if (d->label) {
        QFont font(d->label->font());
        font.setPointSizeF(size);
        d->label->setFont(font);
        d->label->update();
    }
}

qreal HMaterialTextField::labelFontSize() const
{
    Q_D(const HMaterialTextField);

    return d->labelFontSize;
}

void HMaterialTextField::setLabel(const QString &label)
{
    Q_D(HMaterialTextField);

    d->labelString = label;
    setShowLabel(true);
    d->label->update();
}

QString HMaterialTextField::label() const
{
    Q_D(const HMaterialTextField);

    return d->labelString;
}

void HMaterialTextField::setTextColor(const QColor &color)
{
    Q_D(HMaterialTextField);

    d->textColor = color;
    setStyleSheet(QString("QLineEdit { color: %1; }").arg(color.name()));

    MATERIAL_DISABLE_THEME_COLORS
    d->stateMachine->setupProperties();
}

QColor HMaterialTextField::textColor() const
{
    Q_D(const HMaterialTextField);

    if (d->useThemeColors || !d->textColor.isValid()) {
        return HMaterialStyle::instance().themeColor("text");
    } else {
        return d->textColor;
    }
}

void HMaterialTextField::setLabelColor(const QColor &color)
{
    Q_D(HMaterialTextField);

    d->labelColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    d->stateMachine->setupProperties();
}

QColor HMaterialTextField::labelColor() const
{
    Q_D(const HMaterialTextField);

    if (d->useThemeColors || !d->labelColor.isValid()) {
        return HMaterialStyle::instance().themeColor("accent3");
    } else {
        return d->labelColor;
    }
}

void HMaterialTextField::setInkColor(const QColor &color)
{
    Q_D(HMaterialTextField);

    d->inkColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    d->stateMachine->setupProperties();
}

QColor HMaterialTextField::inkColor() const
{
    Q_D(const HMaterialTextField);

    if (d->useThemeColors || !d->inkColor.isValid()) {
        return HMaterialStyle::instance().themeColor("primary1");
    } else {
        return d->inkColor;
    }
}

void HMaterialTextField::setInputLineColor(const QColor &color)
{
    Q_D(HMaterialTextField);

    d->inputLineColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    d->stateMachine->setupProperties();
}

QColor HMaterialTextField::inputLineColor() const
{
    Q_D(const HMaterialTextField);

    if (d->useThemeColors || !d->inputLineColor.isValid()) {
        return HMaterialStyle::instance().themeColor("border");
    } else {
        return d->inputLineColor;
    }
}

void HMaterialTextField::setShowInputLine(bool value)
{
    Q_D(HMaterialTextField);

    if (d->showInputLine == value)
        return;

    d->showInputLine = value;
    update();
}

bool HMaterialTextField::hasInputLine() const
{
    Q_D(const HMaterialTextField);

    return d->showInputLine;
}

HMaterialTextField::HMaterialTextField(HMaterialTextFieldPrivate &d, QWidget *parent)
    : QLineEdit(parent),
      d_ptr(&d)
{
    d_func()->init();
}

bool HMaterialTextField::event(QEvent *event)
{
    Q_D(HMaterialTextField);

    switch (event->type()) {
        case QEvent::Resize:
        case QEvent::Move: {
            if (d->label)
                d->label->setGeometry(rect());
        }
        default:
            break;
    }

    return QLineEdit::event(event);
}

void HMaterialTextField::paintEvent(QPaintEvent *event)
{
    Q_D(HMaterialTextField);

    QLineEdit::paintEvent(event);

    QPainter painter(this);

    const qreal progress = d->stateMachine->progress();

    if (text().isEmpty() && progress < 1) {
        painter.setOpacity(1 - progress);
        painter.fillRect(rect(), parentWidget()->palette().color(backgroundRole()));
    }

    const int y = height() - 1;
    const int wd = width() - 5;

    if (d->showInputLine) {
        QPen pen;
        pen.setWidth(1);
        pen.setColor(inputLineColor());

        if (!isEnabled())
            pen.setStyle(Qt::DashLine);

        painter.setPen(pen);
        painter.setOpacity(1);
        painter.drawLine(QLine(2.5, y, wd, y));

        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(inkColor());

        if (progress > 0) {
            painter.setPen(Qt::NoPen);
            painter.setBrush(brush);
            const int w = (1 - progress) * static_cast<qreal>(wd / 2);
            painter.drawRect(w + 2.5, height() - 2, wd - w * 2, 2);
        }
    }
}
