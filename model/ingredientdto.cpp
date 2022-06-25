#include "ingredientdto.h"

IngredientDto::IngredientDto()
{

}


IngredientDto::IngredientDto(const IngredientDto &obj)
{
    id = obj.id;
    name = obj.name;
    amount = obj.amount;
    measureName = obj.measureName;
}
