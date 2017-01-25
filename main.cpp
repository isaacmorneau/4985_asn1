#include "mainwindow.h"
#include <QApplication>
/**
 * Program: 4985 Assignment 1
 *
 * Source File: main.cpp
 *
 * Functions:
 *      int main(int argc, char *argv[])
 *
 * Date: 2017/01/20
 *
 * Designer: Isaac Morneau; A00958405
 *
 * Programmer: Isaac Morneau; A00958405
 *
 * Notes: This program is a utility program to find the links between IPs and
 * Hostnames as well as the link between Services and Ports. It provides a
 * graphical interface to query the system from as follows:
 * IP by Hostname
 * Hostname by IP
 * Service by Port
 * Port by Service
 *
 * compilation:
 * The application form is built with QT and is required to rebuild the project.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
