#ifndef USERPRODUCTSDTO_H
#define USERPRODUCTSDTO_H
#include <QObject>
#include "model/ingredientdto.h"

class UserProductsDto : public QObject
{
public:
    UserProductsDto();

    int id;
    IngredientDto ingredient;
    int amount;
};

#endif // USERPRODUCTSDTO_H
