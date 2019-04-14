import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2


ApplicationWindow {
    visible: true
    width: 640
    height: 380
    maximumHeight: height
    maximumWidth: width

    minimumHeight: height
    minimumWidth: width
    title: qsTr("Minecraft Clicker")


    FontLoader {
        id: roboto
        source: "./assets/fonts/Roboto-Light.ttf"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form
        {
            Rectangle {
                id: rectangle
                width: 640
                height: 380
                color: "#EEEEEE"
                SpinBox {
                    id: mincps
                    x: 42
                    y: 235
                    width: 124
                    height: 40
                    editable: true
                    to: 19
                    from: 1
                    value: 10
                    onValueModified:{
                        if(maxcps.value <= mincps.value)
                        {
                           maxcps.value++;
                        }
                        Clicking.setMaxCpsDelay(maxcps.value);
                        Clicking.setMinCpsDelay(mincps.value);
                        Clicking.loopReset();
                    }

                    Text {
                        id: mincpstxt
                        x: 0
                        y: -17
                        width: 124
                        height: 17
                        text: qsTr("minCps")
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 14
                        rightPadding: 0
                        font.family: roboto.name
                        horizontalAlignment: Text.AlignHCenter
                        lineHeight: 1
                        topPadding: 0
                        font.bold: true
                    }

                }
                SpinBox {
                    id: maxcps
                    x: mincps.x + mincps.width + 10;
                    y: 235
                    width: 124
                    height: 40
                    editable: true
                    to: 20
                    from: 1
                    value: 15
                    onValueModified:{
                        if(maxcps.value <= mincps.value)
                        {
                           maxcps.value++;
                        }
                        Clicking.setMaxCpsDelay(maxcps.value);
                        Clicking.setMinCpsDelay(mincps.value);
                        Clicking.loopReset();
                    }

                    Text {
                        id: maxcpstxt
                        y: -17
                        width: 124
                        height: 17
                        text: qsTr("maxCps")
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 14
                        rightPadding: 0
                        font.family: roboto.name
                        horizontalAlignment: Text.AlignHCenter
                        lineHeight: 1
                        topPadding: 0
                        font.bold: true
                    }

                }
            }

        }

        Page2Form
        {
            Rectangle {
                id: rectangle1
                width: 640
                height: 380
                color: "#EEEEEE"
                SpinBox {
                    id: rspinBox
                    x: 42
                    y: 235
                    width: 124
                    height: 40
                    editable: true
                    to: 100
                    from: 1
                    value: 100
                    onValueModified:{
                        Building.setDelay(rspinBox.value);
                        Building.loopReset();
                    }
                    Text {
                        id: element4
                        x: 0
                        y: -17
                        width: 124
                        height: 17
                        text: qsTr("CPS amount")
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 14
                        rightPadding: 0
                        font.family: roboto.name
                        horizontalAlignment: Text.AlignHCenter
                        lineHeight: 1
                        topPadding: 0
                        font.bold: true
                    }

                }
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        background: Rectangle {
            id: main
            color: "#FFC107"
        }

        TabButton {
            height: main.height
            text: qsTr("LMB")
            font.bold: true
            font.family: roboto.name
            font.pixelSize: Qt.application.font.pixelSize * 1.75
            background: Rectangle {
                height: main.height
                color: tabBar.currentIndex == 0 ? "#FFC107" : "#607D8B"
            }

        }
        TabButton {
            height: main.height
            text: qsTr("RMB")
            font.bold: true
            font.family: roboto.name
            font.pixelSize: Qt.application.font.pixelSize * 1.75
            background: Rectangle {
                height: main.height
                color: tabBar.currentIndex == 1 ? "#FFC107" : "#607D8B"
            }
        }
    }
    Item{width: 1; height: 3;}
    KeyPicker {
        x: 512
        y: 55
        keyName: "E"
        onAccepted: {
            var a = keyTranslator.getCode(keyName);
            if(a === 404){
                askForKey()
            } else {
                Building.setEqBindKey(keyTranslator.getCode(keyName))
                Clicking.setEqBindKey(keyTranslator.getCode(keyName))
            }
        }

            Text {
                id: element
                x: -121
                y: 0
                width: 120
                height: 40
                text: qsTr("Inventory button: ")
                font.family: roboto.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                font.pointSize: 11
            }
    }
    KeyPicker {
        x: 512
        y: 101
        keyName: "R"
        onAccepted: {
            var a = keyTranslator.getCode(keyName);
            if(a === 404){
                askForKey()
            } else {
                Clicking.setToggleButton(keyTranslator.getCode(keyName))
            }
        }

        Text {
            x: -121
            y: 0
            width: 120
            height: 40
            text: qsTr("LMB + ")
            font.family: roboto.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.pointSize: 11
        }
    }
    KeyPicker {
        x: 512
        y: 147
        keyName: "R"
        onAccepted: {
            var a = keyTranslator.getCode(keyName);
            if(a === 404){
                askForKey()
            } else {
                Building.setToggleButton(keyTranslator.getCode(keyName))
            }
        }

        Text {
            x: -121
            y: 0
            width: 120
            height: 40
            text: qsTr("RMB + ")
            font.family: roboto.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.pointSize: 11
        }
    }
    TextField {
        id: textInput
        x: 432
        y: 7
        width: 200
        height: 33
        text: "Minecraft 1.8.8 (Blazingpack.pl)"
        font.pixelSize: 12
        onTextEdited:{
            Building.setWindowName(textInput.text);
            Clicking.setWindowName(textInput.text);
        }
    }
}
