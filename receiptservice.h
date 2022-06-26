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
    void insertProductToFridge(QString product, int count);
    QList<AvailableReceiptDto> getAvailableReceipts();
    void cookReceipts(int receiptId, int count);

private:
    AvailableReceiptDto convertReceiptDtoToAvailableReceiptDto(ReceiptDto receiptDto, int amountPorsion);
    SqlService *service;
};

#endif // RECEIPTSERVICE_H
