#ifndef QTHNI_SEARCHITEM_P_H
#define QTHNI_SEARCHITEM_P_H

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

#include <QUuid>
#include <QLocale>

class QLabel;
class QVBoxLayout;

class SearchItem;
class SearchItemPrivate
{
    Q_DISABLE_COPY(SearchItemPrivate)
    Q_DECLARE_PUBLIC(SearchItem)

public:
    explicit SearchItemPrivate(SearchItem *q);
    ~SearchItemPrivate();

    void init();

    SearchItem *const       q_ptr;
    QVBoxLayout             *m_layout;
    QtMaterialAvatar        *m_avatar;
    QLabel                  *m_title;
    QLabel                  *m_subTitle;
    QtMaterialFlatButton    *m_button;
    bool                    m_hasAdded;

    QUuid                   m_uuid;
    QLocale                 m_locale;
};

#endif //QTHNI_SEARCHITEM_P_H
