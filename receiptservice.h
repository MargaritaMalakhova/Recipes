#ifndef RECEIPTSERVICE_H
#define RECEIPTSERVICE_H
#include <QObject>
#include "sqlservice.h"

class ReceiptService : public QObject
{
    Q_OBJECT
public:
    ReceiptService();
    QString getReceiptById(int id);
    QList<UserProductsDto> getUserProductsDto();

private:
    SqlService *service;
};

#endif // RECEIPTSERVICE_H
