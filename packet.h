#ifndef PACKET_H
#define PACKET_H

#include "address.h"
#include <string>
#include <vector>

class Packet {
public:
    Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::string data);
    Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::vector<char> data);

    Address srcAddress() const;
    Address destAddress() const;
    short srcPort() const;
    short destPort() const;
    const std::vector<char>& data() const;
    std::string dataString() const;

private:
    Address srcAddress_;
    Address destAddress_;
    short srcPort_;
    short destPort_;
    std::vector<char> data_;
};

#endif 
