import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Cpp_Elements 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Exercício 02")


    RecebeComando {
        id: recebeComando

        topic: "test"
        message: "testando"

        Component.onCompleted: {
            recebeComando.receiveMessage()
        }
    }

    Text {
        text: recebeComando.message
    }

}
