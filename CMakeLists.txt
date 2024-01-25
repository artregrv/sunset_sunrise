cmake_minimum_required(VERSION 3.22)

project(qt_sql)

set(Qt5_DIR "/home/artregrv/Qt/5.15.2/gcc_64/lib/cmake/Qt5")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Quick Sql REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    database.h
    database.cpp
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Quick Qt5::Sql)
