#ifndef NETWORKING_H
#define NETWORKING_H
#include <QThread>
#include <string>

typedef void (* completionFunc)(const std::string &);


class ServiceByPortThread : public QThread{
public:
    void run();
    ServiceByPortThread(completionFunc func):done(func){}
private:
    completionFunc done;
};


class PortByServiceThread : public QThread{
public:
    void run();
    PortByServiceThread(completionFunc func):done(func){}
private:
    completionFunc done;
};


class HostnameByIpThread : public QThread{
public:
    void run();
    HostnameByIpThread(completionFunc func):done(func){}
private:
    completionFunc done;
};


class IPByHostname : public QThread{
public:
    void run();
    IPByHostname(completionFunc func):done(func){}
private:
    completionFunc done;
};

#endif // NETWORKING_H
