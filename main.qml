import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    title: qsTr("Exercício 02")
    width: 640
    height: 480
    visible: true

    StackView {
        id: myStackView
        initialItem: "Principal.qml"
        anchors.fill: parent
    }
}
