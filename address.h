#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

// 주소를 나타내는 클래스
class Address {
private:
    int address_;

public:
    Address(int address) : address_(address) {} // 생성자 정의 후 int 값 받아 초기화
    std::string toString() const { return std::to_string(address_); }
    bool operator==(const Address &rhs) const { return address_ == rhs.address_; } // 연산자 오버로딩
};

#endif 
