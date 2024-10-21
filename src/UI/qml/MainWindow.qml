import QtQuick 6.5
import QtQuick.Controls 6.5
import QtQuick.Layouts 6.5

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Convolution Tool"

    GridLayout {
        columns: 2

        // Left side: Upload and view photo
        Image {
            id: photo
            source: "Assets/cat.png" 
            fillMode: Image.PreserveAspectFit
        }

        // Right side: Convolution output
        Image {
            id: outputPhoto
            fillMode: Image.PreserveAspectFit
        }

        // Dropdown and custom convolution input
        ComboBox {
            id: convolutionDropdown
            model: ["Blur", "Sharpen", "Custom"]
        }

        TextField {
            id: customConvolution
            visible: convolutionDropdown.currentIndex === 2
            placeholderText: "Enter custom convolution matrix"
        }

        // Apply button
        Button {
            text: "Apply"
            onClicked: {
                // Call the C++ backend to apply the convolution
                // Exposed method from C++ backend
                // applyConvolution(photo.source, outputPhoto.source);
            }
        }
    }
}
