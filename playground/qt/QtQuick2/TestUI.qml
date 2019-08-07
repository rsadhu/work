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
}
