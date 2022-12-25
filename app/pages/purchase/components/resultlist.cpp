#include "purchase/components/resultlist.h"
#include "purchase/components/resultlist_p.h"

#include "layout/flowlayout.h"
#include "widgets/items/searchitem.h"

#include "products/ProductObject.h"

ResultListPrivate::ResultListPrivate(ResultList *q)
    : q_ptr(q)
{
}

ResultListPrivate::~ResultListPrivate() = default;

void ResultListPrivate::init()
{
    Q_Q(ResultList);

    m_layout        = new FlowLayout(q);

    /*
    SearchItem *s1 = new SearchItem(q);
    SearchItem *s2 = new SearchItem(q);
    SearchItem *s3 = new SearchItem(q);
    SearchItem *s4 = new SearchItem(q);
    SearchItem *s5 = new SearchItem(q);
    SearchItem *s6 = new SearchItem(q);
    SearchItem *s7 = new SearchItem(q);
    SearchItem *s8 = new SearchItem(q);
    SearchItem *s9 = new SearchItem(q);
    SearchItem *s10 = new SearchItem(q);
    SearchItem *s11 = new SearchItem(q);
    SearchItem *s12 = new SearchItem(q);
    SearchItem *s13 = new SearchItem(q);
    SearchItem *s14 = new SearchItem(q);
    SearchItem *s15 = new SearchItem(q);
    SearchItem *s16 = new SearchItem(q);
    SearchItem *s17 = new SearchItem(q);
    SearchItem *s18 = new SearchItem(q);

    m_layout->addWidget(s1);
    m_layout->addWidget(s2);
    m_layout->addWidget(s3);
    m_layout->addWidget(s4);
    m_layout->addWidget(s5);
    m_layout->addWidget(s6);
    m_layout->addWidget(s7);
    m_layout->addWidget(s8);
    m_layout->addWidget(s9);
    m_layout->addWidget(s10);
    m_layout->addWidget(s11);
    m_layout->addWidget(s12);
    m_layout->addWidget(s13);
    m_layout->addWidget(s14);
    m_layout->addWidget(s15);
    m_layout->addWidget(s16);
    m_layout->addWidget(s17);
    m_layout->addWidget(s18);
    */

}

ResultList::ResultList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ResultListPrivate(this))
{
    d_func()->init();
}

ResultList::~ResultList() = default;

void ResultList::addProductObjectShow(SearchItem* item)
{
    Q_D(ResultList);

    d->m_layout->addWidget(item);
}

void ResultList::deleteProductObjectShow(int index)
{
    Q_D(ResultList);

    SearchItem *item;
    for (int i = 0; i < d->m_layout->count(); i++) {
        QLayoutItem *litem = d->m_layout->itemAt(i);

        if (i > index && (item = dynamic_cast<SearchItem *>(litem->widget()))) {
            item->setIndex(item->index() - 1);
        }
    }

    QLayoutItem *litem = d->m_layout->itemAt(index);
    if ((item = dynamic_cast<SearchItem *>(litem->widget()))) {
        item->deleteLater();
    }
}