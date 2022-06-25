#include "sqlservice.h"

SqlService::SqlService()
{
    dbase = QSqlDatabase:: addDatabase ("QSQLITE");
    QString dbFileName ("../Recipes/Recipes.sqlite");
    dbase.setDatabaseName(dbFileName);

    if (!dbase.open()) {qDebug() << "База данных не открылась";}
    else {qDebug() << "База данных открыта";}
}

ReceiptDto SqlService::getReceiptById(int receiptId)
{
    ReceiptDto result;
    QSqlQuery a_query;

    QString query = "SELECT * FROM recipes WHERE ID = %1";
    QString finalSQL = query.arg(receiptId);

    qDebug() << finalSQL;

    a_query.exec(finalSQL);

    //Создали объект записи:
    QSqlRecord rec = a_query.record();

    if (a_query.next())
    {
        result.id = a_query.value(rec.indexOf("ID")).toInt();
        result.description = a_query.value(rec.indexOf("discription")).toString();
        result.name = a_query.value(rec.indexOf("name")).toString();
    } else {

        result.id = 0;
    }

    return result;
}

QList<IngredientDto> SqlService::getIngredientsByReceiptId(int receiptId)
{
    QList<IngredientDto> ingredientList;
    QSqlQuery a_query;

    QString query = "SELECT ings.ID, ings.name, amount_ings, measures.name "
                    "FROM (measures INNER JOIN ings ON measures.ID = ings.measures_ID) "
                    "INNER JOIN ings_to_recipes ON ings.ID = ings_to_recipes.ings_ID "
                    "WHERE recipes_ID = %1";
    QString finalSQL = query.arg(receiptId);

    qDebug() << finalSQL;

    a_query.exec(finalSQL);

    //Создали объект записи:
    QSqlRecord rec = a_query.record();

    while (a_query.next())
    {
        IngredientDto ingredient;
        ingredient.id = a_query.value(rec.indexOf("ings.ID")).toInt();
        ingredient.name = a_query.value(rec.indexOf("ings.name")).toString();
        ingredient.amount = a_query.value(rec.indexOf("amount_ings")).toInt();
        ingredient.measureName = a_query.value(rec.indexOf("measures.name")).toString();
        ingredientList.append(ingredient);
    }

    return ingredientList;
}

QList<IngredientDto> SqlService::getAllIngredients() {
    QList<IngredientDto> ingredientList;
    QSqlQuery a_query;

    QString query = "SELECT ings.ID, ings.name, amount_ings, measures.name "
                    "FROM (measures INNER JOIN ings ON measures.ID = ings.measures_ID) "
                    "INNER JOIN ings_to_recipes ON ings.ID = ings_to_recipes.ings_ID ";

    qDebug() << query;

    a_query.exec(query);

    //Создали объект записи:
    QSqlRecord rec = a_query.record();

    while (a_query.next())
    {
        IngredientDto ingredient;
        ingredient.id = a_query.value(rec.indexOf("ings.ID")).toInt();
        ingredient.name = a_query.value(rec.indexOf("ings.name")).toString();
        ingredient.amount = a_query.value(rec.indexOf("amount_ings")).toInt();
        ingredient.measureName = a_query.value(rec.indexOf("measures.name")).toString();
        ingredientList.append(ingredient);
    }

    return ingredientList;
}

QList<UserProductsDto> SqlService::getUserProducts()
{
    qDebug() << "QList<UserProductsDto> SqlService::getUserProducts()";
    QList<UserProductsDto> userProductsList;
    QSqlQuery a_query;

    QString query = "SELECT ings_in_fridge.ID, ings.name, amount_ing, measures.name "
                    "FROM (ings_in_fridge INNER JOIN ings ON ings_in_fridge.ings_ID = ings.ID) "
                    "INNER JOIN measures ON ings.measures_ID = measures.ID "
                    "WHERE amount_ing > 0";
    a_query.exec(query);
    QSqlRecord rec = a_query.record();

    while (a_query.next())
    {
        UserProductsDto userProduct;
        userProduct.id = a_query.value(rec.indexOf("ings_in_fridge.ID")).toInt();
        userProduct.name = a_query.value(rec.indexOf("ings.name")).toString();
        userProduct.amount = a_query.value(rec.indexOf("amount_ing")).toInt();
        userProduct.measureName = a_query.value(rec.indexOf("measures.name")).toString();
        userProductsList.append(userProduct);
    }
    return userProductsList;
}

QList<ReceiptDto> SqlService::getAllReceipts()
{
    qDebug() << "QList<ReceiptDto> SqlService::getAllReceipts()";
    QList<ReceiptDto> receiptsList;
    QSqlQuery a_query;

    QString query = "SELECT * FROM recipes";
    a_query.exec(query);
    QSqlRecord rec = a_query.record();

    while (a_query.next())
    {
        ReceiptDto receipt;
        receipt.id = a_query.value(rec.indexOf("ID")).toInt();
        receipt.description = a_query.value(rec.indexOf("discription")).toString();
        receipt.name = a_query.value(rec.indexOf("name")).toString();
        receiptsList.append(receipt);
    }
    return receiptsList;
}

void SqlService::insertProductToFridge(QString product, int count) {
    qDebug() << "SqlService::insertProductToFridge()";
    QString query = "INSERT INTO ings_in_fridge (ings_ID, amount_ing) "
            "VALUES ('" + product + "', "+QString::number(count)+")";
    qDebug() << query;

    QSqlQuery a_query;
    a_query.exec(query);

}

void SqlService::updateUserProductAmount(int productId, int ingredientLeft) {
    qDebug() << "void SqlService::updateUserProductAmount(int productId, int IngredientLeft);";
    QString query = "";
    query = "UPDATE ings_in_fridge SET amount_ing = " + QString::number(ingredientLeft) + " WHERE ID = " + QString::number(productId);
   // QString finalSQL = query.arg(productId, ingredientLeft);
    qDebug() << query;

    QSqlQuery a_query;
    a_query.exec(query);

}
