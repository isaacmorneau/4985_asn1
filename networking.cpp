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

    // Open up a Winsock v2.2 session
    WSAStartup(wVersionRequested, &wsaData);

    s_port = atoi(port.c_str());

    sv = getservbyport (htons(s_port), proto.c_str());
    if (sv == NULL){
        result = "Error in getservbyport";
    } else {
        sprintf(buffer, "The service for %s port %d is: %s", proto.c_str(), s_port, sv->s_name);
        result = buffer;
    }
    WSACleanup();
    return result;
}

std::string PbS(const std::string &service, const std::string &proto){
    delay(3);
    return "done";
}

std::string HbI(const std::string &ip){
    delay(3);
    return "done";
}

std::string IbH(const std::string &hostname){
    delay(3);
    return "done";
}
