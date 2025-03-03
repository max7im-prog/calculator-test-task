import QtQuick
import QtQuick.Controls
import calculatorTestTask

ApplicationWindow {
    id: mainWindow
    width: 300
    height: 500

    minimumWidth:width
    maximumWidth:width

    minimumHeight:height
    maximumHeight:height

    visible: true
    title: qsTr("calculator-test-task")
    color: theme_1_1

    property color theme_1_1: "#024873"  
    property color theme_1_2: "#0889A6"  
    property color theme_1_3: "#04BFAD"  
    property color theme_1_4: "#B0D1D8"  
    property color theme_1_5: "#F25E5E"  
    property color theme_1_6: "#FFFFFF"  
    property color theme_1_add_1: "#0Df79C"  
    property color theme_1_add_2: "#F7E425"  
    property color theme_1_3_30: "#04BFAD"  
    property color theme_1_1_30: "#024873"  
    property color theme_1_4_30: "#B0D1D8"  

    property string result: "Hello!"
    property string expression: "expression"




    Calculator{
        id: calculator 
        onResultChanged: (newResult) => {result = newResult}
        onExpressionChanged: (newExpression) => {expression = newExpression}
    }


    // Define the RoundButton component
    Component {
        id: roundButtonComponent
        RoundButton {
            width: parent.width/4-15
            height: width
            radius: width / 2

            font.family: "Open Sans"
            font.bold: true
            font.pixelSize: 24 
            
            text: "Button"
            background: Rectangle {
                color: "#FF5733"  // Button color
                radius: parent.width / 2
            }
        }
    }

    function createButton(parent, color, value) {
        var button = roundButtonComponent.createObject(parent)
        button.text = value;
        button.background.color = color;
        return button;
    }

    Column {
        spacing: 10
        width: parent.width
        height: parent.height
        
        // Place for output
        Rectangle {
            width: parent.width
            height: parent.height / 4
            color: theme_1_3
            radius: 10
            Text{
                id: expressionText
                anchors.top: parent.top
                anchors.right: parent.right
                padding:10
                text: expression  
            }
            Text{
                id: resultText
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                padding:10
                text: result   
            }
        }
        
        // Grid to hold buttons
        Rectangle {
        width: parent.width
        height: parent.height*3/4
        color: "transparent"
            Grid {
                width: parent.width
                height:parent.height
                columns: 4
                rows: 5
                spacing: 10
                padding:10
                
                // Row 5
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"=")
                        button.onClicked.connect(function() {
                            calculator.evaluate();  
                        });
                        
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,".")
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"0")
                        button.onClicked.connect(function() {
                            calculator.num(0);  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_5,"C")
                        button.onClicked.connect(function() {
                            calculator.clear();  
                        });
                    }
                }

                // Row 4
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"+")
                        button.onClicked.connect(function() {
                            calculator.sum();  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"3")
                        button.onClicked.connect(function() {
                            calculator.num(3);  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"2")
                        button.onClicked.connect(function() {
                            calculator.num(2);  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"1")
                        button.onClicked.connect(function() {
                            calculator.num(1);  
                        });
                    }
                }

                // Row 3
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"-")
                        button.onClicked.connect(function() {
                            calculator.sub();  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"6")
                        button.onClicked.connect(function() {
                            calculator.num(6);  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"5")
                        button.onClicked.connect(function() {
                            calculator.num(5);  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"4")
                        button.onClicked.connect(function() {
                            calculator.num(4);  
                        });
                    }
                }

                // Row 2
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"X")
                        button.onClicked.connect(function() {
                            calculator.mul();  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"9")
                        button.onClicked.connect(function() {
                            calculator.num(9);  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"8")
                        button.onClicked.connect(function() {
                            calculator.num(8);  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_6,"7")
                        button.onClicked.connect(function() {
                            calculator.num(7);  
                        });
                    }
                }

                // Row 1
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"/")
                        button.onClicked.connect(function() {
                            calculator.fraq();  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"%")
                        button.onClicked.connect(function() {
                            calculator.percent();  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"+/-")
                        button.onClicked.connect(function() {
                            calculator.plusMinus();  
                        });
                    }
                }
                Item{
                    Component.onCompleted:{
                        var button = createButton(parent,theme_1_4,"()")
                        button.onClicked.connect(function() {
                            calculator.brackets();  
                        });
                    }
                }

                

                
            }
        
        }
    }
}
