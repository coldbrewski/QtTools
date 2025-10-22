cmake_minimum_required(VERSION 3.28)

project(Screenshot VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Quick
    Widgets
)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appScreenshot
    main.cpp
)

qt_add_qml_module(appScreenshot
    URI Screenshot
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES screenshotclass.h screenshotclass.cpp
)

target_link_libraries(appScreenshot PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Widgets
)

add_subdirectory(Info)

include(GNUInstallDirs)
install(TARGETS appScreenshot
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
