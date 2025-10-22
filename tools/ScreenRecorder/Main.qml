import QtQuick
import QtQuick.Controls

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Screen Recording Application")

    /*!
      This property contains the current state of Recording.
      Is true if currently recording, otherwise false.
      False by default.
     */
    property bool isActive: false

    //--------------------------------------------------------------------------------------------------
    // Create some basic fill in the window and add a button for the screenshot tool
    //
    // A clock showing the current time is placed in the centre of the window just as an example,
    // but also as an example that can show constant change to help the user understand the process.
    //--------------------------------------------------------------------------------------------------

    // Create a background for the base window:
    Rectangle
    {
        id: background
        anchors.fill: parent
        color: "darkgray"
    }

    // Put the current time in the center screen as a component:
    property string timeString: Qt.formatTime(new Date(), "hh:mm:ss")
    Timer
    {
        id: timer
        interval: 1000
        running: true
        repeat: true
        onTriggered: timeString = Qt.formatTime(new Date(), "hh:mm:ss")
    }
    Text
    {
        id: timeDisplay
        text: timeString
        anchors.centerIn: parent
        font.pixelSize: 40
        font.bold: true
    }

    Button
    {
        id: stateButton
        width: parent.width / 4
        height: width / 2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
        text: isActive ? "<b>Stop</b>" : "<b>Start</b>"
        font.pixelSize: 24

        background: Rectangle
        {
            // Toggle the color of our button for friendliness
            color: isActive ? "red" : "green"
            radius: 10
        }

        onClicked:
        {
            // Toggle the state of recording
            isActive = !isActive
        }
    }
}
