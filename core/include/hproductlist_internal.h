#ifndef HPRODUCTLIST_INTERNAL_H
#define HPRODUCTLIST_INTERNAL_H

class HProductListItem : public QWidget
{
    Q_OBJECT

public:
    HProductListItem(HProductList *parent);
    ~HProductListItem();

private:
    Q_DISABLE_COPY(HProductListItem)

    HProductList *const m_productList;
};

#endif
