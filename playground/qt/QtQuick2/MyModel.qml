import QtQuick 2.0

Rectangle {

    height: 300
    width: 300

    ListModel {
        id:listModel
        ListElement { name :"Amigo"}
        ListElement { name :"Dost"}
        ListElement { name :"Freund"}
        ListElement { name :"Mitra"}
    }

    ListView {
        anchors.fill: parent
        clip: true
        model: listModel
        delegate: //nameDelegate
                  Text {
            text: name
            font.pixelSize: 30

        }

        footer: Rectangle {
            width: parent.width; height: 30;
        }
        highlight: Rectangle {
            width: parent.width
            color: "lightgray"
        }
    }

    Component {
        id: nameDelegate
        Text {
            text: name;
            font.pixelSize: 24
        }
    }
}
