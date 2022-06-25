#include "receiptservice.h"

ReceiptService::ReceiptService()
{
    service = new SqlService();
}

QString ReceiptService::getReceiptDescriptionById(int id)
{
    ReceiptDto receipt = service->getReceiptById(id);
//TODO: добавить логику вывода ингредиентов рецепта
    QString text = receipt.description;
    return text;
}

QList<UserProductsDto> ReceiptService::getUserProductsDto()
{
       qDebug() << "QList<UserProductsDto> ReceiptService::getUserProductsDto()";
       return service->getUserProducts();
}

QList<ReceiptDto> ReceiptService::getAllReceiptsDto()
{
       qDebug() << "QList<ReceiptDto> ReceiptService::getAllReceiptsDto()";
       return service->getAllReceipts();
}

QStringList ReceiptService::getAllIngredients()
{
    QStringList ingredientAndMesuare;
//TODO: добавить логику вывода списка ингредиентов и его меру из БД
    IngredientDto ingrDto;

    ingredientAndMesuare.append("Яблоко (Грамм)");
    ingredientAndMesuare.append("Яйцо (Штуки)");

    return ingredientAndMesuare;
}

void ReceiptService::insertProductToFridge(QString product, int count)
{
    service->insertProductToFridge(product, count);
}

AvailableReceiptDto ReceiptService::convertor(ReceiptDto receiptDto, int amountPorsion)
{
    AvailableReceiptDto availableReceipt;
    availableReceipt.id = receiptDto.id;
    availableReceipt.name = receiptDto.name;
    availableReceipt.description = "Просто описание";
    availableReceipt.amountPorsion = amountPorsion;

    return availableReceipt;
}


QList<AvailableReceiptDto> ReceiptService::getAvailableReceipts()
{
    qDebug() << "QList<ReceiptDto> ReceiptService::getAllReceiptsDto()";
    QList<ReceiptDto> receipts = service->getAllReceipts();
      //в цикле преобразовать дто
      //получить и вернуть новый лист
    QList<AvailableReceiptDto> availableReceipts;
     for (int i = 0; i < receipts.size(); i++)
     {
        AvailableReceiptDto availableReceipt;
        availableReceipt = convertor(receipts.at(i), 2+i);
        availableReceipts.append(availableReceipt);
     }
    return availableReceipts;

}
