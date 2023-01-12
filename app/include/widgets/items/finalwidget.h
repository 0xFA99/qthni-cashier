#ifndef QTHNI_FINALWIDGET_H
#define QTHNI_FINALWIDGET_H

#include "interfaces/IItem.h"
#include "interfaces/IObserver.h"
#include "interfaces/ISubject.h"

#include <QWidget>
#include <QUuid>

class FinalWidgetPrivate;
class FinalWidget : public QWidget, public IObserver, public IItem
{
    Q_OBJECT

public:
    explicit FinalWidget(ISubject &, QWidget *parent = nullptr);
    ~FinalWidget();

    void Update(const QImage&, const QString&, const QString&) override;
    void ExtraUpdate(const QUuid&, int, int, int, int) override;

    void setImage(const QImage&) override;

    void setTitle(const QString&) override;
    void setTitleColor(const QColor&) override;

    void setSubTitle(const QString&) override;
    void setSubTitleColor(const QColor&) override;

    void removeFromSubject() override;

    void setUUID(QUuid);
    [[nodiscard]] QUuid uuid() const;

public slots:
    void changeAmount(int);
    void changeTotal(QUuid, int);

protected:
    const QScopedPointer<FinalWidgetPrivate> d_ptr;

private:
    Q_DISABLE_COPY(FinalWidget)
    Q_DECLARE_PRIVATE(FinalWidget);

    ISubject &m_subject;
};

#endif //QTHNI_FINALWIDGET_H
