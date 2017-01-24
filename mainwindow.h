#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

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
    void on_pushButton_Find_clicked();

    void on_radioButton_SbP_clicked();

    void on_radioButton_PbS_clicked();

    void on_radioButton_IbH_clicked();

    void on_radioButton_HbI_clicked();

private:
    void enableAll(const std::string& result);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
