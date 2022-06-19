#ifndef INGREDIENTDTO_H
#define INGREDIENTDTO_H
#include <QObject>

class IngredientDto : public QObject
{
public:
    IngredientDto();

    int id;
    QString name;
    QString measureName;
};

#endif // INGREDIENTDTO_H
