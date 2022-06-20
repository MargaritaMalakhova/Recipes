#include "viewservice.h"

ViewService::ViewService()
{
    service = new ReceiptService();
    window = new MainWindow();
    window->initShow();

    connect(window,SIGNAL(showReceipt(int)),this,SLOT(on_showReceiptSgn(int)));
    connect(window,SIGNAL(getAllUserProducts()),this, SLOT(on_getAllUserProducts()));
    connect(window,SIGNAL(getAllReceipts()),this, SLOT(on_getAllReceipts()));

    emit window->getAllUserProducts();
    window->show();
}

void ViewService::on_showReceiptSgn(int recptId)
{
    QString receiptText;

    receiptText=service->getReceiptById(recptId);

    receiptWindow = new ReceiptDescription();
    connect(this,SIGNAL(showTextReceipt(QString)),receiptWindow,SLOT(on_showReceipt(QString)));
    receiptWindow->show();

    emit showTextReceipt(receiptText);
}


//SLOTS
void ViewService::on_getAllUserProducts()
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

}
