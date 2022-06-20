#ifndef SQLSERVICE_H
#define SQLSERVICE_H
#include <QObject>
#include <QtSql>
#include <QFile>
#include <QDebug>

#include "model/receiptdto.h"
#include "model/ingredientdto.h"
#include "model/userproductsdto.h"

class SqlService : public QObject
{
    Q_OBJECT
public:
    SqlService();

    ReceiptDto getReceiptById(int id);
    void getIngridientsByReceiptId(int id);
    QList<UserProductsDto> getUserProducts();

private:
    QSqlDatabase dbase;
};

#endif // SQLSERVICE_H
