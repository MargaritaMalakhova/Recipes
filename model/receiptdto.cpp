#include "receiptdto.h"

ReceiptDto::ReceiptDto()
{

}

ReceiptDto::ReceiptDto(const ReceiptDto &obj)
{
    id = obj.id;
    name = obj.name;
    description = obj.description;
}
