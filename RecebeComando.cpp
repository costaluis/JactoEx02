#include "RecebeComando.h"
#include <vector>
#include <string>

RecebeComando::RecebeComando(QObject *parent) : QObject(parent), Mensageiro(zmq::socket_type::sub, Mensageiro::transport_type::ipc) {
    RecebeComando::startConnection();
}

RecebeComando::~RecebeComando() {
    this->stopReceiveMessage();
    this->closeConnection();
}

void RecebeComando::startConnection() {
    _socket->connect(Mensageiro::_transport_header_map.at(this->_transport_type).data() + std::string("/tmp/0"));
}

void RecebeComando::stopReceiveMessage() {
    _running.store(false);
    if (_receiver_thread.joinable()) {
        _receiver_thread.join();
    }
    _socket->set(zmq::sockopt::unsubscribe, _old_topic);
}


void RecebeComando::receiveMessage() {
    if (_running.load()) {
        stopReceiveMessage();
    }

    _socket->set(zmq::sockopt::subscribe, _topic.toStdString());
    _old_topic = _topic.toStdString();

    _running.store(true);
    _receiver_thread = std::thread([this](){
        while (_running.load()) {
            std::vector<zmq::message_t> msg_contents;
            zmq::recv_result_t result = zmq::recv_multipart(*_socket, std::back_inserter(msg_contents), zmq::recv_flags::dontwait);
            if (result) {
                _msg = QString(msg_contents[1].to_string().data());
                emit msgReceived();
            }
        }
    });
}
