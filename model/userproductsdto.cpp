#include "userproductsdto.h"

UserProductsDto::UserProductsDto()
{

}

UserProductsDto::UserProductsDto(const UserProductsDto &obj)
{
    id = obj.id;
    name = obj.name;
    amount = obj.amount;
    measureName = obj.measureName;

}
