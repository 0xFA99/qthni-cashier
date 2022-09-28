#ifndef HMATERIALPANEL_INTERNAL_H
#define HMATERIALPANEL_INTERNAL_H

#include "hmaterialbutton.h"

class HMaterialPanel;

class HMaterialPanelItem : public HMaterialButton
{
    Q_OBJECT

public:
    HMaterialPanelItem(HMaterialPanel *parent);
    ~HMaterialPanelItem();

    inline void setActive(bool state);
    inline bool isActive() const;

protected:
    void paintForeground(QPainter *painter) Q_DECL_OVERRIDE;

protected slots:
    void activeItem();

private:
    Q_DISABLE_COPY(HMaterialPanelItem)

    HMaterialPanel *const   m_panel;
    bool                    m_active;
};

inline void HMaterialPanelItem::setActive(bool state)
{
    m_active = state;
    update();
}

inline bool HMaterialPanelItem::isActive() const
{
    return m_active;
}

#endif
