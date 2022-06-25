#include "addproducttofridge.h"
#include "ui_addproducttofridge.h"

AddProductToFridgeWindow::AddProductToFridgeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProductToFridgeWindow)
{
    ui->setupUi(this);
    ui->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    connect(
        this, &QDialog::accepted,
        this, &AddProductToFridgeWindow::addProductToFridgeOkHandler
    );
}

AddProductToFridgeWindow::~AddProductToFridgeWindow()
{
    delete ui;
}

void AddProductToFridgeWindow::addIngredientToComboBox(QStringList ingredients)
{
    ui->comboBox->addItems(ingredients);
}

void AddProductToFridgeWindow::addProductToFridgeOkHandler()
{
    qDebug() << "AddProductToFridgeWindow::addProductToFridgeOkHandler()!!!!!";
    QString product = ui->comboBox->currentText();
    int count = ui->lineEdit->text().toInt();

    emit OkClickAddProduct(product, count);

}
