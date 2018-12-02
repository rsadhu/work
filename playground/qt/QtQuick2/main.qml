import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import NetworkMngr.qml 1.0
Window {
    id: root
    visible: true
    minimumWidth : 300
    minimumHeight: 300
    maximumWidth : 300
    maximumHeight: 300

    title: qsTr("Hello World")

    AnimatedImage {
        anchors.fill: parent
        source:"file:///home/rsadhu/Desktop/giphy.gif"
    }

    NetworkMngr {
        id: nmngr;
        onResponseArrived: {
            console.log("respone :: ===>> "+response)
        }

        onResultArrived: {
            console.log("result :: ===>> ")//+result)
        }
    }

    //    ListModel {
    //        id:myModel
    //        ListElement{
    //            name: "rakesh"
    //            //            age: 37
    //            //            address: "Kashmir"
    //        }

    //        ListElement {
    //            name: "Ashwani"
    //            //            age: 41
    //            //            address: "Kashmir"
    //        }
    //    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("Mouse Clicked")
            try {
                //   myModel.append({name:"new" ,age: 1, address:"Turkey"})
                nmngr.connectToHost("http://google.com",999)
                console.log("network adaptors : ===>>    "+nmngr.testD.name)
                mngr.testD.name =  "maharaza ho"
                root.delta++
            }catch(e) {
                console.log(e.toString())
            }
        }
    }

    //    Component
    //    {
    //        id: viewData
    //        Text {
    //            color: "red"
    //            text: name +" "// + age + "  " +  address
    //            font.pixelSize: 24
    //        }
    //    }

    //    ListView {
    //        id: listView
    //        anchors.fill: parent
    //        clip: true
    //        model:myModel
    //        delegate:viewData
    //    }
}
