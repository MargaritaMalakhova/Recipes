#ifndef USERPRODUCTSDTO_H
#define USERPRODUCTSDTO_H
#include <QObject>

class UserProductsDto : public QObject
{
public:
    UserProductsDto();
    UserProductsDto(const UserProductsDto &obj);

    UserProductsDto& operator = (const UserProductsDto &s)
    {
        id = s.id;
        name = s.name;
        amount = s.amount;
        measureName = s.measureName;
        return (*this);
    }

    int id;
    QString name;
    int amount;
    QString measureName;

};

#endif // USERPRODUCTSDTO_H
