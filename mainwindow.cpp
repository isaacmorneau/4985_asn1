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

}

void MainWindow::on_pushButton_Find_clicked()
{
    //disable controls
    ui->pushButton_Find->setEnabled(false);
    ui->lineEdit_bot->setEnabled(false);
    ui->lineEdit_top->setEnabled(false);

    if(ui->radioButton_SbP->isChecked()){
        ui->textBrowser_Result->setText("Searching for Service...");
        ui->textBrowser_Result->setText(SbP(ui->lineEdit_top->text().toStdString(),
                      ui->lineEdit_bot->text().toStdString()).c_str());
        ui->lineEdit_bot->setEnabled(true);
    }
    if(ui->radioButton_PbS->isChecked()){
        ui->textBrowser_Result->setText("Searching for Port...");
        ui->textBrowser_Result->setText(PbS(ui->lineEdit_top->text().toStdString(),
                      ui->lineEdit_bot->text().toStdString()).c_str());
        ui->lineEdit_bot->setEnabled(true);
    }
    if(ui->radioButton_HbI->isChecked()){
        ui->textBrowser_Result->setText("Searching for Hostname...");
        ui->textBrowser_Result->setText(HbI(ui->lineEdit_top->text().toStdString()).c_str());
    }
    if(ui->radioButton_IbH->isChecked()){
        ui->textBrowser_Result->setText("Searching for IP...");
        ui->textBrowser_Result->setText(IbH(ui->lineEdit_top->text().toStdString()).c_str());
    }

    //enable controls
    ui->pushButton_Find->setEnabled(true);
    ui->lineEdit_top->setEnabled(true);
}

void MainWindow::on_radioButton_SbP_clicked()
{
    ui->lineEdit_top->setToolTip("Port");
    ui->lineEdit_bot->setToolTip("Protocol");
    ui->lineEdit_bot->setEnabled(true);
}

void MainWindow::on_radioButton_PbS_clicked()
{

    ui->lineEdit_top->setToolTip("Service");
    ui->lineEdit_bot->setToolTip("Protocol");
    ui->lineEdit_bot->setEnabled(true);
}

void MainWindow::on_radioButton_IbH_clicked()
{

    ui->lineEdit_top->setToolTip("Hostname");
    ui->lineEdit_bot->setToolTip("Not Used For Query");
    ui->lineEdit_bot->setEnabled(false);
}

void MainWindow::on_radioButton_HbI_clicked()
{

    ui->lineEdit_top->setToolTip("IP Address");
    ui->lineEdit_bot->setToolTip("Not Used For Query");
    ui->lineEdit_bot->setEnabled(false);
}
