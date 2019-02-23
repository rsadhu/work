import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import NetworkMngr.qml 1.0
import EmployeeCard 1.0
import TestPlugin 1.0

Window {
    id: root
    visible: true

    minimumWidth : 300
    maximumWidth : 300

    minimumHeight: 200
    maximumHeight: 300
    property TestPlugin tpData ; TestPlugin { }
    TestPlugin {
        id: thisPlugin
        onThisPropertyChanged: {
            console.log("<<<< this propertyChanged >> +"+thisProperty)
        }
        onObjectPropertyChanged: {
            console.log("<<<< object property changed >>>> " + ObjectProperty);
        }
    }




    MyModel {
      //  anchors.fill:  root
        visible: true
    }


    EmployeeCard {
        id: ic
        onENameChanged: {
            console.log("--------- >>  ename  "+eName)
        }

        onNameChanged: {
            console.log("====>>>>   name   "+name)
        }

        onAddrChanged: {
            console.log("add  changed>>>  "+addr)
        }

        onEAddrChanged: {
            console.log("add  Emp changed>>>  "+eAddr)
        }

        onFireHandler: {
            console.log("================= >>>>  "+data)
        }
    }

    Connections {
        target: ic
        onFireHandler: {
            console.log("-CONNECTIONS ->>>>>>>>>>>>>>>>> "+data)
        }
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

            var date = new Date;
            thisPlugin.thisProperty =  10;
            thisPlugin.ObjectProperty = date;

            //foreach(var  i in thisPlugin.list)
          //  {
                console.log("list >>>>>>>   "+thisPlugin.listIntegers);



                  TestPlugin.listIntegers =  [10 , 11, 12, 13, 14, 15]
//                TestPlugin.listIntegers[0] = 7
//                TestPlugin.listIntegers[1] = 8
//                TestPlugin.listIntegers[2] = 9
//                TestPlugin.listIntegers[3] = 10
//                TestPlugin.listIntegers[4] = 11
//                TestPlugin.listIntegers[5] = 12

                console.log("list >>>>>>>   "+thisPlugin.listIntegers);
           // }

            try {
                //   myModel.append({name:"new" ,age: 1, address:"Turkey"})
                nmngr.connectToHost("http://google.com",999)
                console.log("network adaptors : ===>>    "+nmngr.testD.name)
                mngr.testD.name =  "maharaza ho"
                root.delta++
                ic.fireCall();
                ic.eAddr = "Turkey"
                ic.eName = "Rakesh";

                listModel.name[0]= "DiscoDance"
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


