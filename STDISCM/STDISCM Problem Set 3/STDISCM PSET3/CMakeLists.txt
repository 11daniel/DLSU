cmake_minimum_required(VERSION 3.16)

project(ocr_demo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    /usr/local/opt/leptonica/include
    /usr/local/opt/tesseract/include
)

link_directories(
    /usr/local/opt/leptonica/lib
    /usr/local/opt/tesseract/lib
)

add_executable(ocr_demo ocr_demo.cpp)

target_link_libraries(ocr_demo PRIVATE tesseract leptonica)
