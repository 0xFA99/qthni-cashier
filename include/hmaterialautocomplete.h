#ifndef HMATERIALAUTOCOMPLETE_H
#define HMATERIALAUTOCOMPLETE_H

#include "hmaterialtextfield.h"

class HMaterialAutoCompletePrivate;

class HMaterialAutoComplete : public HMaterialTextField
{
    Q_OBJECT

public:
    explicit HMaterialAutoComplete(QWidget *parent = nullptr);
    ~HMaterialAutoComplete();

    void setDataSource(const QString &data);

signals:
    void itemSelected(QString);

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;

protected slots:
    void updateResults(QString text);

private:
    Q_DISABLE_COPY(HMaterialAutoComplete)
    Q_DECLARE_PRIVATE(HMaterialAutoComplete)
};

#endif
