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
    QList<UserProductsDto> getUserProductsDto();
    QList<ReceiptDto> getAllReceiptsDto();
    QStringList getAllIngredients();
    void insertProductToFridge(QString product, int count);
    QList<AvailableReceiptDto> getAvailableReceipts();
    AvailableReceiptDto convertor(ReceiptDto receiptDto, int amountPorsion);
    void cookReceipts(int receiptId, int count);

private:
    SqlService *service;
};

#endif // RECEIPTSERVICE_H
