import QtQuick 2.15
import QtQuick.Window 2.15
import MyPlugin.CustomPlugin 1.0
import QtQuick.Controls 2.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button
    {
        id: btn
        onClicked: {
         myPlugin.setStatus("Zupppppp")
         myPlugin.changeStatus("Merhaba nasilsin?")
        }
    }

    Text {
        id: name
        text: qsTr("text  "+myPlugin.status)
    }

    CustomPlugin
    {
     id: myPlugin
     status: "Namaskaaram"
     onStatusChanged: {
         changeStatus("Received new Message")
        // statusChanged("hawaiii")
     }
    }

}

