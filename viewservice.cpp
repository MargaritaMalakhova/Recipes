#include "viewservice.h"

ViewService::ViewService()
{
    service = new ReceiptService();
    window = new MainWindow();
    window->show();

    connect(window,SIGNAL(showReceipt(int)),this,SLOT(on_showReceiptSgn(int)));
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
