project(QtChartTestPackage)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
find_package(Qt5Core) 
find_package(Qt5Widgets)

add_executable(qtcharttest main.cpp)
target_link_libraries(qtcharttest ${CONAN_LIBS} Qt5::Core Qt5::Widgets )
