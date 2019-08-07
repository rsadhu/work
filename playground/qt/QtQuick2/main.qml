import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml.Models 2.1
import QtQuick.XmlListModel 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.0
import QtQuick 2.12


import NetworkMngr.qml 1.0
import EmployeeCard 1.0
import TestPlugin 1.0
import AccessType 1.0

Window {
    visible: true
    id: root
    title: qsTr("Hello World")
    width: 400 + _list.width
    height : 300

    property MouseArea areaReceivingEvents: MouseArea {
        onClicked: {
            console.log("================================>>> ")
        }
    }

    ListModel {
        id: _model

        ListElement {
            dest: "Wroclaw"
            start: "Munich"
            airlines: "Lufthansa"
            date: "17/09/2019"
            time: "06:00"
        }

        ListElement {
            dest: "Munich"
            start: "Wroclaw"
            airlines: "Lufthansa"
            date: "13/09/2019"
            time: "17:00"        }

        ListElement {
            dest: "San Francisco , CA"
            start: "Munich"
            airlines: "Lufthansa"
            date: "12/10/2019"
            time: "16:00"
        }


        ListElement {
            dest: "Munich"
            start: "San Francisco , CA"
            airlines: "Lufthansa"
            date: "03/11/2019"
            time: "12:00"
        }
    }

    Row {

        ListView {
            id: _list
            width: 400
            model: _model

            delegate:
                Label {
                text: start + "\n" + dest + "\n" + airlines + "\n" + date + "\n" + time;
                color: "#21be2b"
                font.pixelSize: 22
                font.italic: true
            }
        }


        Button {
            //   anchors.right: root
            onClicked:{
                root.update();
            }
        }
    }
}

//        Rectangle {
//            id: rect
//            width: root.width ; height: 100
//            color: "red"

//             ParallelAnimation on width {
//                NumberAnimation { duration: 1000 }
//                NumberAnimation {
//                    duration: 1000
//                    easing.type: Easing.InOutQuad
//                    from: rect.width
//                    to : 0
//                }
//            }
//        }

//    }




