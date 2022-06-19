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
