#ifndef NETWORKING_H
#define NETWORKING_H

#include <QTime>
#include <QApplication>
#include <string>



void delay(int seconds);

const std::string& SbP(const std::string &port);
const std::string& PbS(const std::string &service);
const std::string& HbI(const std::string &ip);
const std::string& IbH(const std::string &hostname);

#endif // NETWORKING_H
