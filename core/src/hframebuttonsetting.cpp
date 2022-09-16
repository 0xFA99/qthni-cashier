#include <QDebug>

#include "hframebuttonsetting.h"

HFrameButtonSetting *HFrameButtonSetting::m_hFrameButtonSetting = nullptr;

HFrameButtonSetting::HFrameButtonSetting(const QString &text, QWidget *parent)
    : HMaterialFlatButton(text, parent)
    , m_frameList(QVector<HMaterialFrame *>())
    , m_buttonList(QVector<HMaterialFlatButton *>())
{
    QObject::connect(this, &QPushButton::clicked, [=]() { changeFrameMode(); });
}

HFrameButtonSetting *HFrameButtonSetting::getFrameSetting()
{
    if (m_hFrameButtonSetting == nullptr)
        m_hFrameButtonSetting = new HFrameButtonSetting("Change Mode");

    return m_hFrameButtonSetting;
}

void HFrameButtonSetting::addFrameWidget(QWidget *widget)
{
    m_frameList.append(widget);
}

void HFrameButtonSetting::addButtonWidget(HMaterialFlatButton *widget)
{
    m_buttonList.append(widget);
}

void HFrameButtonSetting::changeFrameMode()
{
    if (m_frameList.isEmpty() && m_buttonList.isEmpty())
        return;

    QVector<QWidget *>::iterator itr;
    for (itr = m_frameList.begin(); itr != m_frameList.end(); ++itr)
        (*itr)->changeMode();

    QVector<HMaterialFlatButton *>::iterator itr;
    for (itr = m_buttonList.begin(); itr != m_buttonList.end(); ++itr)
        (*itr)->changeMode();
        
}
