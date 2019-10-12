import QtQuick 2.0

Item {

    property int i: 100
    property int j: 100
    property int k: 100

    signal messageSent(string msg)

    //    Rectangle {
    //        id: _rect
    //        color: "red"
    //        width : parent.width
    //        height : parent.height
    //        focus: true

    //        Keys.onPressed: {
    //            if(event.key === Qt.Key_F1){
    //                var a = Qt.createQmlObject("import QtQuick 2.0 ;Rectangle {z: 10; visible:true ; color:\"blue\"; anchors.fill:_rect; border.width:4;}", _rect, "");
    //            }
    //        }

    //        Keys.onSpacePressed: {
    //            console.log("space bar pressed ")
    //        }
    //    }


    Rectangle {
        id: root1
        width: 100; height: 100

        signal clicked(string value);
        color: "green"
        states: [
            State {
                name: "red_color"
                PropertyChanges { target: root1; color: "red" }
            },
            State {
                name: "blue_color"
                PropertyChanges { target: root1; color: "blue" }
            }
        ]


        MouseArea {
            id: _mArea
            anchors.fill: root1
            onClicked: {
                root1.clicked("true");
                root.messageSent("this is a message ")
            }
        }



        Connections {
            target: root1
            onClicked: {
                console.log("  >>>>>  MouseArea :: onClicked  >>>>>>  "+value)
            }
        }
    }


    function messageReceived(msg) {
        console.log(msg)
    }



    Component.onCompleted:  {
        root.messageSent.connect(messageReceived);
    }

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
