#ifndef RECEIPTDTO_H
#define RECEIPTDTO_H
#include <QObject>

class ReceiptDto : public QObject
{
public:
    ReceiptDto();
    ReceiptDto(const ReceiptDto &obj);

    int id;
    QString name;
    QString description;
};

#endif // RECEIPTDTO_H
