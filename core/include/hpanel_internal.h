#ifndef HPANEL_INTERNAL_H
#define HPANEL_INTERNAL_H

#include "hmaterialflatbutton.h"

class HPanel;
class HPanelItem : public HMaterialFlatButton
{
    Q_OBJECT

public:
    HPanelItem(const QString &text, HPanel *parent);
    ~HPanelItem();

    inline void setActive(bool state);
    inline bool isActive() const;

protected:
    void paintForeground(QPainter *painter) Q_DECL_OVERRIDE;

protected slots:
    void activeItem();

private:
    Q_DISABLE_COPY(HPanelItem)

    HPanel *const   m_panel;
    bool            m_active;
};

inline void HPanelItem::setActive(bool state)
{
    m_active = state;
    update();
}

inline bool HPanelItem::isActive() const
{
    return m_active;
}

#endif
