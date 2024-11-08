#ifndef MENSAGEIRO_H
#define MENSAGEIRO_H

#include <memory>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <map>

class Mensageiro {


protected:
    enum class transport_type {
        tcp,
        udp,
        pgm,
        norm,
        ipc,
        inproc,
        gssapi
    };

    Mensageiro(zmq::socket_type socket_type, Mensageiro::transport_type transport_type) : _transport_type(transport_type) {
        _context = std::make_unique<zmq::context_t>();
        _socket = std::make_unique<zmq::socket_t>(*_context, socket_type);
    }

    virtual void startConnection() = 0;
    virtual void closeConnection() {_socket->close();};

    inline static const std::map<transport_type, std::string_view> _transport_header_map = {
        {transport_type::tcp, "tcp://"},
        {transport_type::udp, "udp://"},
        {transport_type::pgm, "pgm://"},
        {transport_type::norm, "norm://"},
        {transport_type::ipc, "ipc://"},
        {transport_type::inproc, "inproc://"},
        {transport_type::gssapi, "gssapi://"}
    };

    std::unique_ptr<zmq::context_t> _context;
    std::unique_ptr<zmq::socket_t> _socket;
    transport_type _transport_type;
};


#endif // MENSAGEIRO_H
