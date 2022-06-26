#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initShow();

    void cleanIngrFridgeTab();
    void cleanAllReceiptsTab();
    void cleanAvailableReceiptsTable();
    void addRowToIngrFridgeTab(int index, int id, QString name, int count, QString measure);
    void addRowToAllReceiptsTab(int index, int id, QString name);
    void addRowToAvailableReceiptsTab(int index, int id, QString name, int amountPorsion);
    void hasBeenCooked(int count);

signals:
    void showReceipt(int recptId);
    void getAllUserProducts();
    void getAllReceipts();
    void showAddProductsWindow();
    void getAvailableReceipes();
    void letsCook(int id,int count);

private slots:
    void showRecptBtn_clicked();
    void chooseWidget(int index);
    void addIngrButton_clicked();
    void letsCookBtn_clicked();
    void availableReceiptsTable_clicked();

private:
    void drawIngrFridgeTab();
    void drawAllRecipes();
    void drawAvailableRecipes();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
