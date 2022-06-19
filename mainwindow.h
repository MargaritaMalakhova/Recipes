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

signals:
    void showReceipt(int recptId);

private slots:
    void showRecptBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
