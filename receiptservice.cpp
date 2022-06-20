#include "receiptservice.h"

ReceiptService::ReceiptService()
{
    service = new SqlService();
}

QString ReceiptService::getReceiptById(int id)
{
    ReceiptDto receipt = service->getReceiptById(id);

    QString text = receipt.description;
    return text;
}

QList<UserProductsDto> ReceiptService::getUserProductsDto()
{
       qDebug() << "QList<UserProductsDto> ReceiptService::getUserProductsDto()";
       return service->getUserProducts();
}
