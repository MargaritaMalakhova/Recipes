#ifndef SQLSERVICE_H
#define SQLSERVICE_H
#include <QObject>
#include <QtSql>
#include <QFile>
#include <QDebug>

#include "model/receiptdto.h"
#include "model/ingredientdto.h"
#include "model/userproductsdto.h"
#include "model/availablereceiptdto.h"

class SqlService : public QObject
{
    Q_OBJECT
public:
    SqlService();

    ReceiptDto getReceiptById(int id);
    void getIngridientsByReceiptId(int id);//переделать на QList
    QList<UserProductsDto> getUserProducts();
    QList<ReceiptDto> getAllReceipts();
    void insertProductToFridge(QString product, int count);
    QList<IngredientDto> getIngredientsByReceiptId(int receiptId);
    QList<IngredientDto> getAllIngredients();
    void updateUserProductAmount(int productId, int IngredientLeft);

private:
    QSqlDatabase dbase;
};

#endif // SQLSERVICE_H
