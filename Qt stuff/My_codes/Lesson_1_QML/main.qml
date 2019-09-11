import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

Window
{
    visible: true
    width: 640
    height: 480
    title: qsTr("My first Gui")

 Label
    {
        id:myLabel
        width: 18
        height: 18
        text:"myLabe"
        font.pixelSize: 22
        font.italic: true
        color: "steelblue"

    }
 TextField {
     width:18
     style: TextFieldStyle {
         background: Rectangle {



        width: 20
        color: "#f0f0f0"
        antialiasing: true
        border.color: "gray"
        radius: height/2
           Rectangle {
                       anchors.fill: parent
                        anchors.margins: 1
                       color: "transparent"
                       antialiasing: true
                       border.color: "#aaffffff"
                       radius: height/2
                         }

         }
     }

 }







}
