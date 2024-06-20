#ifndef MESSAGE_SERVICE_INSTALLER_H
#define MESSAGE_SERVICE_INSTALLER_H

#include "address.h"
#include "message_service.h"
#include "service_installer.h"

class MessageServiceInstaller : public ServiceInstaller {
private:
    Address destAddress_;
    short destPort_;

public:
    MessageServiceInstaller(const Address &destAddress, short destPort)
        : destAddress_(destAddress), destPort_(destPort) {}

    MessageService* install(Host *host) {
        MessageService *service = new MessageService(host, port_, destAddress_, destPort_);
        ServiceInstaller::install(host, service);
        return service;
    }
};

#endif 
