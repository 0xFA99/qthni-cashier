#ifndef HPANEL_PRIVATE_H
#define HPANEL_PRIVATE_H

#include <QtGlobal>
#include <QLabel>

class QVBoxLayout;
class HPanel;
class HPanelPrivate
{
    Q_DISABLE_COPY(HPanelPrivate)
    Q_DECLARE_PUBLIC(HPanel)

public:
    HPanelPrivate(HPanel *q);
    ~HPanelPrivate();

    void init();

    HPanel *const   q_ptr;
    QVBoxLayout     *m_layout;
    QColor          m_textColor;
    int             m_item;
    QLabel          *m_logo;
};

#endif
