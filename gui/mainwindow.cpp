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

void MainWindow::initShow()
{
    ui->tabWidget->setCurrentIndex(0);
    drawIngrFridgeTab();

    emit getAllUserProducts();
}

void MainWindow::drawIngrFridgeTab()
{
    QStringList header;
    header.append("id");
    header.append("Название");
    header.append("Количество");
    header.append("Мера");

    ui->ingrTabWdgt->setColumnCount(4);
    ui->ingrTabWdgt->setShowGrid(true);
    //выделение выделение одного элемента
    ui->ingrTabWdgt->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->ingrTabWdgt->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->ingrTabWdgt->setHorizontalHeaderLabels(header);
    //ui->ingrTabWdgt->
    // Скрываем колонку под номером 0
    //ui->tableWidget->hideColumn(0);


}

void MainWindow::addRowToIngrFridgeTab(int index, int id, QString name, int count, QString measure)
{
     ui->ingrTabWdgt->insertRow(index);

     qDebug() << "addRowToIngrFridgeTab" << QString::number(index) << QString::number(id) << name;


     // Далее забираем все данные из результата запроса и устанавливаем в остальные поля
     ui->ingrTabWdgt->setItem(index,0, new QTableWidgetItem(QString::number(id)));
     ui->ingrTabWdgt->setItem(index,1, new QTableWidgetItem(name));
     ui->ingrTabWdgt->setItem(index,2, new QTableWidgetItem(QString::number(count)));
     ui->ingrTabWdgt->setItem(index,3, new QTableWidgetItem(measure));

}
