cmake_minimum_required(VERSION 3.16)

project(calculator-test-task VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS 
Quick
Core
QuickControls2
Qml
)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appcalculator-test-task
    src/main.cpp
    src/calculator.h
    src/calculator.cpp
)

qt_add_qml_module(appcalculator-test-task
    URI calculatorTestTask
    VERSION 1.0
    QML_FILES
        src/Main.qml
    # SOURCES src/calculator.cpp src/ calculator.h
)

target_include_directories(appcalculator-test-task PRIVATE ${CMAKE_SOURCE_DIR}/src)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appcalculator-test-task PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appcalculator-test-task
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcalculator-test-task
    PRIVATE 
    Qt6::Quick
    Qt6::Core
    Qt6::QuickControls2
    Qt6::Qml
)

include(GNUInstallDirs)
install(TARGETS appcalculator-test-task
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
