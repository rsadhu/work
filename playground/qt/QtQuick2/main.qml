
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml.Models 2.1
import QtQuick.XmlListModel 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12


import NetworkMngr.qml 1.0
import EmployeeCard 1.0
import TestPlugin 1.0
import AccessType 1.0

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

//        onTypeChanged: {
//     //       console.log("<<<<<<<<<<<<<< MyType Changed >>>>>> "+type)
//        }
    }

//    MyModel {
//      //  anchors.fill:  root
//        visible: true
//    }


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
    }   
        onClicked: {
            console.log("Mouse Clicked")

            var date = new Date;
            thisPlugin.thisProperty =  10;
            thisPlugin.ObjectProperty = date;
            AccessType.type = AccessType.STRING;
            console.log("<<<<<<<<<<< enum is >>>>>>>>>> "+AccessType.type.toString())


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

