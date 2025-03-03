# Calculator Test Task  

A simple Qt-based calculator application using **QML** for the UI and **C++** for the backend logic.  
This project also includes a **hidden "Secret Menu"** that can be accessed through a specific key sequence.  

## **Features**  
- Basic arithmetic operations (`+`, `-`, `×`, `/`, `%`)  
- Special functions (`+/-`, `C` for clearing, decimal point support)  
- **Secret Menu Activation** via a hidden combination  

## **Secret Menu Activation**  
To unlock the **Secret Menu**, follow these steps:  
1. **Press and hold** the `=` button for **4 seconds**.  
2. After releasing it, enter the sequence **"123"** within **5 seconds**.  
3. The **Secret Menu** will be displayed.  

## **Installation & Setup**  
### **Prerequisites**  
- **Qt 6+** (with QtQuick & QtQuick.Controls modules)  
- **CMake 3.16+**  
- **C++17+**  

### **Build Instructions**  

# Clone the repository
git clone --recurse-submodules http://github.com/max7im-prog/calculator-test-task.git 

cd calculator-test-task

# Create a build directory
mkdir build && cd build  

# Run CMake
cmake ..  

# Build the project
make  

# Run the application
./appcalculator-test-task  
