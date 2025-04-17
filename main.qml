import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import QtCharts 2.3
import App 1.0

ApplicationWindow {
    visible: true
    width: 800; height: 600
    title: "Touchstone Parser"

    Rectangle {
        id: mainRect
        width: parent.width - 10; height: parent.height - 10
        color: "#bdc3c7"
        anchors.centerIn: parent
        radius: 5
        Rectangle {
            id: chartViewRect
            width: (parent.width - 10); height: (parent.height - 20 - loadButton.height)
            color: "#34495e"
            y: 10
            anchors.horizontalCenter: parent.horizontalCenter
            radius: 5
            ChartView {
                id: mainGraph
                anchors.fill: parent
                theme: ChartView.ChartThemeBrownSand
                antialiasing: true

                ValueAxis {
                    id: axisX
                    min: graphDataUiHandler.minX
                    max: graphDataUiHandler.maxX
                }
                ValueAxis {
                    id: axisY
                    min: graphDataUiHandler.minY
                    max: graphDataUiHandler.maxY
                }

                LineSeries {
                    id: lineSeries
                    objectName: "lineSeries"
                    axisX: axisX
                    axisY: axisY
                    name: "Data"
                }

                Component.onCompleted: {
                    graphDataUiHandler.setSeries(lineSeries);
                }
            }
        }

        Button {
            id: loadButton
            width: (parent.width - 10); height: (parent.height * 0.1)
            y: parent.height - height - 10
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: fileDialog.open()
            Text {
                id: loadButtonText
                text: "Select file"
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
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

        GraphDataUiHandler {
            id: graphDataUiHandler
            objectName: "graphDataUiHandler"

        }
    }
}
