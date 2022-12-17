#ifndef QTHNI_PROFILEDIALOG_H
#define QTHNI_PROFILEDIALOG_H

#include <QWidget>

class ProfileDialogPrivate;
class ProfileDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileDialog(QWidget *parent = nullptr);
    ~ProfileDialog();

    void initImagePack();

signals:
    void closedProfileDialog();

protected:
    const QScopedArrayPointer<ProfileDialogPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProfileDialog)
    Q_DECLARE_PRIVATE(ProfileDialog)
};

#endif //QTHNI_PROFILEDIALOG_H
