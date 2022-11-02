#ifndef HMEMBERPAGE_H
#define HMEMBERPAGE_H

#include <QWidget>

class HMemberPagePrivate;
class HMemberPage : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberPage(QWidget *parent = nullptr);
    ~HMemberPage();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMemberPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberPage)
    Q_DECLARE_PRIVATE(HMemberPage)
};

#endif
