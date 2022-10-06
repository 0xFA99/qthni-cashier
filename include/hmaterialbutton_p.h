#ifndef HMATERIALBUTTON_PRIVATE_H
#define HMATERIALBUTTON_PRIVATE_H

class HMaterialButton;

class HMaterialButtonPrivate 
{
    Q_DISABLE_COPY(HMaterialButtonPrivate)
    Q_DECLARE_PUBLIC(HMaterialButton)

public:
    HMaterialButtonPrivate(HMaterialButton *q);
    ~HMaterialButtonPrivate();

    void init();

    HMaterialButton *const  q_ptr;
    QColor                  m_lightColor;
    QColor                  m_darkColor;
    bool                    m_followTheme;
};

#endif
