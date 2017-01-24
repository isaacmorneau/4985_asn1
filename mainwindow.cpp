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
    ui->pushButton_Find->setEnabled(true);
    ui->lineEdit_bot->setEnabled(true);
    ui->lineEdit_top->setEnabled(true);

    ui->textBrowser_Result->setText(result.c_str());
}

//disable other options until result is found
void MainWindow::disableAll(){
    ui->pushButton_Find->setEnabled(false);
    ui->lineEdit_bot->setEnabled(false);
    ui->lineEdit_top->setEnabled(false);
}


void MainWindow::SbP_clicked()
{
    ui->textBrowser_Result->setText("Searching for Service...");
    disableAll();
    enableAll(SbP(ui->lineEdit_top->text().toStdString(),
                  ui->lineEdit_bot->text().toStdString()));
}

void MainWindow::PbS_clicked()
{
    ui->textBrowser_Result->setText("Searching for Port...");
    disableAll();
    enableAll(PbS(ui->lineEdit_top->text().toStdString(),
                  ui->lineEdit_bot->text().toStdString()));
}

void MainWindow::HbI_clicked()
{
    ui->textBrowser_Result->setText("Searching for Hostname...");
    disableAll();
    enableAll(HbI(ui->lineEdit_top->text().toStdString()));
}

void MainWindow::IbH_clicked()
{
    ui->textBrowser_Result->setText("Searching for IP...");
    disableAll();
    enableAll(IbH(ui->lineEdit_top->text().toStdString()));
}

void MainWindow::on_pushButton_Find_clicked()
{
    if(ui->radioButton_SbP->isChecked())
        SbP_clicked();
    if(ui->radioButton_PbS->isChecked())
        PbS_clicked();
    if(ui->radioButton_HbI->isChecked())
        HbI_clicked();
    if(ui->radioButton_IbH->isChecked())
        IbH_clicked();
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
