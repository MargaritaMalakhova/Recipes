#include "receiptservice.h"

ReceiptService::ReceiptService()
{
    service = new SqlService();
}

QString ReceiptService::getReceiptById(int id)
{
    QString text = "string for receipt " + QString::number(id);
    return text;
}
