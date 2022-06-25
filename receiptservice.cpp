#include "receiptservice.h"

ReceiptService::ReceiptService()
{
    service = new SqlService();
}

QString ReceiptService::getReceiptDescriptionById(int receiptId)
{
    ReceiptDto receipt = service->getReceiptById(receiptId);
       QList<IngredientDto> ingredients = service->getIngredientsByReceiptId(receiptId);
       QString receiptText = "";
       receiptText = receiptText + "Ингредиенты для рецепта " + "\""+receipt.name + + "\":  \n";
       for(int i = 0; i < ingredients.size(); i++) {
          IngredientDto ingredient = ingredients.at(i);
          qDebug() <<  ingredient.name + " " + QString::number(ingredient.amount) + " "  + ingredient.measureName;
          receiptText = receiptText + ingredient.name + " " + QString::number(ingredient.amount) + " "  + ingredient.measureName + "\n";
       }

    receiptText = receiptText  + "\n" + receipt.description;
    return receiptText;
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
    QList<IngredientDto> ingredients = service->getAllIngredients();
//TODO: добавить логику вывода списка ингредиентов и его меру из БД
    for (int i = 0; i < ingredients.size(); i++) {
         IngredientDto ingrDto = ingredients.at(i);
         ingredientAndMesuare.append(ingrDto.name + " (" +ingrDto.measureName+ ")");
    }



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
    QList<AvailableReceiptDto> availableReceipts;
     for (int i = 0; i < receipts.size(); i++)
     {
        AvailableReceiptDto availableReceipt;
        availableReceipt = convertor(receipts.at(i), 2+i);
        availableReceipts.append(availableReceipt);
     }
    return availableReceipts;

}

void ReceiptService::cookReceipts(int receiptId, int count)
{
    qDebug() << "void ReceiptService::cookReceipts(int receiptId, int count)" << receiptId << " " << count;
    QList<IngredientDto> ingredients = service->getIngredientsByReceiptId(receiptId);
    QList<UserProductsDto> allProducts = service->getUserProducts();
    for(int i = 0; i<ingredients.size(); i++) {
        IngredientDto ingredient = ingredients.at(i);
        int countToDelete = ingredient.amount * count;
        UserProductsDto toUpdate;
        for(int j = 0; j<allProducts.size(); j++) {
            UserProductsDto product = allProducts.at(j);
            if(ingredient.name == product.name) {
                toUpdate = product;
                break;
            }
        }
        int ingredientLeft = toUpdate.amount - countToDelete;
        service->updateUserProductAmount(toUpdate.id, ingredientLeft);
    }
}
