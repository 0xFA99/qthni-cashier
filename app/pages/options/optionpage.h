#ifndef QTHNI_OPTIONPAGE_H
#define QTHNI_OPTIONPAGE_H

#include <QWidget>

class OptionPagePrivate;
class OptionPage : public QWidget
{
    Q_OBJECT

public:
    explicit OptionPage(QWidget *parent = nullptr);
    ~OptionPage();

protected:
    const QScopedPointer<OptionPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(OptionPage)
    Q_DECLARE_PRIVATE(OptionPage)
};

#endif //QTHNI_OPTIONPAGE_H
