import QtQuick 2.6
import QtQuick.Window 2.2
//import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
//import QtQuick.Particles 2.0

Window
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Slider
    {
        id: slider1

        value: 0.5
        width: parent.width/5
        style: sliderStyle
    }

   Button
   {
       id: button1


       width: parent.width/5

       x:200
       y:200
       style: buttonStyle_1
       text:"myButton"
       enabled:true
   }

    Component
    {

            id: sliderStyle
            SliderStyle
            {
                handle: Rectangle
                {
                    width: 18
                    height: 18
                    color: control.pressed ? "darkGray" : "deepSkyblue"
                    border.color: "gray"
                   //? antialiasing: true
                    radius: height/2

                        Rectangle
                        {
                            anchors.fill: parent
                            anchors.margins: 1
                            color: "transparent"
                            //antialiasing: true
                            border.color: "#eee"
                           radius: height/2
                        }
                }

                groove: Rectangle
                {
                    height: 8


                    antialiasing: true
                    color: "pink"
                    border.color: "#777"
                    radius: 0

                            Rectangle
                            {
                                anchors.fill: parent
                                anchors.margins: 1
                               // color: "yellow"
                               // antialiasing: true
                                border.color: "green"
                                radius: height/2
                            }
                }
            }

    }

    Component
    {
        id:buttonStyle_1

        ButtonStyle
        {
            background: Rectangle
            {
                implicitHeight: 22
                implicitWidth: window.width

                //if button pressed change to aqua
                color: control.pressed ? "aqua" : control.activeFocus ? "green" : "darkblue"

            }

        }


    }
}
