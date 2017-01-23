#ifndef NETWORKING_H
#define NETWORKING_H

#include <QTime>
#include <QApplication>
#include <string>

#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")

void delay(int seconds);

std::string SbP(const std::string &port, const std::string &proto);
std::string PbS(const std::string &service, const std::string &proto);
std::string HbI(const std::string &ip);
std::string IbH(const std::string &hostname);

#endif // NETWORKING_H
