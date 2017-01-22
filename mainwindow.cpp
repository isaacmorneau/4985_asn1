#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networking.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableAll(const string& result){
    //make sure that there is a ui reff before updating
    ui->pushButton_SbP->setEnabled(true);
    ui->pushButton_PbS->setEnabled(true);
    ui->pushButton_IbH->setEnabled(true);
    ui->pushButton_HbI->setEnabled(true);

    ui->lineEdit_Result->setText(result.c_str());
}

void MainWindow::disableAll(){
    ui->pushButton_PbS->setEnabled(false);
    ui->pushButton_SbP->setEnabled(false);
    ui->pushButton_HbI->setEnabled(false);
    ui->pushButton_IbH->setEnabled(false);
}

void MainWindow::on_pushButton_SbP_clicked()
{
    ui->lineEdit_Result->setText("Searching for Service...");
    //disable other options until result is found
    disableAll();
    SbP(ui->lineEdit_SbP->text().toStdString());
    enableAll("done");

}

void MainWindow::on_pushButton_PbS_clicked()
{
    ui->lineEdit_Result->setText("Searching for Port...");
    //disable other options until result is found
    disableAll();
    PbS(ui->lineEdit_PbS->text().toStdString());
    enableAll("done");
}

void MainWindow::on_pushButton_HbI_clicked()
{
    ui->lineEdit_Result->setText("Searching for Hostname...");
    //disable other options until result is found
    disableAll();
    HbI(ui->lineEdit_HbI->text().toStdString());
    enableAll("done");
}

void MainWindow::on_pushButton_IbH_clicked()
{
    ui->lineEdit_Result->setText("Searching for IP...");
    //disable other options until result is found
    disableAll();
    IbH(ui->lineEdit_IbH->text().toStdString());
    enableAll("done");
}
