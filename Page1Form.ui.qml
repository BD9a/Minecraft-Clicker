import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 640
    height: 380
    header: Label {
        text: qsTr("Left Mouse Button")
        font.bold: true
        font.family: roboto.name
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
        color: "#000000"
    }

    Rectangle {
        id: rectangle
        x: 0
        y: -47
        width: 640
        height: 47
        color: "#FFC107"
    }
}
