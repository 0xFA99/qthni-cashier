#ifndef HOPTIONPAGE_H
#define HOPTIONPAGE_H

#include <QWidget>

class HOptionPagePrivate;
class HOptionPage : public QWidget
{
    Q_OBJECT

public:
    explicit HOptionPage(QWidget *parent = nullptr);
    ~HOptionPage();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HOptionPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HOptionPage)
    Q_DECLARE_PRIVATE(HOptionPage)
};

#endif
