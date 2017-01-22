#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->pushButton_SbP->setEnabled(true);
    ui->pushButton_PbS->setEnabled(true);
    ui->pushButton_IbH->setEnabled(true);
    ui->pushButton_HbI->setEnabled(true);

    ui->lineEdit_Result->setText(result.c_str());
}

void MainWindow::on_pushButton_SbP_clicked()
{
    ui->lineEdit_Result->setText("Searching for Service...");
    //disable other options until result is found
    ui->pushButton_HbI->setEnabled(false);
    ui->pushButton_PbS->setEnabled(false);
    ui->pushButton_IbH->setEnabled(false);

}

void MainWindow::on_pushButton_PbS_clicked()
{
    ui->lineEdit_Result->setText("Searching for Port...");
    //disable other options until result is found
    ui->pushButton_HbI->setEnabled(false);
    ui->pushButton_SbP->setEnabled(false);
    ui->pushButton_IbH->setEnabled(false);

}

void MainWindow::on_pushButton_HbI_clicked()
{
    ui->lineEdit_Result->setText("Searching for Hostname...");
    //disable other options until result is found
    ui->pushButton_SbP->setEnabled(false);
    ui->pushButton_PbS->setEnabled(false);
    ui->pushButton_IbH->setEnabled(false);

}

void MainWindow::on_pushButton_IbH_clicked()
{
    ui->lineEdit_Result->setText("Searching for IP...");
    //disable other options until result is found
    ui->pushButton_HbI->setEnabled(false);
    ui->pushButton_PbS->setEnabled(false);
    ui->pushButton_SbP->setEnabled(false);

}
