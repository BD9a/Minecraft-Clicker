import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4

ApplicationWindow {
    visible: true
    width: 432
    height: 648
    title: qsTr("Minecraft Clicker")
    maximumHeight: height
    maximumWidth: width

    minimumHeight: height
    minimumWidth: width

    onClosing:{
        Config.save();
    }

    FontLoader {
        id: adobeFont
        source: "./assets/fonts/AdobeClean-Regular.ttf"
    }


    Rectangle {
        id: line
        x: 0
        y: 0
        width: 432
        height: 65
        SequentialAnimation on color {
            loops: Animation.Infinite
            ColorAnimation { from: "#ff7373"; to: "#73ff73"; duration: 8000 }
            ColorAnimation { from: "#73ff73"; to: "#7373ff"; duration: 8000 }
            ColorAnimation { from: "#7373ff"; to: "#ff7373"; duration: 8000 }
        }



        Rectangle {
            id: darkTop
            x: 0
            y: 0
            width: 432
            height: 60
            color: "#1c1c1c"
        }

        Text {
            id: clickerName
            x: 8
            y: 20
            color: "#fbfbfb"
            text: qsTr("Minecraft Clicker")
            font.family: adobeFont.name
            font.pixelSize: 20
        }
    }

    Image {
        source: "watermark.png" //Your "watermark", make it blurry for better effect.
        x: 164
        y: 179
        width: 104
        height: 104
    }

    Rectangle {
        id: configPanel
        x: 0
        y: 411
        width: 432
        height: 237
        color: "#eaeaea"

            SpinBox {
                id: mincps
                x: 13
                y: 38
                width: 124
                height: 40
                editable: true
                to: 19
                from: 1
                value: Config.minCps
                onValueModified:{
                    if(maxcps.value <= mincps.value)
                    {
                        maxcps.value++;
                    }
                    Config.setMaxCpsDelay(maxcps.value);
                    Config.setMinCpsDelay(mincps.value);
                    Clicking.loopStart();
                }

                Text {
                    x: -3
                    y: -15
                    text: qsTr("Minimum CPS for Left Click")
                    font.letterSpacing: 0
                    font.pixelSize: 11
                    font.family: adobeFont.name
                }

            }
            SpinBox {
                id: maxcps
                x: 13
                y: 99
                width: 124
                height: 40
                editable: true
                to: 20
                from: 1
                value: Config.maxCps
                onValueModified:{
                    if(maxcps.value <= mincps.value)
                    {
                        maxcps.value++;
                    }
                    Config.setMaxCpsDelay(maxcps.value);
                    Config.setMinCpsDelay(mincps.value);
                    Clicking.loopStart();
                }

                Text {
                    x: -3
                    y: -15
                    text: qsTr("Maximum CPS for Left Click")
                    font.pixelSize: 11
                    font.family: adobeFont.name
                }

            }
            SpinBox {
                id: rspinBox
                x: 13
                y: 156
                width: 124
                height: 40
                editable: true
                to: 100
                from: 1
                value: Config.delay
                onValueModified:{
                    Config.setDelay(rspinBox.value);
                    Building.loopStart();
                }
                Text {
                    x: 17
                    y: -13
                    text: qsTr("CPS for Right Click")
                    font.pixelSize: 11
                    font.family: adobeFont.name
                }

            }

        Item{width: 1; height: 3;}
        InvBind {
            x: 304
            y: 182
            keyName: "E"
            onAccepted: {
                var a = keyTranslator.getCode(keyName);
                if(a === 404){
                    askForKey()
                } else {
                    Config.setEqBindKey(keyTranslator.getCode(keyName))
                }
            }

            Text {
                x: 18
                y: -43
                width: 84
                height: 11
                text: qsTr("Inventory button (cancel clicking/building)")
                wrapMode: Text.WordWrap
                font.letterSpacing: 0
                font.pixelSize: 11
                font.family: adobeFont.name
            }
        }
        LeftBind {
            x: 304
            y: 38
            keyName: "R"
            onAccepted: {
                var a = keyTranslator.getCode(keyName);
                if(a === 404){
                    askForKey()
                } else {
                    Config.setcToggleButton(keyTranslator.getCode(keyName))
                }
            }

            Text {
                x: 42
                y: -15
                text: qsTr("Fighting")
                font.letterSpacing: 0
                font.pixelSize: 11
                font.family: adobeFont.name
            }
        }
        RightBind {
            id: testowanie
            x: 304
            y: 99
            keyName: "R"
            onAccepted: {
                var a = keyTranslator.getCode(keyName);
                if(a === 404){
                    askForKey()
                } else {
                    Config.setbToggleButton(keyTranslator.getCode(keyName))
                }

            }

            Text {
                x: 41
                y: -15
                text: qsTr("Building")
                font.letterSpacing: 0
                font.pixelSize: 11
                font.family: adobeFont.name
            }
        }
    }

    ComboBox {
        id: comboBox
        x: 66
        y: 361
        width: 301
        height: 32
        model: Config.nazwy
        onActivated:{
            Config.setWindowName(comboBox.currentText);
        }

        TapHandler {
            onTapped:{
                comboBox.model = Config.bumpNames();
            }
        }

        Text {
            x: 28
            y: -16
            text: qsTr("Choose <u>Window Name</u> where You want to use it:")
            font.pixelSize: 12
            font.family: adobeFont.name
        }
    }
}
