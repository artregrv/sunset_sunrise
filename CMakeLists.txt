cmake_minimum_required(VERSION 3.22)

project(sunset_sunrise)

set(Qt5_DIR "/home/artregrv/Qt/5.15.2/gcc_64/lib/cmake/Qt5")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Quick Sql REQUIRED)

file(GLOB SOURCES src/*)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    qml/resources.qrc
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Quick Qt5::Sql)
