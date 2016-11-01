
cmake_minimum_required(VERSION 2.8)
PROJECT(ReadDICOMSeriesQt)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED QUIET)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB UI_FILES *.ui)
file(GLOB QT_WRAP *.h)
file(GLOB CPP_FILES *.cxx)

qt5_wrap_ui(UISrcs ${UI_FILES})
# CMAKE_AUTOMOC in ON so the MOC headers will be automatically wrapped.
add_executable(ReadDICOMSeriesQt ${CPP_FILES} ${UISrcs} ${QT_WRAP})
qt5_use_modules(ReadDICOMSeriesQt Core Gui)
target_link_libraries(ReadDICOMSeriesQt ${VTK_LIBRARIES})
