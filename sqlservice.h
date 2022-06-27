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
    UserProductsDto getUserProductByName(QString productName);
    QList<ReceiptDto> getAllReceipts();
    QList<ReceiptDto> getAllReceiptsWithAvailableIngredients();
    void insertProductToFridge(QString product, int count);
    QList<IngredientDto> getIngredientsByReceiptId(int receiptId);
    QList<IngredientDto> getAllIngredients();
    void removeProductFromFridge(int productId, int count);
    void removeProductFromFridgeByProductName(QString productName, int count);

private:
    QSqlDatabase dbase;
};

#endif // SQLSERVICE_H
