#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //связывает сигналы от кнопок с необходимыми слотами
    connect(
        ui->showRecptBtn, &QPushButton::clicked,
        this, &MainWindow::showRecptBtn_clicked
    );

    connect(
        ui->addIngrButton, &QPushButton::clicked,
        this, &MainWindow::addIngrButton_clicked
    );

    //сигналы и слоты вкладок
    connect(
        ui->tabWidget, &QTabWidget::currentChanged,
        this, &MainWindow::chooseWidget
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initShow()
{
    ui->tabWidget->setCurrentIndex(0);

    //формируем таблицы
    drawIngrFridgeTab();
    drawAllRecipes();
    drawAvailableRecipes();

}

void MainWindow::cleanIngrFridgeTab()
{
    ui->ingrTabWdgt->setRowCount(0);
}

void MainWindow::cleanAllReceiptsTab()
{
    ui->recpTblWdgt->setRowCount(0);
}

void MainWindow::cleanAvailableReceiptsTable()
{
    ui->availableReceiptsTable->setRowCount(0);
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
    //автоматическое растягивание таблички
    ui->ingrTabWdgt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->ingrTabWdgt->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->ingrTabWdgt->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->ingrTabWdgt->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    // Скрываем колонку под номером 0
    //ui->tableWidget->hideColumn(0);


}

void MainWindow::drawAllRecipes()
{
    QStringList header;
    header.append("id");
    header.append("Название рецепта");

    ui->recpTblWdgt->setColumnCount(2);
    ui->recpTblWdgt->setShowGrid(true);
    //выделение выделение одного элемента
    ui->recpTblWdgt->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->recpTblWdgt->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->recpTblWdgt->setHorizontalHeaderLabels(header);
    //автоматическое растягивание таблички
    ui->recpTblWdgt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->recpTblWdgt->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

void MainWindow::drawAvailableRecipes()
{
    QStringList header;
    header.append("id");
    header.append("Название рецепта");
    header.append("Доступное количество");

    ui->availableReceiptsTable->setColumnCount(3);
    ui->availableReceiptsTable->setShowGrid(true);
    //выделение выделение одного элемента
    ui->availableReceiptsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->availableReceiptsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->availableReceiptsTable->setHorizontalHeaderLabels(header);
    //автоматическое растягивание таблички
    ui->availableReceiptsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->availableReceiptsTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->availableReceiptsTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
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

void MainWindow::addRowToAllReceiptsTab(int index, int id, QString name)
{
     ui->recpTblWdgt->insertRow(index);

     qDebug() << "addRowToAllReceiptsTab" << QString::number(index) << QString::number(id) << name;

     // Далее забираем все данные из результата запроса и устанавливаем в остальные поля
     ui->recpTblWdgt->setItem(index,0, new QTableWidgetItem(QString::number(id)));
     ui->recpTblWdgt->setItem(index,1, new QTableWidgetItem(name));
}

void MainWindow::addRowToAvailableReceiptsTab(int index, int id, QString name, int amountPorsion)
{
     ui->availableReceiptsTable->insertRow(index);

     qDebug() << "addRowToAvailableReceiptsTab" << QString::number(index) << QString::number(id) << name << QString::number(amountPorsion);

     // Далее забираем все данные из результата запроса и устанавливаем в остальные поля
     ui->availableReceiptsTable->setItem(index,0, new QTableWidgetItem(QString::number(id)));
     ui->availableReceiptsTable->setItem(index,1, new QTableWidgetItem(name));
     ui->availableReceiptsTable->setItem(index,2, new QTableWidgetItem(QString::number(amountPorsion)));
}

//SLOTS---------------------------------------------------------------------------------------------------
void MainWindow::showRecptBtn_clicked()
{
    QString recptIdValue;

    recptIdValue = ui->showReceiptId->text();
    emit showReceipt(recptIdValue.toInt());
}

void MainWindow::addIngrButton_clicked()
{
    emit showAddProductsWindow();
}

void MainWindow::chooseWidget(int index)
{
    switch (index)
    {
        case 0:
            emit getAllUserProducts();
            break;
        case 1:
            emit getAllReceipts();
            break;
        case 2:
            emit getAvailableReceipes();
            break;
    }
}

