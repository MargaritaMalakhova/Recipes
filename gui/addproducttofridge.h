#ifndef ADDPRODUCTTOFRIDGE_H
#define ADDPRODUCTTOFRIDGE_H

#include <QDialog>

namespace Ui {
class AddProductToFridgeWindow;
}

class AddProductToFridgeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductToFridgeWindow(QWidget *parent = nullptr);
    ~AddProductToFridgeWindow();
    void addIngredientToComboBox(QStringList ingredients);

signals:
    void OkClickAddProduct(QString product, int count);

private slots:
    void addProductToFridgeOkHandler();

private:
    Ui::AddProductToFridgeWindow *ui;
};

#endif // ADDPRODUCTTOFRIDGE_H
