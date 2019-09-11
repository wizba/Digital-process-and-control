import QtQuick 2.0
import QtQuick 2.6

Rectangle
{
    width:50
    height:50

    color:"red"

    signal clicked

    MouseArea
      {
          anchors.fill: parent
          onClicked:
          {
              root.clicked()

          }
      }
}
