
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml.Models 2.1
import QtQuick.XmlListModel 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12


import NetworkMngr.qml 1.0
import EmployeeCard 1.0
import TestPlugin 1.0
import AccessType 1.0



Window {
   // width: 200
 //   height: 300
    visible: true
    id: root
    GridLayout {
        anchors.fill: parent
        id: grid
        columns: 10
        //rows: 2
        //layoutDirection: Qt.RightToLeft
        Text { text: "Three"; font.bold: true; }
        Button { text: "1" ;}
        Text { text: "words"; color: "red" }
        Button { text: "2" ;}
        Text { text: "in"; font.underline: true }
        Button { text: "3" ;}
        Text { text: "a"; font.pixelSize: 20 }
        Button { text: "4" ;}
        Text { text: "row"; font.strikeout: true }
        Button { text: "5" ;}

    }   
}



