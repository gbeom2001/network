#ifndef MANUAL_ROUTER_H
#define MANUAL_ROUTER_H

#include "address.h"
#include "router.h"

class ManualRouter : public Router {
public:
    void addRoutingEntry(const Address &destination, Link *nextLink) {
        routingTable_.emplace_back(destination, nextLink);
    }

    void receivePacket(Packet *packet) override {
        std::cout << "Router #" << std::to_string(id()) << ": forwarding packet (from: "
                  << packet->srcAddress().toString() << ", to: "
                  << packet->destAddress().toString() << ", " 
                  << packet->dataString().size() << " bytes)" << std::endl;

        for (const auto& entry : routingTable_) {
            if (entry.destination == packet->destAddress()) {
                entry.nextLink->transmitPacket(packet, this);
                return;
            }
        }

        std::cout << "Router #" << std::to_string(id()) << ": no route for packet (from: "
                  << packet->srcAddress().toString() << ", to: "
                  << packet->destAddress().toString() << ", "
                  << packet->dataString().size() << " bytes)" << std::endl;
    }
};

#endif 
