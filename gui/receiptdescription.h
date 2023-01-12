#ifndef RECEIPTDESCRIPTION_H
#define RECEIPTDESCRIPTION_H

#include <QWidget>

namespace Ui {
class ReceiptDescription;
}

class ReceiptDescription : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiptDescription(QWidget *parent = nullptr);
    ~ReceiptDescription();

public slots:
    void on_showReceipt(QString receipt);

private:
    Ui::ReceiptDescription *ui;
};

#endif // RECEIPTDESCRIPTION_H
