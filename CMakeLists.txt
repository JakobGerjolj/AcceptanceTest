cmake_minimum_required(VERSION 3.5)

project(AcceptanceTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test SerialPort SerialBus)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test SerialPort SerialBus)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AcceptanceTest tst_acceptancetest.cpp)
add_test(NAME AcceptanceTest COMMAND AcceptanceTest)

# Link against QtTest, QtSerialPort, and QtSerialBus
target_link_libraries(AcceptanceTest PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::SerialPort Qt${QT_VERSION_MAJOR}::SerialBus)

# Link against your custom library
target_link_libraries(AcceptanceTest PRIVATE /home/jakob/build-test-bench-library-Desktop_Qt_6_5_3_GCC_64bit-Debug/libtest-bench-library.so)
