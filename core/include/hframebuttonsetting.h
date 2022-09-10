#ifndef HFRAMEBUTTONSETTING_H
#define HFRAMEBUTTONSETTING_H

#include <QVector>

#include "hmaterialflatbutton.h"
#include "hmaterialframe.h"

class HFrameButtonSetting : public HMaterialFlatButton
{
    Q_OBJECT

public:
    HFrameButtonSetting(HFrameButtonSetting &other) = delete;
    void operator=(const HFrameButtonSetting &) = delete;

    static HFrameButtonSetting *getFrameSetting();

    void addFrameWidget(HMaterialFrame *widget);
    void changeFrameMode();

protected:
    HFrameButtonSetting(const QString &text, QWidget *parent = nullptr);

    static HFrameButtonSetting *m_hFrameButtonSetting;

    QVector<HMaterialFrame *> m_frameList;
};

#endif
