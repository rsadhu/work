import QtQuick 2.0

Item {
    Column {
        Repeater {
            model: 3

            Row {
                Repeater {
                    model: 3
                    Rectangle {
                        width: 10//parent.width/3
                        height : 10//parent.height/3
                    }
                }
            }
        }
    }
}
