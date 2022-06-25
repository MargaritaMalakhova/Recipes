#ifndef RECEIPTDTO_H
#define RECEIPTDTO_H
#include <QObject>

class ReceiptDto : public QObject
{
public:
    ReceiptDto();
    ReceiptDto(const ReceiptDto &obj);

    ReceiptDto& operator = (const ReceiptDto &s)
    {
        id = s.id;
        name = s.name;
        description = s.description;
        return (*this);
    }

    int id;
    QString name;
    QString description;
};

#endif // RECEIPTDTO_H
