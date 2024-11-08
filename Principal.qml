import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Item {
    id: mainView

    Column {
        spacing: 30
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }

        Button {
            id: bt01

            height: 50
            width: 200

            background: Rectangle {
                color: parent.hovered ? "gray" : "lightgray"
            }

            text: "Receber"
            onClicked: {
                myStackView.push("Recebe.qml")
            }
        }

        Button {
            id: bt02

            height: 50
            width: 200

            background: Rectangle {
                color: parent.hovered ? "gray" : "light gray"
            }

            text: "Sair/Encerrar"
            onClicked: Qt.quit()
        }
    }
}
