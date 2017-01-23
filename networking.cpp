#include "networking.h"

void delay(int seconds)
{
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

std::string SbP(const std::string &port, const std::string &proto){
    std::string result;
    char buffer[256];
    struct servent *sv;
    int s_port;

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

    s_port = atoi(port.c_str());

    sv = getservbyport (htons(s_port), proto.c_str());
    if (sv == NULL)
        sprintf(buffer,"Service not found for port %d",s_port);
    else
        sprintf(buffer, "The service for %s port %d is: %s", proto.c_str(), s_port, sv->s_name);
    result = buffer;
    WSACleanup();
    return result;
}

std::string PbS(const std::string &service, const std::string &proto){
    std::string result;
    char buffer[256];
    struct servent *sv;

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

    sv = getservbyname (service.c_str(), proto.c_str());
    if (sv == NULL)
        sprintf(buffer,"Port not found for service %s", service.c_str());
    else
        sprintf (buffer, "The port number for %s is: %d\n", service.c_str(), ntohs(sv->s_port));
    result = buffer;
    WSACleanup();
    return result;
}

std::string HbI(const std::string &ip){
    delay(3);
    return "done";
}

std::string IbH(const std::string &hostname){
    delay(3);
    return "done";
}
