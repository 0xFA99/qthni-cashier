#include "options/optionpage.h"
#include "options/optionpage_p.h"

OptionPagePrivate::OptionPagePrivate(OptionPage *q)
    : q_ptr(q)
{
}

OptionPagePrivate::~OptionPagePrivate() = default;

void OptionPagePrivate::init()
{
    Q_Q(OptionPage);
}

OptionPage::OptionPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new OptionPagePrivate(this))
{
    d_func()->init();
}

OptionPage::~OptionPage() = default;