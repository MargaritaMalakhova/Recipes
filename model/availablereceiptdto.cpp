#include "availablereceiptdto.h"

AvailableReceiptDto::AvailableReceiptDto()//конструктор по умолчанию объекта класса
{

}

AvailableReceiptDto::AvailableReceiptDto(const AvailableReceiptDto &obj)//конструктор копии
{
        id = obj.id;
        name = obj.name;
        description = obj.description;
        amountPorsion = obj.amountPorsion;
}
