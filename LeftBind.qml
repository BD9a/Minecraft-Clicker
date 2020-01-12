import QtQuick 2.9
import QtQuick.Controls 2.4

Item {
    id: root
    width: 120
    height: 40
    signal accepted
    property string text: "Left Mouse Button + "+"<u><b>"+keyName+"</u></b>"
    property string keyName
    property bool isListening: false
    property color fontColor1: "#000000"
    property color fontColor2: "#9B1B03"
    function askForKey(){
        if(!root.isListening){
            txt.text = "Press Key"
        }
        root.isListening = true
        root.focus = true
    }
    Timer {
        id: focusTimer
        interval: 500; running: root.focus; repeat: true
        onTriggered: {
            if(txt.color == root.fontColor1){
                txt.color = root.fontColor2
            }else{
                txt.color = root.fontColor1
            }
        }
    }

    Keys.onPressed: {
        if(root.isListening){
            switch(event.key){
            case 16777251:
                root.keyName="ALT";
                break;
            case 32:
                root.keyName="SPACE";
                break;
            default:
                root.keyName=event.text.toUpperCase();
                break;
            }
            txt.text = "Left Mouse Button + "+"<u><b>"+root.keyName+"</u></b>"
            root.isListening = false
            root.focus = false
            txt.color = root.fontColor1
            root.accepted()
        }
    }
    FontLoader {
        id: roboto
        source: "../assets/fonts/AdobeClean-Regular.ttf"
    }

    Rectangle {
        id: rectangle
        color: "#d1d1d1"
        anchors.fill: parent

        Text {
            id: txt
            width: 100
            font.family: roboto.name
            height: 34
            color: root.fontColor1
            text: root.text
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            if(!root.focus){
                txt.color = root.fontColor2
            }
        }
        onExited: {
            if(!root.focus){
                txt.color = root.fontColor1
            }
        }
        onClicked: {
            root.askForKey()
        }
    }
}
