#ifndef HOST_H
#define HOST_H

#include "address.h"
#include "packet.h"
#include "service.h"
#include "node.h"
#include <vector>
#include <cstdlib>

class Host : public Node {
    friend class ServiceInstaller;

private:
    Address address_;
    std::vector<Service *> services_;

public:
    Address address() { return address_; }
    Host(Address address) : address_(address) {}
    ~Host() {
        for (auto service : services_) {
            delete service;
        }
    }

    void initialize() {
        services_.clear();
    }

    void send(Packet *packet) override {
        std::string from = packet->srcAddress().toString();
        std::string to = packet->destAddress().toString();
        std::string packetSize = std::to_string(packet->dataString().size());

        std::cout << "Host #" << std::to_string(id()) << ": sending packet (from: " << from
                  << ", to: " << to << ", " << packetSize << " bytes)" << std::endl;

        int linkSize = std::rand() % linklist().size();
        Link* link = linklist()[linkSize];
        link->transmitPacket(packet, this);
    }

    void receive(Packet *packet) override {
        std::cout << "Host #" << std::to_string(id()) << ": received packet, destination port: " 
                  << packet->destPort() << std::endl;

        bool handled = false;
        for (auto service : services_) {
            if (service->port() == packet->destPort()) {
                service->handlePacket(packet);
                handled = true;
                break;
            }
        }

        if (!handled) {
            std::cout << "Host #" << std::to_string(id()) << ": no service for packet (from: "
                      << packet->srcAddress().toString() << ", to: "
                      << packet->destAddress().toString() << ", "
                      << packet->dataString().size() << " bytes)" << std::endl;
        }
    }

    void addService(Service* service) {
        services_.push_back(service);
    }
};

#endif 
