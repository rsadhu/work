import QtQuick 2.4

Item
{
    //property  var _colors :  [ "red", "blue" , "cyan" , "black", "pink" , "yellow"]
    //property int cnt: 0
    // property bool enableIt:false
    // property var obj : null

    //    MouseArea {
    //        anchors.fill : parent
    //        onClicked: {
    //            console.log("===========>> clicked"+root.cnt++)
    //            //enableIt =  true;
    //            //_loader.item.color = (root._colors[root.cnt++%_colors.length])

    //            createObject();

    //            if( obj !==  null) {
    //                var o = obj.createObject(root);
    //                o.color = "red"
    //                o.width = root.width
    //                o.height =  root.height
    //                //o.anchors.centerIn = root
    //                console.log("text is >>> "+ obj.url)
    //            }
    //        }
    //    }

    //    Component {
    //        id: _reusableComponent
    //        Rectangle {
    //            id: _myRect
    //            width :root.width
    //            height: root.height
    //        }
    //    }

    //    Repeater {

    //    }

    //    Loader {
    //        id: _loader
    //        sourceComponent: _reusableComponent
    //        asynchronous: false
    //        active:  enableIt

    //        onActiveChanged:  {


    //        }
    //    }


    //    Rectangle {
    //        width: root.width
    //        height: root.height
    //        MyKeyBoard {
    //            anchors.fill :parent
    //        }
    //    }

    //    Row {

    //        Repeater {
    //            model: 3



    Rectangle {



        //                border.color: "blue"
        //              border.width: 3
        //        color: "red"
        //        width : root.width/3
        //        height : root.height/3

        Column {
            id: _c

            property var _clr : "grey"
            Repeater {
                model : 3

                Row {
                    Rectangle{
                        id: rect1

                        border.width: 3
                        border.color: _c._clr

                        color: "blue"
                        x: 0
                        y: 120
                        width: 50
                        height: 50
                        MouseArea {
                            anchors.fill: rect1

                            onPressed: {
                                rect1.color = "red"
                            }

                            onReleased: {
                                rect1.color = "blue"
                            }

                        }
                    }

                    Rectangle{
                        id: rect2
                        border.width: 3
                        border.color: _c._clr
                        color: "yellow"
                        x: 120
                        y: 120
                        width: 50
                        height: 50
                        MouseArea {
                            anchors.fill: rect2

                            onPressed: {
                                rect2.color = "red"
                            }

                            onReleased: {
                                rect2.color = "yellow"
                            }

                        }
                    }

                    Rectangle{
                        id: rect3
                        border.width: 3
                        border.color: _c._clr
                        color: "green"
                        x: 240
                        y: 120
                        width: 50
                        height: 50
                        MouseArea {
                            anchors.fill: rect3

                            onPressed: {
                                rect3.color = "red"
                            }

                            onReleased: {
                                rect3.color = "green"
                            }

                        }
                    }
                }
            }
        }


        Component.onCompleted: {

            //                    var a =  Qt.createComponent("item.qml");
            //                    if(a.status === Component.Ready)
            //                    {
            //                        a.createObject(root);
            //                    }
        }
        //        }
        //  }
    }




    function createObject() {

        if(obj){
            console.log("object already created "+obj);
            return;
        }

        obj = Qt.createComponent("item.qml");

        if(obj.status === Component.Ready) {
            console.log("ready component")
        }
        else if(obj.status === Component.Error) {
            console.log("Error===>>  ")
        }
        else {
            console.log("not ready ")
        }
    }
}
