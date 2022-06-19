#ifndef VIEWSERVICE_H
#define VIEWSERVICE_H
#include <QObject>

#include "mainwindow.h"
#include "receiptdescription.h"
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

private:
    MainWindow *window;
    ReceiptDescription *receiptWindow;
    ReceiptService *service;
};

#endif // VIEWSERVICE_H
