#include "receiptservice.h"

ReceiptService::ReceiptService()
{
    service = new SqlService();
}

QString ReceiptService::getReceiptById(int id)
{
   ReceiptDto receipt = service->getReceiptById(id);

   // QString text = "string for receipt " + QString::number(id);
    QString text = receipt.description;
    return text;
}
