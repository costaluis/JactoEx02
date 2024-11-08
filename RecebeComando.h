#ifndef RECEBECOMANDO_H
#define RECEBECOMANDO_H

#include <QObject>
#include <thread>
#include <atomic>
#include "Mensageiro.h"

class RecebeComando : public QObject, private Mensageiro
{
    Q_OBJECT
    Q_PROPERTY(QString message MEMBER _msg NOTIFY msgReceived)
    Q_PROPERTY(QString topic MEMBER _topic)
public:
    RecebeComando(QObject *parent = nullptr);
    ~RecebeComando();

    Q_INVOKABLE void receiveMessage();

signals:
    void msgReceived();

private:
    void startConnection() override;
    void stopReceiveMessage();
    QString _topic;
    QString _msg;
    std::thread _receiver_thread;
    std::atomic_bool _running {false};
};

#endif // RECEBECOMANDO_H
