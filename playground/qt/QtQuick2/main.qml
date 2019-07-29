import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import NetworkMngr.qml 1.0
import EmployeeCard 1.0
import TestPlugin 1.0
import AccessType 1.0

Window {
    id: root
    visible: true
    width: 300
    height: 200
    title: qsTr("Hello World")

    ListModel {

        id:mymodel

        ListElement {
            name : "Rakesh";
            age: 37
            address: "MUC, DE"
            hometown: "Kmr, India"
        }

        ListElement {
            name : "Ashwani";
            age: 41
            address: "Zpur, India"
            hometown: "Kmr, India"
        }

        ListElement {
            name : "Jotika";
            age: 44
            address: "Jmu, India"
            hometown: "Kmr, India"
        }

        ListElement {
            name : "JLS";
            age: 69
            address: "Kmr, India"
            hometown: "Kmr, India"
        }
    }

    Component {

        id: mydelegate

        Row {

            Text {
                text: name
            }

            Text {
                text: age
            }

            Text {
                text: address
            }

            Text {
                text: hometown
            }
        }
    }

    ListView {
        id:view
        height: root.height*0.9
        model: mymodel
        delegate: mydelegate
    }

    Button {
        id: btn
        text: "Ok"
        onClicked: {
            for(var i = 0;i<4;i++) {
                console.log("===>"+mymodel.data(mymodel.index(i,0),0))
                console.log("===>"+mymodel.data(mymodel.index(i,0),1))
                console.log("===>"+mymodel.data(mymodel.index(i,0),2))
                console.log("===>"+mymodel.data(mymodel.index(i,0),3))
            }
        }
    }
}


