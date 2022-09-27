#ifndef HMATERIALLABEL_H
#define HMATERIALLABEL_H

#include <QLabel>

#include "hinterfacewidget.h"
#include "hmaterialtheme.h"

class HMaterialLabelPrivate;

class HMaterialLabel : public QLabel, public HInterfaceWidget
{
public:
    HMaterialLabel(QWidget *parent = nullptr);
    HMaterialLabel(const QString &text, QWidget *parent = nullptr);
    ~HMaterialLabel();

    void setDarkTheme() override;
    void setLightTheme() override;

    void setFollowTheme(bool value);
    bool isFollowTheme() const;

    void setLabelStyle(HMaterial::LabelStyle style);
    HMaterial::LabelStyle labelStyle() const;

    void setLabelRole(HMaterial::Role role);
    HMaterial::Role labelRole() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

protected:
    const QScopedPointer<HMaterialLabelPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialLabel);
    Q_DECLARE_PRIVATE(HMaterialLabel);
};

#endif
