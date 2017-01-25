/**
 * Program: 4981 Assignment 1
 *
 * Source File: mainwindow.cpp
 *
 * Class: MainWindow
 *
 * Functions:
 *      explicit MainWindow(QWidget *parent = 0)
 *      ~MainWindow()
 *      void on_pushButton_Find_clicked()
 *      void on_pushButton_Sbp_clicked()
 *      void on_pushButton_PbS_clicked()
 *      void on_pushButton_HbI_clicked()
 *      void on_pushButton_IbH_clicked()
 *
 * Date: 2017/01/19
 *
 * Designer: Isaac Morneau; A00958405
 *
 * Programmer: Isaac Morneau; A00958405
 *
 * Notes: This Class holds all ui elements and handles all hooked ui events
 */
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
    /**
    * Function: MainWindow
    *
    * Date: 2017/01/20
    *
    * Designer: Isaac Morneau; A00958405
    *
    * Programmer: Isaac Morneau; A00958405
    *
    * Interface: explicit MainWindow(QWidget *parent = 0)
    *   parent - the window parent if one exists
    *
    * Return: none
    *
    * Notes: Creates window and initializes element pointer
    */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * Function: ~MainWindow()
     *
     * Date: 2017/01/20
     *
     * Designer: Isaac Morneau; A00958405
     *
     * Programmer: Isaac Morneau; A00958405
     *
     * Interface: ~MainWindow()
     *
     * Return: none
     *
     * Notes: frees ui pointers
     */
    ~MainWindow();
private slots:
    /**
     * Function: on_pushButton_Find_clicked
     *
     * Date: 2017/01/20
     *
     * Designer: Isaac Morneau; A00958405
     *
     * Programmer: Isaac Morneau; A00958405
     *
     * Interface: void on_pushButton_Find_clicked(void)
     *
     * Return: void
     *
     * Notes: triggers networking function to get form data and perform query on
     * 'Find' button click disables controls on start, enables on completion.
     */
    void on_pushButton_Find_clicked();

    /**
     * Function: on_radioButton_SbP_clicked
     *
     * Date: 2017/01/20
     *
     * Designer: Isaac Morneau; A00958405
     *
     * Programmer: Isaac Morneau; A00958405
     *
     * Interface: void on_radioButton_SbP_clicked(void)
     *
     * Return: void
     *
     * Notes: Enables both text inputs
     */
    void on_radioButton_SbP_clicked();

    /**
     * Function: on_radioButton_PbS_clicked
     *
     * Date: 2017/01/20
     *
     * Designer: Isaac Morneau; A00958405
     *
     * Programmer: Isaac Morneau; A00958405
     *
     * Interface: void on_radioButton_PbS_clicked(void)
     *
     * Return: void
     *
     * Notes: Enables both text inputs
     */
    void on_radioButton_PbS_clicked();

    /**
     * Function: on_radioButton_IbH_clicked
     *
     * Date: 2017/01/20
     *
     * Designer: Isaac Morneau; A00958405
     *
     * Programmer: Isaac Morneau; A00958405
     *
     * Interface: void on_radioButton_IbH_clicked(void)
     *
     * Return: void
     *
     * Notes: Disables the bottom text input
     */
    void on_radioButton_IbH_clicked();

    /**
     * Function: on_radioButton_HbI_clicked
     *
     * Date: 2017/01/20
     *
     * Designer: Isaac Morneau; A00958405
     *
     * Programmer: Isaac Morneau; A00958405
     *
     * Interface: void on_radioButton_HbI_clicked(void)
     *
     * Return: void
     *
     * Notes: Disables the bottom text input
     */
    void on_radioButton_HbI_clicked();

private:

    //handle to ui elements
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
