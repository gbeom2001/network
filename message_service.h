#ifndef MESSAGE_SERVICE_H
#define MESSAGE_SERVICE_H

#include "address.h"
#include "host.h"
#include "service.h"
#include <iostream>

class MessageService : public Service {
    friend class MessageServiceInstaller;

private:
    Address destAddress_;
    short destPort_;
    MessageService(Host *host, short port, Address destAddress, short destPort)
        : Service(host, port), destAddress_(destAddress), destPort_(destPort) {}

public:
    void send(std::string message) {
        std::vector<char> data(message.begin(), message.end());
        Packet packet(host_->address(), destAddress_, port_, destPort_, data);
        host_->send(&packet);
    }

    void handlePacket(Packet *packet) override {
        std::cout << "MessageService: received \"" << packet->dataString()
                  << "\" from " << packet->srcAddress().toString() << ":" << packet->srcPort()
                  << std::endl;
    }
};

#endif 
