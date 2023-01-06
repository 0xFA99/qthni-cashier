#ifndef QTHNI_CHOOSEMEMBERWIDGET_H
#define QTHNI_CHOOSEMEMBERWIDGET_H

#include <QWidget>

class ChooseMemberWidgetPrivate;
class ChooseMemberWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseMemberWidget(QWidget *parent = nullptr);
    ~ChooseMemberWidget();

signals:
    void hideChooseMember(const QString&);

protected:
    const QScopedPointer<ChooseMemberWidgetPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ChooseMemberWidget)
    Q_DECLARE_PRIVATE(ChooseMemberWidget)
};

#endif //QTHNI_CHOOSEMEMBERWIDGET_H
