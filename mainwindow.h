#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "networking.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_SbP_clicked();

    void on_pushButton_PbS_clicked();

    void on_pushButton_HbI_clicked();

    void on_pushButton_IbH_clicked();

private:
    void enableAll(const std::string& result);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
