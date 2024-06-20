#include "packet.h"

// 생성자: 문자열 데이터를 사용하는 경우
Packet::Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::string data)
    : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort), destPort_(destPort), data_(data.begin(), data.end()) {
}

// 생성자: 벡터 데이터를 사용하는 경우
Packet::Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::vector<char> data)
    : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort), destPort_(destPort), data_(data) {
}

// 전송자 주소 반환
Address Packet::srcAddress() const {
    return srcAddress_;
}

// 수신자 주소 반환
Address Packet::destAddress() const {
    return destAddress_;
}

// 전송자 포트 반환
short Packet::srcPort() const {
    return srcPort_;
}

// 수신자 포트 반환
short Packet::destPort() const {
    return destPort_;
}

// 패킷 데이터 반환
const std::vector<char>& Packet::data() const {
    return data_;
}

// 패킷 데이터를 문자열로 변환하여 반환
std::string Packet::dataString() const {
    return std::string(data_.begin(), data_.end());
}
