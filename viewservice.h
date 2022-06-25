#ifndef VIEWSERVICE_H
#define VIEWSERVICE_H
#include <QObject>

#include "gui/mainwindow.h"
#include "gui/receiptdescription.h"
#include "gui/addproducttofridge.h"
#include "receiptservice.h"

class ViewService : public QObject
{
    Q_OBJECT
public:
    ViewService();
    ~ViewService();

signals:
    void showTextReceipt(QString receipt);

private slots:
    void on_showReceiptSgn(int recptId);
    void on_getAllUserProducts();
    void on_getAllReceipts();
    void on_showAddProductsWindow();
    void addProductToFridgeOkHandler(QString product, int count);
    void on_getAvailableReceipes();

private:
    MainWindow *window;
    ReceiptDescription *receiptWindow;
    AddProductToFridgeWindow *AddProductWindow;
    ReceiptService *service;
};

#endif // VIEWSERVICE_H
