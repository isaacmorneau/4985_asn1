#include "networking.h"

void delay(int seconds)
{
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

const std::string& SbP(const std::string &port){
    delay(3);
    return "done";
}

const std::string& PbS(const std::string &service){
    delay(3);
    return "done";
}

const std::string& HbI(const std::string &ip){
    delay(3);
    return "done";
}

const std::string& IbH(const std::string &hostname){
    delay(3);
    return "done";
}
