/**
 * Program: 4981 Assignment 1
 *
 * Source File: mainwindow.cpp
 *
 * Class: MainWindow
 *
 * Functions:
 *      string SbP(const std::string &port, const std::string &proto)
 *      string PbS(const std::string &service, const std::string &proto)
 *      string HbI(const std::string &ip)
 *      string IbH(const std::string &hostname)
 *
 * Date: 2017/01/21
 *
 * Designer: Isaac Morneau; A00958405
 *
 * Programmer: Isaac Morneau; A00958405
 *
 * Notes: This file holds all functions for cleanly finding information on
 * services, hosts, and IPs
 */
#ifndef NETWORKING_H
#define NETWORKING_H

#include <QTime>
#include <QApplication>
#include <string>
#include <WinSock2.h>
#include <stdio.h>
#include <sstream>

#pragma comment(lib, "ws2_32.lib")

/**
* Function: SbP
*
* Date: 2017/01/21
*
* Designer: Isaac Morneau; A00958405
*
* Programmer: Isaac Morneau; A00958405
*
* Interface: string SbP(const std::string &port, const std::string &proto)
*   port - the string of the port to lookup
*   proto - the protocol used
*
* Return: string - the formatted string of info
*
* Notes: returns formatted information on the service linked to that port
*/
std::string SbP(const std::string &port, const std::string &proto);
/**
* Function: PbS
*
* Date: 2017/01/21
*
* Designer: Isaac Morneau; A00958405
*
* Programmer: Isaac Morneau; A00958405
*
* Interface: string PbS(const std::string &service, const std::string &proto)
*   service - the string of the service to find
*   proto - the protocol used
*
* Return: string - the formatted string of info
*
* Notes: returns formatted information on the port linked to that service
*/
std::string PbS(const std::string &service, const std::string &proto);
/**
* Function: HbI
*
* Date: 2017/01/21
*
* Designer: Isaac Morneau; A00958405
*
* Programmer: Isaac Morneau; A00958405
*
* Interface: string HbI(const std::string &ip)
*   ip - the ip to lookup
*
* Return: string - the formatted string of info
*
* Notes: returns formatted information on the host linked to that IP
*/
std::string HbI(const std::string &ip);
/**
* Function: IbH
*
* Date: 2017/01/21
*
* Designer: Isaac Morneau; A00958405
*
* Programmer: Isaac Morneau; A00958405
*
* Interface: string IbH(const std::string &hostname)
*   hostname - the hostname to lookup
*
* Return: string - the formatted string of info
*
* Notes: returns formatted information on the IP linked to that hostname
*/
std::string IbH(const std::string &hostname);

#endif // NETWORKING_H
