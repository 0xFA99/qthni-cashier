#ifndef HANALYSICPAGE_H
#define HANALYSICPAGE_H

#include <QWidget>

class HAnalysicPagePrivate;
class HAnalysicPage : public QWidget
{
    Q_OBJECT

public:
    HAnalysicPage(QWidget *parent = nullptr);
    ~HAnalysicPage();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HAnalysicPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HAnalysicPage)
    Q_DECLARE_PRIVATE(HAnalysicPage)
};

#endif
