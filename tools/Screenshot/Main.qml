import QtQuick
import QtQuick.Controls

import Utils 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //--------------------------------------------------------------------------------------------------
    // Create some basic fill in the window and add a button for the screenshot tool
    //
    // A clock showing the current time is placed in the centre of the window just as an example,
    // but also as an example that can show constant change to help the user understand the process.
    //--------------------------------------------------------------------------------------------------

    // Create an instance of our screen shot utility:
    ScreenshotUtil
    {
        id: screenshotUtil
    }

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

    // Create a button that completes the screenshot:
    Button
    {
        id: screenshotButton
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        text: "Take Screenshot"
        onClicked:
        {
            // Set the screenshot functionality here:
            screenshotUtil.takeScreenshot()
            // Show when the screenshot button is clicked
            console.log("Screenshot button clicked")
        }
    }
}
