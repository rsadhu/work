import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle {
        id: rect
        width: 100; height: 100
        color: "red"

        SequentialAnimation {
            running: true
            NumberAnimation { target: rect; property: "x"; to: root.width ; duration: 1000 }
            NumberAnimation { target: rect; property: "y"; to: root.height; duration: 1000 }
        }
    }
}
