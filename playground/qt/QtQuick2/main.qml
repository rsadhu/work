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
    id: root
    visible: true
    width: 300
    height: 200
    title: qsTr("Hello World")

    ObjectModel {

        id: myVisualModel


        Rectangle {
            color: "red"
            width: 100
            height: 50

            Text {
                anchors.centerIn: parent
                text :"1"
                color:"blue"
            }
        }

        Rectangle {
            color: "blue"
            width: 100
            height: 50

            Text {
                anchors.centerIn: parent
                text :"2"
                color:"red"
            }
        }

        Rectangle {

            color: "yellow"
            width: 100
            height: 50

            Text {
                anchors.centerIn: parent
                text :"3"
                color:"cyan"
            }
        }
    }

    ListView {
        id:view
        anchors.fill: parent
       // property string fruits: ["PineApple", "Avacado", "Mango", "WaterMelon"]
       // property int count: 0
       // model: myVisualModel
        /*model: ["Apple", "Orange", "Pear", "Grapes"]
        delegate: Text {
            text: modelData
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("=============onClicked=========="+modelData)
                    modelData = view.fruits[root.count]//++%root.fruit.length]
                }
            }
        }*/

        model: XmlListModel {
            id: feedModel
            source: "http://rss.news.yahoo.com/rss/oceania"
            query: "/rss/channel/item"
            XmlRole { name: "title"; query: "title/string()" }
            XmlRole { name: "link"; query: "link/string()" }
            XmlRole { name: "description"; query: "description/string()" }
       }

        delegate: Rectangle{
            Text {
                text : source  +"  "+query
            }
        }
    }
}


