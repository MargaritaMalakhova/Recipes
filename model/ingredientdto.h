#ifndef INGREDIENTDTO_H
#define INGREDIENTDTO_H
#include <QObject>

class IngredientDto : public QObject
{
public:
    IngredientDto();
    IngredientDto(const IngredientDto &obj);

    IngredientDto& operator=(const IngredientDto &other)
    {
        id = other.id;
        name = other.name;
        amount = other.amount;
        measureName = other.measureName;

        return (*this);
    }

    int id;
    QString name;
    int amount;
    QString measureName;
};

#endif // INGREDIENTDTO_H
