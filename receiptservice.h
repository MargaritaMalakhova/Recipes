#ifndef RECEIPTSERVICE_H
#define RECEIPTSERVICE_H
#include <QObject>
#include "sqlservice.h"

class ReceiptService : public QObject
{
    Q_OBJECT
public:
    ReceiptService();
    QString getReceiptDescriptionById(int id);
    QList<UserProductsDto> getUserProducts();
    QList<ReceiptDto> getAllReceipts();
    QStringList getAllIngredientsWithMeasure();
    QStringList getAllUserProductNamesWithMeasure();
    void insertProductToFridge(QString productName, int count);
    QList<AvailableReceiptDto> getAvailableReceipts();
    void cookReceipts(int receiptId, int count);
    QString removeProductFromFridge(QString productName, int countToDelete);

private:
    AvailableReceiptDto convertReceiptDtoToAvailableReceiptDto(ReceiptDto receiptDto, int amountPorsion);
    SqlService *service;
};

#endif // RECEIPTSERVICE_H
