import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import NetworkMngr.qml 1.0
import EmployeeCard 1.0
import TestPlugin 1.0
import AccessType 1.0
import QtQml.Models 2.1
import QtQuick.XmlListModel 2.0

Window {
    visible: true
    id: root
    title: qsTr("Hello World")
    width: _img.width
    height: _img.height + _btn.height

    Column {
        BorderImage {
            id: _img
            border { left: 30; top: 30; right: 30; bottom: 30 }
            horizontalTileMode: BorderImage.Repeat
            verticalTileMode: BorderImage.Repeat
            source: "file:///home//rsadhu//Desktop//pic1.jpeg"

        }

        Button {
            id:  _btn
            text: "press"
            onClicked: {

            }
        }
    }
}


