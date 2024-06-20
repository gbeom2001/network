#ifndef LINK_H
#define LINK_H

#include "packet.h"

class Node;

class Link {
    friend class LinkInstaller;

private:
    Node *nodeA_;
    Node *nodeB_;

    Link(Node *nodeA, Node *nodeB) : nodeA_(nodeA), nodeB_(nodeB) {}

    Node *other(const Node *node) const {
        return node == nodeA_ ? nodeB_ : nodeA_;
    }

public:
    void transmitPacket(Packet *packet, Node *sender) {
        Node *receiver = other(sender);
        std::cout << "Link: forwarding packet from node #" << sender->id() << ", to node #" << receiver->id() << std::endl;
        receiver->receivePacket(packet);
    }
};

#endif // LINK_H
