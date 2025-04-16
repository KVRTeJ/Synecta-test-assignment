import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

ApplicationWindow {
    visible: true
    width: 800; height: 600
    title: "Touchstone Parser"

    Rectangle {
        id: mainRect
        width: parent.width - 10; height: parent.height - 10
        color: "#bdc3c7"
        anchors.centerIn: parent
        Button {
            id: loadButton
            width: (parent.width - 20); height: (parent.height * 0.1)
            y: parent.height - height - 10
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: fileDialog.open()

            Text {
                id: loadButtonText
                text: "Select file"
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
                font.bold: true
            }
        }

        FileDialog {
            id: fileDialog
            title: "Select File"
            folder: shortcuts.home
            onAccepted: {
                urlCatcher.getFileUrl(fileDialog.fileUrls[0])
            }
        }
    }
}
