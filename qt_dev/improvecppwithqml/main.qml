import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Image {
        id: ball
        source: "file:///home/rsadhu/Pictures/test.gif"

       MouseArea{
           anchors.fill:ball
           onDragChanged: {
               ball.mo
           }
       }
    }

}
