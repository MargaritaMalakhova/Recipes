#ifndef AVAILABLERECEIPTDTO_H
#define AVAILABLERECEIPTDTO_H
#include "model/receiptdto.h"

class AvailableReceiptDto: public ReceiptDto
{
public:
    AvailableReceiptDto();
    AvailableReceiptDto(const AvailableReceiptDto &obj);

    AvailableReceiptDto& operator = (const AvailableReceiptDto &s)//переопределение оператора присваивания
    {
        id = s.id;
        name = s.name;
        description = s.description;
        amountPorsion = s.amountPorsion;
        return (*this);
    }

    int amountPorsion;
};

#endif // AVAILABLERECEIPTDTO_H
