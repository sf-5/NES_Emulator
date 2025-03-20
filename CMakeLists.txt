cmake_minimum_required(VERSION 3.15)
project(NES_Emulator)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(main main.cpp Bus.cpp Bus.h CPU.cpp CPU.h)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json) 