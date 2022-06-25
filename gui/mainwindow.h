#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

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

signals:
    void showReceipt(int recptId);
    void getAllUserProducts();
    void getAllReceipts();
    void showAddProductsWindow();
    void getAvailableReceipes();

private slots:
    void showRecptBtn_clicked();
    void chooseWidget(int index);
    void addIngrButton_clicked();

private:
    void drawIngrFridgeTab();
    void drawAllRecipes();
    void drawAvailableRecipes();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
