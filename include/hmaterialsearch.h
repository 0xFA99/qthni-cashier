#ifndef HMATERIALSEARCH_H
#define HMATERIALSEARCH_H

#include <QWidget>

class HMaterialSearchPrivate;
class HMaterialSearch : public QWidget
{
    Q_OBJECT

public:
    explicit HMaterialSearch(QWidget *parent = nullptr);
    ~HMaterialSearch();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialSearchPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialSearch)
    Q_DECLARE_PRIVATE(HMaterialSearch)
};

#endif
