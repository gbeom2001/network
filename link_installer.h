#ifndef LINK_INSTALLER_H
#define LINK_INSTALLER_H

#include "link.h"

class LinkInstaller {
public:
    Link* install(Node *a, Node *b) {
        Link* link = new Link(a, b);
        a->addLink(link);
        b->addLink(link);
        return link;
    }
};

#endif 
