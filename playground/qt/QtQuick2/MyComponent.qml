import QtQuick 2.0

Item {
    id: testImg
    Image {
        id: img

        height: parent.height /0.67
        width: parent.width
        source:"file:///home//rsadhu//Desktop//mummy_passport1.jpeg"
        ParallelAnimation {
            running: true
        }
    }

    Rectangle {
        color: "red"

    }

    ListModel {
        id: _model
        ListElement {
            uid: 1
            name: "Rakesh"
            addr:"MUC, DE"
        }

        ListElement {
            uid: 2
            name: "Ashwani"
            addr: "Zpur, IN"
        }
    }

    ListView {
        model: _model
        delegate:  Rectangle {
            width: root.width
            height: root.width
            Text {
                width: parent.width/2;
                height: parent.height/2
                text : uid + "." + name + "-" +addr
            }
        }

        onModelChanged: {
            console.log("<<<<<<<<<<<<<<<<<<<===>>>>>>>>>>>>>>>>")
        }
    }

}
