#ifndef QTHNI_FRAMETITLE_P_H
#define QTHNI_FRAMETITLE_P_H

#include <QLabel>

class QVBoxLayout;

class FrameTitle;
class FrameTitlePrivate
{
    Q_DISABLE_COPY(FrameTitlePrivate)
    Q_DECLARE_PUBLIC(FrameTitle)

public:
    explicit FrameTitlePrivate(FrameTitle *q);
    ~FrameTitlePrivate();

    void init();

    FrameTitle *const       q_ptr;
    QVBoxLayout             *m_layout;
    QLabel                  *m_title;
    QColor                  m_titleColor;
    int                     m_fontSize;
};

#endif //QTHNI_FRAMETITLE_P_H
