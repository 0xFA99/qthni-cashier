#include "hmaterialpage.h"
#include "hmaterialpage_p.h"

#include <QGridLayout>

#include "hmaterialframe.h"

HProductPagePrivate::HProductPagePrivate(HProductPage *q)
    : q_ptr(q)
{
}

HProductPagePrivate::~HProductPagePrivate()
{
}

void HProductPagePrivate::init()
{
    Q_Q(HProductPagePrivate);

    m_layout    = new QGridLayout(q);

    HMaterialFrame *frame1 = new HMaterialFrame(q);
    HMaterialF
}
