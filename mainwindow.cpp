#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(
        ui->showRecptBtn, &QPushButton::clicked,
        this, &MainWindow::showRecptBtn_clicked
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRecptBtn_clicked()
{
    QString recptIdValue;

    recptIdValue = ui->showReceiptId->text();
    emit showReceipt(recptIdValue.toInt());
}

