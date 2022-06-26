#include "addproducttofridge.h"
#include "ui_addproducttofridge.h"

AddProductToFridgeWindow::AddProductToFridgeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProductToFridgeWindow)
{
    QValidator *validator = new QIntValidator(0, 999999, this);
    ui->setupUi(this);
    //ui->lineEdit->setInputMask("9");
    ui->lineEdit->setValidator(validator);

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
