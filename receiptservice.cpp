#include "receiptservice.h"

ReceiptService::ReceiptService()
{
    service = new SqlService();
}

QString ReceiptService::getReceiptDescriptionById(int receiptId)
{
    ReceiptDto receipt = service->getReceiptById(receiptId);
       QList<IngredientDto> ingredients = service->getIngredientsByReceiptId(receiptId);
       QString receiptText =  "Ингредиенты для рецепта \"" + receipt.name + "\":  \n";
       for(int i = 0; i < ingredients.size(); i++) {
          IngredientDto ingredient = ingredients.at(i);
          qDebug() <<  ingredient.name + " " + QString::number(ingredient.amount) + " "  + ingredient.measureName;
          receiptText = receiptText + ingredient.name + " " + QString::number(ingredient.amount) + " "  + ingredient.measureName + "\n";
       }

    receiptText = receiptText  + "\n" + receipt.description;
    return receiptText;
}

QList<UserProductsDto> ReceiptService::getUserProducts()
{
       qDebug() << "QList<UserProductsDto> ReceiptService::getUserProductsDto()";
       return service->getUserProducts();
}

QList<ReceiptDto> ReceiptService::getAllReceipts()
{
       qDebug() << "QList<ReceiptDto> ReceiptService::getAllReceiptsDto()";
       return service->getAllReceipts();
}

QStringList ReceiptService::getAllIngredientsWithMeasure()
{
    QStringList ingredientAndMesuare;
    QList<IngredientDto> ingredients = service->getAllIngredients();
    for (int i = 0; i < ingredients.size(); i++) {
         IngredientDto ingrDto = ingredients.at(i);
         ingredientAndMesuare.append(ingrDto.name + " (" +ingrDto.measureName+ ")");
    }

    return ingredientAndMesuare;
}

QStringList ReceiptService::getAllUserProductNamesWithMeasure()
{
    QStringList productNames;
    QList<UserProductsDto> userProducts = getUserProducts();

    for (int i = 0; i < userProducts.size(); i++) {
         UserProductsDto userProductDto = userProducts.at(i);
         productNames.append(userProductDto.name + " (" +userProductDto.measureName+ ")");
    }

    return productNames;
}



void ReceiptService::insertProductToFridge(QString productName, int count)
{
    qDebug() << "ReceiptService::insertProductToFridge(QString productName, int count): " << productName;
    service->insertProductToFridge(productName, count);
}

QString ReceiptService::removeProductFromFridge(QString productName, int countToDelete)
{
    qDebug() << "ReceiptService::removeProductFromFridge(QString productName, int count): " << productName;
    UserProductsDto product = service->getUserProductByName(productName);
    if(product.amount < countToDelete) {
        return "Вы пытаетесь убрать из холодильника продукта "+ product.name +
                " больше, чем там есть.\n\nДоступное количество: " + QString::number(product.amount) +
                ".\nВы пытаетесь убрать " + QString::number(countToDelete) +
                ".\n\nПересмотрите возможности вашего холодильника.";

    }
    service->removeProductFromFridgeByProductName(productName, countToDelete);
    return "";
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
        service->removeProductFromFridge(toUpdate.id, countToDelete);
    }
}

QList<AvailableReceiptDto> ReceiptService::getAvailableReceipts()
{
    qDebug() << "QList<ReceiptDto> ReceiptService::getAvailableReceipts()";
    QList<ReceiptDto> receipts = service->getAllReceiptsWithAvailableIngredients();
    QList<AvailableReceiptDto> availableReceipts;
    QList<UserProductsDto> userProducts = getUserProducts();

    for (int i = 0; i < receipts.size(); i++) {
        ReceiptDto currentReceipt = receipts.at(i);
        QList<IngredientDto> ingredients = service->getIngredientsByReceiptId(currentReceipt.id);
        int availableCount = 99999;
        for (int j = 0; j < ingredients.size(); j++) {
            if(availableCount == 0) {
                break;
            }
            int count = 0;
            IngredientDto ingredient = ingredients.at(j);
            for(int k = 0; k < userProducts.size(); k++) {
                UserProductsDto userProduct = userProducts.at(k);
                if(userProduct.name == ingredient.name) {
                    count = userProduct.amount/ingredient.amount;
                    if(count < availableCount) {
                        availableCount = count;
                    }
                    break;
                }
                if(k == userProducts.size()-1){
                   availableCount = 0;
                }
            }
        }

        if (availableCount > 0) {
            AvailableReceiptDto availableReceipt = convertReceiptDtoToAvailableReceiptDto(currentReceipt, availableCount);
            availableReceipts.append(availableReceipt);
        }
     }
    return availableReceipts;

}

AvailableReceiptDto ReceiptService::convertReceiptDtoToAvailableReceiptDto(ReceiptDto receiptDto, int amountPorsion)
{
    AvailableReceiptDto availableReceipt;
    availableReceipt.id = receiptDto.id;
    availableReceipt.name = receiptDto.name;
    availableReceipt.description = receiptDto.description;
    availableReceipt.amountPorsion = amountPorsion;

    return availableReceipt;
}
