#ifndef VIEWSERVICE_H
#define VIEWSERVICE_H
#include <QObject>

#include "gui/mainwindow.h"
#include "gui/receiptdescription.h"
#include "receiptservice.h"

class ViewService : public QObject
{
    Q_OBJECT
public:
    ViewService();

signals:
    void showTextReceipt(QString receipt);

private slots:
    void on_showReceiptSgn(int recptId);
    void on_getAllUserProducts();
    void on_getAllReceipts();

private:
    MainWindow *window;
    ReceiptDescription *receiptWindow;
    ReceiptService *service;
};

#endif // VIEWSERVICE_H
