#ifndef QTHNI_FRAMETITLE_H
#define QTHNI_FRAMETITLE_H

#include <QWidget>

class FrameTitlePrivate;
class FrameTitle : public QWidget
{
    Q_OBJECT

public:
    explicit FrameTitle(QWidget *parent = nullptr);
    explicit FrameTitle(const QString &title, QWidget *parent = nullptr);
    ~FrameTitle();

    void setTitle(const QString &text);
    [[nodiscard]] QString title() const;

    void setFontSize(int size);
    int fontSize() const;

    void setTitleColor(const QColor &color);
    QColor titleColor() const;

    void addChildWidget(QWidget *widget);

protected:
    const QScopedPointer<FrameTitlePrivate> d_ptr;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(FrameTitle)
    Q_DECLARE_PRIVATE(FrameTitle)
};

#endif //QTHNI_FRAMETITLE_H
