#include "viewservice.h"

ViewService::ViewService()
{
    service = new ReceiptService();
    window = new MainWindow();
    window->initShow();

    connect(window,SIGNAL(showReceipt(int)),this,SLOT(on_showReceiptSgn(int)));
    connect(window,SIGNAL(getAllUserProducts()),this, SLOT(on_getAllUserProducts()));
    connect(window,SIGNAL(getAllReceipts()),this, SLOT(on_getAllReceipts()));
    connect(window,SIGNAL(showAddProductsWindow()), this, SLOT(on_showAddProductsWindow()));
    connect(window,SIGNAL(getAvailableReceipes()), this, SLOT(on_getAvailableReceipes()));
    connect(window,SIGNAL(letsCook(int,int)),this, SLOT(on_letsCook(int,int)));

    emit window->getAllUserProducts();
    window->show();
}

ViewService::~ViewService()
{
    delete service;
    delete window;
}

//SLOTS
void ViewService::on_showReceiptSgn(int recptId)
{
    QString receiptText;

    receiptText=service->getReceiptDescriptionById(recptId);

    receiptWindow = new ReceiptDescription();
    connect(this,SIGNAL(showTextReceipt(QString)),receiptWindow,SLOT(on_showReceipt(QString)));
    receiptWindow->show();

    emit showTextReceipt(receiptText);
}

void ViewService:: on_getAllUserProducts()
{
    qDebug() << "void ViewService::on_getAllUserProducts()";
    QList<UserProductsDto> products = service->getUserProductsDto();

    window->cleanIngrFridgeTab();

    for(int i = 0; i<products.size(); i++) {
        UserProductsDto product = products.at(i);
        window->addRowToIngrFridgeTab(i,product.id,product.name,product.amount,product.measureName);
    }
}

void ViewService::on_getAllReceipts()
{
    qDebug() << "void ViewService::on_getAllReceipts()";
    QList<ReceiptDto> receipts = service->getAllReceiptsDto();

    window->cleanAllReceiptsTab();

    for(int i = 0; i<receipts.size(); i++) {
        ReceiptDto receipt = receipts.at(i);
        window->addRowToAllReceiptsTab(i,receipt.id,receipt.name);
    }
}

void ViewService::on_showAddProductsWindow()
{
    qDebug() << "void ViewService::on_showAddProductsWindow()";
    AddProductWindow = new AddProductToFridgeWindow();

    QStringList ingredients = service->getAllIngredients();
    AddProductWindow->addIngredientToComboBox(ingredients);

    connect(
        AddProductWindow, &AddProductToFridgeWindow::OkClickAddProduct,
        this, &ViewService::addProductToFridgeOkHandler
    );

    AddProductWindow->show();
}

void ViewService::addProductToFridgeOkHandler(QString product, int count)
{
    qDebug() << "void ViewService::addProductToFridgeOkHandler(QString product, int count)";
    qDebug() << product << QString::number(count);
    service->insertProductToFridge(product, count);
    on_getAllUserProducts();
}

void ViewService::on_getAvailableReceipes()
{
    qDebug() << "void ViewService::on_getAvailableReceipes()";
    QList<AvailableReceiptDto> availableReceipts = service->getAvailableReceipts();

    window->cleanAvailableReceiptsTable();

    for(int i = 0; i<availableReceipts.size(); i++) {
        AvailableReceiptDto availableReceipt = availableReceipts.at(i);
        window->addRowToAvailableReceiptsTab(i,availableReceipt.id,availableReceipt.name, availableReceipt.amountPorsion);
    }
}

void ViewService::on_letsCook(int receiptId, int count)
{
    qDebug() << "void ViewService::on_letsCook(int receiptId, int count)";
    service->cookReceipts(receiptId, count);

    on_getAvailableReceipes();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Сообщение");
    msgBox.setText("Рецепт в количестве " + QString::number(count) + " порций приготовлен.");
    msgBox.exec();
}
