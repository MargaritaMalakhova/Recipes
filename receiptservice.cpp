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

QList<UserProductsDto> ReceiptService::getUserProductsDto()
{
    QList<UserProductsDto> testList;
    UserProductsDto test1;
    test1.id = 1;
    test1.name = "Картошка";
    test1.amount = 1000;
    test1.measureName = "Грамм";

      UserProductsDto test2;
    test2.id = 22;
    test2.name = "Яйцо";
    test2.amount = 3;
    test2.measureName = "Штук";

    testList.append(test1);
    testList.append(test2);
    return testList;
}
