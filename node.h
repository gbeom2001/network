#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>

class Node {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;
  std::vector<Link *> linklist_; // 노드가 링크된 리스트

public:
  Node() : id_(nextId_++) {} // nextId를 통해 id 초기화 후 nextId 값 1 증가
  int id() const { return id_; } // id 값 반환
  virtual ~Node() {} // 가상 소멸자
  std::vector<Link *> linklist() { return linklist_; } // linklist_ 값 반환
  virtual void send(Packet *packet) = 0; // =0을 통해 순수 가상 함수 구현, 파생 클래스에서 무조건 상속받아 구현해야 함
  virtual void receive(Packet *packet) = 0;

protected:
  void addLink(Link *link) {
    linklist_.push_back(link); // 링크를 리스트에 추가
  }
};

#endif // NODE_H

