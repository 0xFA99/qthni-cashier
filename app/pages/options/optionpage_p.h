#ifndef QTHNI_OPTIONPAGE_P_H
#define QTHNI_OPTIONPAGE_P_H

#include <QtCore>

class OptionPage;
class OptionPagePrivate
{
    Q_DISABLE_COPY(OptionPagePrivate)
    Q_DECLARE_PUBLIC(OptionPage)

public:
    explicit OptionPagePrivate(OptionPage *q);
    ~OptionPagePrivate();

    void init();

    OptionPage *const   q_ptr;
};

#endif //QTHNI_OPTIONPAGE_P_H
