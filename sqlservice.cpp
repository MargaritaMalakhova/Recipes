#include "sqlservice.h"

SqlService::SqlService()
{
    dbase = QSqlDatabase:: addDatabase ("QSQLITE");
    QString dbFileName ("C:/sqlite3/Recipes.sqlite");
    dbase.setDatabaseName(dbFileName);

    if (!dbase.open()) {qDebug() << "База данных не открылась";}
    else {qDebug() << "База данных открыта";}
}

ReceiptDto SqlService::getReceiptById(int id)
{
    ReceiptDto result;
    QSqlQuery a_query;
    QString query = "SELECT * FROM recipes WHERE ID_recipe = %1";

    QString finalSQL = query.arg(id);

    qDebug() << finalSQL;

    a_query.exec(finalSQL);

    //Создали объект записи:
    QSqlRecord rec = a_query.record();

    if (a_query.next())
    {
        result.id = a_query.value(rec.indexOf("ID_recipe")).toInt();
        result.description = a_query.value(rec.indexOf("discription")).toString();
        result.name = a_query.value(rec.indexOf("name_recipe")).toString();
    } else {
        result.id = 0;
    }

    return  result;
}

QList<UserProductsDto> SqlService::getUserProducts()
{
    qDebug() << "QList<UserProductsDto> SqlService::getUserProducts()";
    QList<UserProductsDto> userProductsList;
    QSqlQuery a_query;

    QString query = "SELECT ID_field, name_ing, amount_ing, name_measure "
                    "FROM (ings_in_fridge INNER JOIN ings ON ings_in_fridge.ID_ing = ings.ID_ing) "
                    "INNER JOIN measures ON ings.ID_measure = measures.ID_measure";
    a_query.exec(query);
    QSqlRecord rec = a_query.record();

    while (a_query.next())
    {
        UserProductsDto userProduct;
        userProduct.id = a_query.value(rec.indexOf("ID_field")).toInt();
        userProduct.name = a_query.value(rec.indexOf("name_ing")).toString();
        userProduct.amount = a_query.value(rec.indexOf("amount_ing")).toInt();
        userProduct.measureName = a_query.value(rec.indexOf("name_measure")).toString();
        userProductsList.append(userProduct);
    }
    return userProductsList;
}
