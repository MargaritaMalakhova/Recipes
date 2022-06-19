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
    void addRowToIngrFridgeTab(int index, int id, QString name, int count, QString measure);

signals:
    void showReceipt(int recptId);
    void getAllUserProducts();

private slots:
    void showRecptBtn_clicked();

private:
    void drawIngrFridgeTab();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
