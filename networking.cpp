#include "networking.h"

void delay(int seconds)
{
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

std::string SbP(const std::string &port, const std::string &proto){
    std::string result;
    std::stringstream ss;
    struct servent *sv;
    int s_port;

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

    s_port = atoi(port.c_str());

    sv = getservbyport (htons(s_port), proto.c_str());
    if (sv == NULL)
        ss << "Service not found for port " << s_port;
    else
        ss << "The service for " << proto << " port " << s_port << " is: " << sv->s_name;
    result = ss.str();
    WSACleanup();
    return result;
}

std::string PbS(const std::string &service, const std::string &proto){
    std::string result;
    std::stringstream ss;
    struct servent *sv;

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

    sv = getservbyname (service.c_str(), proto.c_str());
    if (sv == NULL)
        ss << "Port not found for service " << service.c_str();
    else
        ss << "The port number for " << service.c_str() << " is: " << ntohs(sv->s_port);
    result = ss.str();
    WSACleanup();
    return result;
}

std::string HbI(const std::string &ip){
    std::string result;
    std::stringstream ss;
    int		a;
    struct	hostent *hp;
    struct	in_addr my_addr, *addr_p;
    char	**p;
    char	ip_address[256];      // String for IP address

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

    addr_p = &my_addr;
    if ((a = inet_addr(ip.c_str())) == 0){
        result = "IP Address must be of the form x.x.x.x";
        return result;
    }

    strcpy(ip_address, ip.c_str());

    addr_p->s_addr=inet_addr(ip_address);

    //use blocking call but process events before and after to hide any freeze
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    hp = gethostbyaddr((char *)addr_p, PF_INET, sizeof (my_addr));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    if (hp == NULL)
    {
        ss << "host information for " << ip << " not found";
        result = ss.str();
        return result;
    }
    for (p = hp->h_addr_list; *p != 0; p++)
    {
        struct in_addr in;
        char **q;

        memcpy(&in.s_addr, *p, sizeof (in.s_addr));
        ss << "IP Address: " << inet_ntoa(in) << "\t Host Name: " << hp->h_name << std::endl;
        for (q = hp->h_aliases; *q != 0; q++)
            ss << " \t\t   Aliases: " << *q << std::endl;
    }
    result = ss.str();
    WSACleanup();
    return result;
}

std::string IbH(const std::string &hostname){
    std::string result;
    std::stringstream ss;
    struct	hostent *hp;
    struct	in_addr my_addr, *addr_p;
    char	**p;

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

    addr_p = &my_addr;

    //use blocking call but process events before and after to hide any freeze
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    if ((hp = gethostbyname (hostname.c_str())) == NULL)
    {
        switch (h_errno)
        {
        case HOST_NOT_FOUND:
            ss << "No such host " << hostname;
            break;
        case TRY_AGAIN:
            ss << "host " << hostname << " try again later";
            break;
        case NO_RECOVERY:
            ss <<"host " << hostname << " DNS Error\n";
            break;
        case NO_ADDRESS:
            ss << "No IP Address for " << hostname;
            break;
        default:
            ss << "Unknown Error: " << h_errno;
            break;
        }
        result = ss.str();
        return result;
    }
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    for (p = hp->h_addr_list; *p != 0; p++)
    {
        struct in_addr in;
        char **q;

        memcpy(&in.s_addr, *p, sizeof (in.s_addr));
        ss << "IP Address: " << inet_ntoa(in) << "\t Host Name: " << hp->h_name << std::endl;
        for (q = hp->h_aliases; *q != 0; q++)
            ss << " \t\t   Aliases: " << *q << std::endl;
    }
    result = ss.str();
    WSACleanup();
    return result;
}
