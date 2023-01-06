#ifndef QTHNI_MEMBERNAMEWIDGET_H
#define QTHNI_MEMBERNAMEWIDGET_H

#include <QWidget>

class MemberNameWidgetPrivate;
class MemberNameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MemberNameWidget(QWidget *parent = nullptr);
    ~MemberNameWidget();

    void changeMemberName(const QString&);

signals:
    void changeMember();
    void memberChoosen(bool);

protected:
    const QScopedPointer<MemberNameWidgetPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberNameWidget)
    Q_DECLARE_PRIVATE(MemberNameWidget)
};

#endif //QTHNI_MEMBERNAMEWIDGET_H
