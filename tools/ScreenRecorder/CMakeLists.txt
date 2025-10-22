cmake_minimum_required(VERSION 3.28)

project(ScreenRecorder
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Quick
)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appScreenRecorder
    main.cpp
)

qt_add_qml_module(appScreenRecorder
    URI ScreenRecorder
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES recorder.h recorder.cpp
)

target_link_libraries(appScreenRecorder PRIVATE
    Qt6::Quick
)
target_link_libraries(appScreenRecorder PRIVATE Qt6::Core)

add_subdirectory(info)

include(GNUInstallDirs)
install(TARGETS appScreenRecorder
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
