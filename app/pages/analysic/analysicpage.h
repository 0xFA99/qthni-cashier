#ifndef QTHNI_ANALYSICPAGE_H
#define QTHNI_ANALYSICPAGE_H

#include <QWidget>

class AnalysicPagePrivate;
class AnalysicPage : public QWidget
{
    Q_OBJECT

public:
    explicit AnalysicPage(QWidget *parent = nullptr);
    ~AnalysicPage();

protected:
    const QScopedPointer<AnalysicPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(AnalysicPage)
    Q_DECLARE_PRIVATE(AnalysicPage)
};

#endif //QTHNI_ANALYSICPAGE_H
