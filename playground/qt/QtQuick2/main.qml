import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 300
    height: 300
    title: qsTr("Hello World")

    ListModel {
        id:myModel
        ListElement{
            name: "rakesh"
            //            age: 37
            //            address: "Kashmir"
        }

        ListElement {
            name: "Ashwani"
            //            age: 41
            //            address: "Kashmir"
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("Mouse Clicked")
            try {
                myModel.append({name:"new" ,age: 1, address:"Turkey"})
            }catch(e) {
                console.log(e.toString())
            }
        }
    }

    Component
    {
        id: viewData
        Text {
            color: "red"
            text: name +" "// + age + "  " +  address
            font.pixelSize: 24
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        clip: true
        model:myModel
        delegate:viewData
    }
}
