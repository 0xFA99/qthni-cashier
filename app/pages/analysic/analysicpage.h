#ifndef QTHNI_ANALYSICPAGE_H
#define QTHNI_ANALYSICPAGE_H

#include <QWidget>

#include "products/ProductObjectManager.h"

class AnalysicPagePrivate;
class AnalysicPage : public QWidget
{
    Q_OBJECT

public:
    explicit AnalysicPage(ProductObjectManager*, QWidget *parent = nullptr);
    ~AnalysicPage();

public slots:
    // void addRemaindStockItem(int);
    void deleteRemainStockItem(int);

protected:
    const QScopedPointer<AnalysicPagePrivate> d_ptr;

private:
    void addProductManager(ProductObjectManager*);

    Q_DISABLE_COPY(AnalysicPage)
    Q_DECLARE_PRIVATE(AnalysicPage)
};

#endif //QTHNI_ANALYSICPAGE_H
