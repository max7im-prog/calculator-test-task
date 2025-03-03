import QtQuick
import QtQuick.Controls

Page {
    id: secretMenuPage
    title: "Secret Menu"
    

    Column {
        anchors.fill: parent
        spacing: 20

        Rectangle {
            color: theme_1_1
            width: parent.width
            height: parent.height / 4

            Text {
                text: "Secret Menu"
                font.pixelSize: 24
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.centerIn: parent
                color: theme_1_6
            }
        }

        Rectangle{
            color:theme_1_2
            width:parent.width
            height:parent.height*3/4
            Button {
                text: "Back"
                onClicked: stackView.pop()  // Navigate back to calculator
                width:parent.width
                background: Rectangle{
                    color:theme_1_5
                }

            }
        }
    }
    
}
