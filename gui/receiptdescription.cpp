#include "receiptdescription.h"
#include "ui_receiptdescription.h"

ReceiptDescription::ReceiptDescription(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiptDescription)
{
    ui->setupUi(this);
}

ReceiptDescription::~ReceiptDescription()
{
    delete ui;
}

void ReceiptDescription::on_showReceipt(QString receipt)
{
    ui->description->setText(receipt);
}
