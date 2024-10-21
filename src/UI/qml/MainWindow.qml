import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Convolution Tool"

    GridLayout {
        columns: 2
        spacing: 10

        // Left side: Upload and view photo
        Image {
            id: photo
            source: "image.jpg"  // Placeholder source
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
                applyConvolution(photo.source, outputPhoto.source);
            }
        }
    }
}
