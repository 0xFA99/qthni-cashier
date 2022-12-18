#ifndef QTHNI_MEMBERCHOOSER_H
#define QTHNI_MEMBERCHOOSER_H

#include "qtmaterial/components/qtmaterialautocomplete.h"

class MemberChooserPrivate;
class MemberChooser : public QtMaterialAutoComplete
{
    Q_OBJECT

public:
    explicit MemberChooser(QWidget *parent = nullptr);
    ~MemberChooser();

protected:
    const QScopedPointer<MemberChooserPrivate> d_ptr;

private:
    void initMemberList();

    Q_DISABLE_COPY(MemberChooser)
    Q_DECLARE_PRIVATE(MemberChooser)
};

#endif //QTHNI_MEMBERCHOOSER_H
