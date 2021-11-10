import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.11
import multi.image.viewer 3.0


ApplicationWindow  {
    width: 640 * 2
    height: 480 * 2
    visible: true
    title: qsTr("Multi-Image Viewer")
    color: "red"

    MultiImageViewer{
        id: backend

    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 600
        height: 250
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
        Text {
            id: popText
            text: qsTr("press  Esc to close")
            x: parent.width/3
        }
        TextField {
            y: 25
            placeholderText: qsTr("Directory for windows A")
            width: parent.width
            onEditingFinished: backend.MenuNew = "0," + text
        }
        TextField {
            y: 75
            placeholderText: qsTr("Directory for windows B")
            width: parent.width
            onEditingFinished: backend.MenuNew = "1," + text
        }

        TextField {
            y: 125
            placeholderText: qsTr("Directory for windows B")
            width: parent.width
            onEditingFinished: backend.MenuNew = "2," + text
        }

        TextField {
            y: 175
            placeholderText: qsTr("Directory for windows B")
            width: parent.width
            onEditingFinished: backend.MenuNew = "3," + text
        }


    }

    menuBar: MenuBar {
            Menu {
                id: fileMenu
                title: qsTr("&File")
                Action {
                    text: qsTr("&New...")
                    onTriggered: popup.open()

                }
                Action {
                    text: qsTr("&Open...")
                    onTriggered: backend.MenuSave = "open"
                }
                Action {
                    text: qsTr("&Save")
                    onTriggered: backend.MenuSave = "save"
                }
                Action {
                    text: qsTr("Save &As...")
                    onTriggered: backend.MenuSave = "saveas"
                }
                MenuSeparator { }
                Action {
                    text: qsTr("&Quit")
                    onTriggered: backend.MenuSave = "quit"
                }
            }
            Menu {
                title: qsTr("&Edit")
                Action { text: qsTr("Cu&t") }
                Action { text: qsTr("&Copy") }
                Action { text: qsTr("&Paste") }
            }
            Menu {
                title: qsTr("&Help")
                Action { text: qsTr("&About") }
            }
        }



    Rectangle{
        id: top_left
        width: parent.width/2.1
        height: parent.height/2.1
        color: "blue"
        x: 0
        y: 25
        Image{
            width: parent.width
            height: parent.height
            source: backend.winAimgName
        }
        //---------- start of arrow animation  ------------
        //hover right/left to see navigation arrows
        property bool leftClicked: false
        property bool rightClicked: false
        Image{
            width: 100
            height: 100
            y:parent.height/2 - 50
            source: "resources/leftArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       top_left.leftClicked = true
                       backend.SideArrow = "0,0,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1
                   }
                   onExited: {
                       parent.opq = 0
                       backend.SideArrow = "0,0,0"

                   }
               }
        }

        Image{
            width: 100
            height: 100
            x: parent.width - 100
            y:parent.height/2 - 50
            source: "resources/rightArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       top_left.rightClicked = true
                       backend.SideArrow = "0,1,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1

                   }
                   onExited: {
                       parent.opq = 0
                       top_left.rightClicked = false
                       backend.SideArrow = "0,1,0"
                   }
               }
        }
        //---------- end of arrow animation  ------------


    }

    Rectangle{
        id: top_right
        width: parent.width/2.1
        height: parent.height/2.1
        color: "blue"
        x: parent.width - parent.width/2.1
        y: 25
        Image{
            width: parent.width
            height: parent.height
            source: backend.winBimgName
        }
        //---------- start of arrow animation  ------------
        //hover right/left to see navigation arrows
        property bool leftClicked: false
        property bool rightClicked: false
        Image{
            width: 100
            height: 100
            y:parent.height/2 - 50
            source: "resources/leftArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       top_right.leftClicked = true
                       backend.SideArrow = "1,0,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1
                   }
                   onExited: {
                       parent.opq = 0
                       top_right.leftClicked = false
                       backend.SideArrow = "1,0,0"
                   }
               }
        }

        Image{
            width: 100
            height: 100
            x: parent.width - 100
            y:parent.height/2 - 50
            source: "resources/rightArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       top_right.rightClicked = true
                       backend.SideArrow = "1,1,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1

                   }
                   onExited: {
                       parent.opq = 0
                       top_right.rightClicked = false
                       backend.SideArrow = "1,1,0"
                   }
               }
        }
        //---------- end of arrow animation  ------------
    }

    Rectangle{
        id: bottom_right
        width: parent.width/2.1
        height: parent.height/2.1
        color: "blue"
        x: parent.width - parent.width/2.1
        y: parent.height - parent.height/2.1
        Image{
            width: parent.width
            height: parent.height
            source: backend.winCimgName
        }

        //---------- start of arrow animation  ------------
        //hover right/left to see navigation arrows
        property bool leftClicked: false
        property bool rightClicked: false
        Image{
            width: 100
            height: 100
            y:parent.height/2 - 50
            source: "resources/leftArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       bottom_right.leftClicked = true
                       backend.SideArrow = "2,0,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1
                   }
                   onExited: {
                       parent.opq = 0
                       bottom_right.leftClicked = false
                       backend.SideArrow = "2,0,0"
                   }
               }
        }

        Image{
            width: 100
            height: 100
            x: parent.width - 100
            y:parent.height/2 - 50
            source: "resources/rightArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       bottom_right.rightClicked = true
                       backend.SideArrow = "2,1,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1

                   }
                   onExited: {
                       parent.opq = 0
                       bottom_right.rightClicked = false
                       backend.SideArrow = "2,1,0"
                   }
               }
        }
        //---------- end of arrow animation  ------------
    }

    Rectangle{
        id: bottom_left
        width: parent.width/2.1
        height: parent.height/2.1
        color: "blue"
        x: 0
        y: parent.height - parent.height/2.1

        Image{
            width: parent.width
            height: parent.height
            source: backend.winDimgName
        }
        //---------- start of arrow animation  ------------
        //hover right/left to see navigation arrows
        property bool leftClicked: false
        property bool rightClicked: false
        Image{
            width: 100
            height: 100
            y:parent.height/2 - 50
            source: "resources/leftArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       bottom_left.leftClicked = true
                       backend.SideArrow = "3,0,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1                       
                   }
                   onExited: {
                       parent.opq = 0
                       bottom_left.leftClicked = false
                       backend.SideArrow = "3,0,0"
                   }
               }
        }

        Image{
            width: 100
            height: 100
            x: parent.width - 100
            y:parent.height/2 - 50
            source: "resources/rightArrow.png"
            property int opq: 0
            opacity: opq
            MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       bottom_left.rightClicked = true
                       backend.SideArrow = "3,1,1"
                   }
                   hoverEnabled: true
                   onEntered: {
                       parent.opq = 1

                   }
                   onExited: {
                       parent.opq = 0
                       bottom_left.rightClicked = false
                       backend.SideArrow = "3,1,0"
                   }
               }
        }
        //---------- end of arrow animation  ------------

    }
    // image name dispaly

    TextField {
        y: 0
        text: {
            backend.winAimgName
        }


        width: parent.width/2.1
        background: Item {
            opacity: 0
        }

    }


    TextField {
        y: 0
        x: parent.width/1.9
        text: {
            backend.winBimgName
        }

        width: parent.width/2.1
        background: Item {
            opacity: 0
        }
    }
    TextField {
        y:  parent.height/2
        x: parent.width/1.9
        text: backend.winCimgName
        width: parent.width/2.1
        background: Item {
            opacity: 0
        }
    }
    TextField {
        y: parent.height/2
        text: backend.winDimgName
        width: parent.width/2.1
        background: Item {
            opacity: 0
        }
    }

    //---------- start of mid arrow animation  ------------
    Rectangle{
        width: parent.width/10
        height: parent.height/10
        anchors.centerIn: parent
        color: "transparent"
        property int opq: 0
        opacity: opq
        MouseArea {
               anchors.fill: parent
               hoverEnabled: true
               onEntered: {
                   parent.opq = 1
               }
               onExited: {
                   parent.opq = 0

               }
           }

        Image{
            width: 100
            height: 100
            x: parent.width - 75
            y:parent.height/2 - 50
            source: "resources/rightArrow.png"
            MouseArea {
                anchors.fill: parent
                onClicked:
                {
                    console.log("clicked right")
                    backend.SideArrow = "0,1,1"
                    backend.SideArrow = "1,1,1"
                    backend.SideArrow = "2,1,1"
                    backend.SideArrow = "3,1,1"
                }
            }
        }

        Image{
            width: 100
            height: 100
            x: -20
            y:parent.height/2 - 50
            source: "resources/leftArrow.png"
            MouseArea {
                anchors.fill: parent
                onClicked:
                {
                    console.log("clicked left")
                    backend.SideArrow = "0,0,1"
                    backend.SideArrow = "1,0,1"
                    backend.SideArrow = "2,0,1"
                    backend.SideArrow = "3,0,1"
                }
            }
        }

        //---------- end of mid arrow animation  ------------

    }



}
