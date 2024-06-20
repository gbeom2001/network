#ifndef ECHO_SERVICE_INSTALLER_H
#define ECHO_SERVICE_INSTALLER_H

#include "address.h"
#include "echo_service.h"
#include "service_installer.h"

class EchoServiceInstaller : public ServiceInstaller {
private:
    short listenPort_;

public:
    EchoServiceInstaller(short listenPort) : listenPort_(listenPort) {}

    EchoService* install(Host *host) {
        EchoService *service = new EchoService(host, listenPort_);
        ServiceInstaller::install(host, service);
        return service;
    }
};

#endif 
