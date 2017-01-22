#include "networking.h"

void ServiceByPortThread::run(){
    done("finished");
}

void PortByServiceThread::run(){
    done("finished");
}

void HostnameByIpThread::run(){
    done("finished");
}

void IPByHostname::run(){
    done("finished");
}
