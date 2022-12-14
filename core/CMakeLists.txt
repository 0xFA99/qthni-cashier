cmake_minimum_required(VERSION 3.24)

project(qthni-executable VERSION 1.0
        DESCRIPTION "Executable for QtHNI Program"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        hni_components
        qtmaterial)

install(TARGETS ${PROJECT_NAME})