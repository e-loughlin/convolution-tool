import QtQuick 6.5
import QtQuick.Controls 6.5
import QtQuick.Layouts 6.5

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Convolution Tool"

    // Background color for the application
    color: "#f0f0f0"

    // Title at the top left
    Text {
        text: "Convolution Tool"
        font.pointSize: 24
        font.bold: true
        color: "#333333" // Dark gray color for the title
        horizontalAlignment: Text.AlignHCenter
        Layout.columnSpan: 2 // Span across two columns
        Layout.alignment: Qt.AlignLeft // Align left
        padding: 10 // Add some padding around the text
    }

    GridLayout {
        anchors.fill: parent
        rowSpacing: 20
        columnSpacing: 20


        // Left side: Upload and view photo
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Image {
                id: photo
                source: "Assets/cat.png"
                fillMode: Image.PreserveAspectFit
                width: parent.width // Fill the width of the container
                height: parent.height * 0.8 // 80% of the height
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
            }
        }

        // Right side: Convolution output
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Image {
                id: outputPhoto
                fillMode: Image.PreserveAspectFit
                width: parent.width // Fill the width of the container
                height: parent.height * 0.8 // 80% of the height
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
            }
        }

        // Dropdown and custom convolution input
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ComboBox {
                id: convolutionDropdown
                model: ["Blur", "Sharpen", "Custom"]
                width: parent.width
                padding: 10
                // Additional styling can be done here
            }

            TextField {
                id: customConvolution
                visible: convolutionDropdown.currentIndex === 2
                placeholderText: "Enter custom convolution matrix"
                width: parent.width
                padding: 10
                // Additional styling can be done here
            }

            // Apply button
            Button {
                text: "Apply"
                width: parent.width
                padding: 10
                onClicked: {
                    // Call the C++ backend to apply the convolution
                    // Exposed method from C++ backend
                    // applyConvolution(photo.source, outputPhoto.source);
                }
            }
        }
    }
}
